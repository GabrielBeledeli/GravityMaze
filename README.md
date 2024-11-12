# Projeto: Gravity Maze (Labirinto Gravitacional)
![Logo do Projeto](path/to/logo.png)

## Justificativa
Este projeto foi selecionado devido à busca por algo interativo, diferente, divertido e possível de ser realizado. Após pesquisar em diversos sites, encontramos o Gravity Maze, ou Labirinto Gravitacional, que atendeu a todos os nossos objetivos. Este jogo envolve um labirinto onde o jogador deve levar a esfera até o buraco certo, manipulando motores instalados na base com um controle de videogame, evitando obstáculos para alcançar o fim.

## Descrição
Iniciamos o projeto discutindo e pesquisando sobre como realizá-lo, quais componentes seriam necessários, orçamento e tempo de conclusão. Optamos por utilizar o microcontrolador ESP 32, um controle conectado via Bluetooth, servomotores, uma tela LCD, sensor piezoelétrico, um botão, resistores de 220 ohms, alguns LEDs, um buzzer e uma fonte de alimentação de 6V e 3A. Organizamos nosso tempo com o Trello e elaboramos um cronograma, utilizando o Fritzing para o esquema elétrico e o Tinkercad para o modelo 3D da estrutura.

## Viabilidade e Proposta Inovadora
O jogo visa desenvolver habilidades lógicas, de coordenação e planejamento, podendo ser jogado por qualquer idade. Ele pode ser implementado em escolas, hospitais e para treinamentos, oferecendo benefícios cognitivos e motoras. O produto final foi avaliado em R$ 380,00, sendo um investimento aceitável para um dispositivo multifuncional.

## Vídeo de Desenvolvimento
Assista ao vídeo de desenvolvimento [aqui](https://youtu.be/dS7PiPDWwpY?si=ALZ4Q6fVcRGnhFJ2).

## Recursos
- [Prototipagem](resources/Prototipagem.png)
- [Esquema Elétrico](resources/Esquema Eletrico.png)
- [Documentação](resources/Gravity Maze.pdf)
- [Modelo 3D (.stl)](resources/Labirinto3D.stl)

## Instalação
1. Clone este repositório:
    ```bash
    git clone https://github.com/seu-usuario/nome-do-repositorio.git
    ```
2. Conecte os componentes conforme o esquema elétrico.
3. Carregue o código no microcontrolador ESP32 via Arduino IDE.

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
- Documentação ESP32: [https://docs.espressif.com](https://docs.espressif.com)
- Bluepad32 para integração com controle Bluetooth: [Bluepad32 GitHub](https://github.com/ricardoquesada/bluepad32)
- Modelo 3D e simulação: Tinkercad [https://www.tinkercad.com](https://www.tinkercad.com)
- Software de esquemático: Fritzing [http://fritzing.org](http://fritzing.org)

