#include <Bluepad32.h>
#include <ESP32Servo.h>
#include <ESP32PWM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definições de pinos e variáveis
const int sensor_pin = 13;  // Pino do sensor Piezoelétrico
int buttonPin = 5;         // Pino do botão para ativar o sistema
int motor_1_pin = 18;        // Pino do Motor 1 "x"
int motor_2_pin = 4;       // Pino do Motor 2 "y"
int led_green = 26;         // Led Verde
int led_red = 33;           // Led Vermelho
int buzzer = 32;            // Pino Buzzer
int buttonState = HIGH;     // Estado do botão
int lastButtonState = HIGH; // Último estado do botão
bool systemActive = false;  // Ativação do sitema
bool timerActive = false;   // Ativação do temporizador
bool motorsEnabled = false; // Ativação dos motores
// Variaveis para o controle do temporizador (milisegundos)
unsigned long startTime;               // Tempo de início
unsigned long currentTime;             // Tempo atual
unsigned long timerDuration = 120000;  // Duração, 2 minutos (em milissegundos)
unsigned long challengeCompletionTime; // Tempo decorrido até a conclusão

// Objetos para motores
Servo Motor_1;
Servo Motor_2;

// Objeto da tela LCD (I2C)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Array de controles conectados
ControllerPtr myControllers[BP32_MAX_GAMEPADS];

// Retorno de quando um controle é conectado
void onConnectedController(ControllerPtr ctl) {     // Percorre o array para identificar controles conectados
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {   // Se encontrar adiciona no array
        if (myControllers[i] == nullptr) {
            myControllers[i] = ctl;   
            break;
        }
    }
}

// Retorno de quando um controle é desconectado
void onDisconnectedController(ControllerPtr ctl) {   // Percorre o array para indentificar controles desconectados
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {    // Se encontrar removo do array
        if (myControllers[i] == ctl) {
            myControllers[i] = nullptr;
            break;
        }
    }
}

// Controle dos LEDs e do Buzzer
void controlLEDandBUZZER(int c){
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);
  digitalWrite(buzzer, LOW);
  if (c == 1){ // acende o led verde e toca o buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(led_red, LOW);
    digitalWrite(buzzer, HIGH); 
    delay(100);
    digitalWrite(buzzer, LOW);  
  }
  else if (c == 0){ // acende o led vermelho e toca o buzzer
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  }
  else if (c == 2){ // acende os dois leds e toca o buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(led_red, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  }
  else{ // destiva 
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(buzzer, LOW);
  }
}
// Processa e implementa os dados analógicos e digitais referentes a cada sistema do controle
void processGamepad(ControllerPtr ctl) {
    if (!ctl || !ctl->isConnected()) return;  // Verifica se o controle ainda está conectado
    int LStickX = ctl->axisX(); // Dados analógicos do eixo "X"
    int LStickY = ctl->axisY(); // Dados analógicos do eixo "Y"
    // Controle dos motores (usando os eixos analógicos)
    if (motorsEnabled) {
        // Condição para eliminar interferências, qaundo o eixo do controle está no centro
        if (abs(LStickX) < 15) {  // abs() Função utilizada para calcular o valor absoluto (sempre positivo)
            Motor_1.write(97);    // Mantem o eixo do motor centralizado
        } else {
            int map_Motor_1 = map(LStickX, -512, 512, 107, 86); // map() Função pra mapear valores analógicos para graus
            Motor_1.write(map_Motor_1); // Ativa movimento do motor
        }

        if (abs(LStickY) < 15) {
            Motor_2.write(97);
        } else {
            int map_Motor_2 = map(LStickY, -512, 512, 107, 86);
            Motor_2.write(map_Motor_2);
            //Serial.println(map_Motor_2);
        }
    }
}

// Verifica se os controles conectados tem novos dados, chama a função processGamepad()
void processControllers() {
    for (auto myController : myControllers) {
        if (myController && myController->isConnected() && myController->hasData()) {
            processGamepad(myController);
        }
    }
}

// Controla a vibração do controle se conectado
ControllerPtr getConnectedController() {
    for (auto ctl : myControllers) {
        if (ctl && ctl->isConnected()) {
            return ctl;
        }
    }
    return nullptr; // Retorna nullptr se nenhum controle estiver conectado
}

