# Gravity Maze (Labirinto Gravitacional)
![Logo do Projeto](resources/logo.png)

## Sobre
Este projeto foi selecionado devido à busca por algo interativo, diferente, divertido e possível de ser realizado. Após pesquisar em diversos sites, encontramos o Gravity Maze, ou Labirinto Gravitacional, que atendeu a todos os nossos objetivos. Este jogo envolve um labirinto onde o jogador deve levar a esfera até o buraco certo, manipulando motores instalados na base com um controle de videogame, evitando obstáculos para alcançar o fim.

## Descrição
Iniciamos o projeto discutindo e pesquisando sobre como realizá-lo, quais componentes seriam necessários, orçamento e tempo de conclusão. Optamos por utilizar o microcontrolador ESP32, um controle conectado via Bluetooth, servomotores, uma tela LCD, sensor piezoelétrico, um botão, resistores de 220 ohms, alguns LEDs, um buzzer e uma fonte de alimentação de 6V e 3A. Organizamos nosso tempo com o Trello e elaboramos um cronograma, utilizando o Fritzing para o esquema elétrico e o Tinkercad para o modelo 3D da estrutura.

## Viabilidade e Proposta Inovadora
O jogo visa desenvolver habilidades lógicas, de coordenação e planejamento, podendo ser jogado por qualquer idade. Ele pode ser implementado em escolas, hospitais e para treinamentos, oferecendo benefícios cognitivos e motoras. O produto final foi avaliado em R$ 380,00, sendo um investimento aceitável para um dispositivo multifuncional.

## Vídeo de Desenvolvimento
Assista ao vídeo de desenvolvimento [aqui](https://youtu.be/dS7PiPDWwpY?si=ALZ4Q6fVcRGnhFJ2).

## Recursos
- [Prototipagem](resources/Prototipagem.png)
- [Esquema Elétrico](resources/Esquema_Eletrico.png)
- [Documentação](resources/Gravity_Maze.pdf)
- [Modelo 3D (.stl)](resources/Labirinto3D.stl)

## Instalação

### Configuração do Ambiente e IDE

1. **Instalação da IDE Arduino**:
   - Para carregar o código no microcontrolador ESP32, recomendamos o uso da [IDE Arduino](https://www.arduino.cc/en/software). Essa interface facilita a programação e o gerenciamento das bibliotecas necessárias para a execução do projeto.
   - Faça o download da versão compatível com seu sistema operacional e siga as instruções de instalação.

2. **Instalação das Bibliotecas Necessárias**:
   - **Bluepad32**: Usada para integrar o controle Bluetooth, permitindo o controle preciso dos motores. Para adicionar essa biblioteca, vá à IDE Arduino, navegue até `Sketch > Incluir Biblioteca > Gerenciar Bibliotecas`, pesquise por “Bluepad32” e instale a biblioteca.
   -  No campo **URLs Adicionais para Gerenciadores de Placas**, adicione o link da Bluepad32: `https://raw.githubusercontent.com/ricardoquesada/esp32-arduino-lib-builder/master/bluepad32_files/package_esp32_bluepad32_index.json`.
   - **LiquidCrystal_I2C**: Controla a tela LCD para exibir o temporizador e o estado do jogo. Procure pela biblioteca “LiquidCrystal_I2C” no gerenciador de bibliotecas e instale-a.
   - **ESP32Servo**: Controla os servomotores de forma eficiente, essencial para os movimentos suaves do labirinto. Esta biblioteca também está disponível no gerenciador de bibliotecas da IDE Arduino.
  
3. **Configuração da Placa ESP32**:
   - Na IDE Arduino, é necessário adicionar o suporte para placas ESP32. Para isso:
     1. Acesse `Arquivo > Preferências`.
     2. No campo **URLs Adicionais para Gerenciadores de Placas**, adicione o link: `https://dl.espressif.com/dl/package_esp32_index.json`.
     3. Em seguida, vá para `Ferramentas > Placa > Gerenciador de Placas`, pesquise por "ESP32" e instale o pacote correspondente.
     4. Após a instalação, selecione **ESP32 Dev Module** em `Ferramentas > Placa`.

4. **Configuração de Parâmetros da Placa**:
   - Configure os parâmetros da placa para garantir a comunicação correta:
     - **Porta**: Selecione a porta correta onde a placa ESP32 está conectada.
     - **Velocidade de Upload**: Recomendado 921600 baud.
     - **Flash Frequency**: 80MHz.
     - **Partition Scheme**: Default.

5. **Carregar o Código**:
   - Após configurar o ambiente e instalar as bibliotecas, conecte a ESP32 ao computador e carregue o código fornecido. Verifique se não há erros de compilação e, em caso de dúvidas, consulte a [Documentação da IDE Arduino](https://www.arduino.cc/reference/en/).

## Uso
1. Ligue o dispositivo.
2. Conecte o controle via Bluetooth.
3. Manipule os motores para guiar a bola pelo labirinto.

## Contatos
- engs-gabrielhul@camporeal.edu.br
- engs-alissonsilva@camporeal.edu.br
- engs-caioguarienti@camporeal.edu.br

## Contribuição
Para contribuir com este projeto, siga os passos abaixo:
1. Faça um fork do repositório.
2. Crie uma branch para suas modificações:
    ```bash
    git checkout -b minha-nova-feature
    ```
3. Commit suas mudanças:
    ```bash
    git commit -m 'Adicionar nova feature'
    ```
4. Envie suas alterações:
    ```bash
    git push origin minha-nova-feature
    ```
5. Abra um Pull Request.

## Referências
- DIYODE: [https://diyodemag.com/projects/arduino_uno_servo-operated_ball_maze_marble_mayhem](https://diyodemag.com/projects/arduino_uno_servo-operated_ball_maze_marble_mayhem)
- Documentação ESP32: ESPRESSIF [https://www.espressif.com/en](https://www.espressif.com/en)
- Bluepad32 para integração com controle Bluetooth: [Bluepad32 GitHub](https://github.com/ricardoquesada/bluepad32)
- Modelo 3D e simulação: Tinkercad [https://www.tinkercad.com](https://www.tinkercad.com)
- Software de esquemático: Fritzing [http://fritzing.org](http://fritzing.org)
- IDE Arduino: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
"""