// COntrole do Timer e do LCD
void updateTimerAndLCD() {
         // Leitura do estado atual do botão (Play/Pause)
    buttonState = digitalRead(buttonPin);

    // Detectar se houve mudança de estado no botão (pressionado -> liberado)
    if (buttonState == LOW && lastButtonState == HIGH) {
        delay(100);  // Debouncing
        systemActive = !systemActive;

        if (systemActive && !timerActive) {   // Ativa valores boleanos para:
            controlLEDandBUZZER(1);
            startTime = millis();             // Função que retorna milisendos o tempo inicial
            timerActive = true;               // Iniciar o temporizador
            motorsEnabled = true;             // Desbloquear os motores               
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Timer: 2 min");
        } else {
            controlLEDandBUZZER(0);  
            timerActive = false;              // Pausa o sistema
            motorsEnabled = false;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tente Novamente!");
        }
    }

    // Armazenar o último estado do botão
    lastButtonState = buttonState;

    // Temporizador não bloqueante utilizando a função millis()
    if (timerActive) {   
        currentTime = millis();   // Função que retorna milisendos o tempo atual
        unsigned long elapsedTime = currentTime - startTime; // Tempo decorrido, a cada interação calcula a diferença entre o tempo de inicio e o atual
        unsigned long remainingTime = (timerDuration - elapsedTime) / 1000; // Tempo restante, calcula o tempo restante, subtraindo o tempo decorrido do total
        // Atualizar o display com o tempo restante
        lcd.setCursor(0, 1);
        lcd.print("Tempo: ");
        lcd.print(remainingTime / 60);  // Minutos
        lcd.print(":");
        lcd.print(remainingTime % 60);  // Segundos

        if (elapsedTime >= timerDuration) { // verifica se a diferença do tempo decorrido é maior que o tempo total
            controlLEDandBUZZER(0);
            timerActive = false;            // Pausa o sistema 
            motorsEnabled = false;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tempo esgotado!");
            // Obtém o controle conectado e executa a vibração, se disponível
            ControllerPtr ctl = getConnectedController();
            if (ctl) {
                ctl->playDualRumble(5, 1000, 0, 8);
            }
        }
    }

    // Leitura do sensor para concluir o desafio
    delay(10);
    int Read_sensor = analogRead(sensor_pin);
    
    if (Read_sensor > 20 && timerActive) { // Verifica se o sensor detectou sinal durante a ativação do temporizador
        Serial.println(Read_sensor);
        controlLEDandBUZZER(2);
        challengeCompletionTime = millis() - startTime; // Calcula o tempo decorrido com a diferença entre o tempo de inicio e o atual
        timerActive = false;           // Pausa o sitema
        motorsEnabled = false;         // Exibe o tempo no display
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Voce Venceu!!");
        lcd.setCursor(0, 1);
        lcd.print("Tempo: ");
        lcd.print(challengeCompletionTime / 60000);  // Minutos
        lcd.print(":");
        lcd.print((challengeCompletionTime / 1000) % 60);  // Segundos
        // Obtém o controle conectado e executa a vibração, se disponível
        ControllerPtr ctl = getConnectedController();
        if (ctl) {
            ctl->playDualRumble(5, 1000, 0, 8);
        }
    }
}

// Setup
void setup() { 
    Serial.begin(115200);
    BP32.setup(&onConnectedController, &onDisconnectedController); // Definições da biblioteca Bluepad32

    Motor_1.attach(motor_1_pin);  
    Motor_2.attach(motor_2_pin);
    lcd.init();
    lcd.backlight();
    pinMode(sensor_pin, INPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(led_green, OUTPUT);
    pinMode(led_red, OUTPUT);
    pinMode(buzzer, OUTPUT);

    Motor_1.write(97);
    Motor_2.write(97);
}

// Loop
void loop() {
      BP32.update();           // Atualiza o estado de todos os controles

      updateTimerAndLCD();     // Chama a função updateTimerAndLCD() precorrendo um loop
      processControllers();    // Chama a função processControllers() percorendo um loop
        
    delay(50); // Debouncing
}