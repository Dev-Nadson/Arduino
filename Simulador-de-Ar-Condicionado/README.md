
# Projeto Arduino: Controle de "Ar Condicionado" inteligente

## Descrição

Este projeto utiliza um Arduino Uno para monitorar se as portas estão fechadas, a temperatura do ambiente e o estado de um interruptor físico (toggle). Quando todas as condições predeterminadas são atendidas (objeto próximo -Porta fechada-, temperatura alta e interruptor ativado), o sistema exibe no display LCD "Ar Ligado"; caso contrário, exibe "Ar Desligado".

## Funcionalidades

* Medição de distância com sensor ultrassônico HC-SR04
* Leitura de temperatura com sensor LM35
* Interruptor físico para habilitar/desabilitar o sistema como uma chave geral
* Feedback visual em display LCD 16×2 via biblioteca Adafruit\_LiquidCrystal
* Evita flicker no LCD apenas atualizando quando o estado muda

## Componentes Necessários

* Arduino Uno (ou compatível)
* Sensor ultrassônico HC-SR04 (pinos TRIG e ECHO)
* Sensor de temperatura LM35
* Display LCD 16×2 compatível com Adafruit\_LiquidCrystal
* Interruptor tipo toggle (push button ou chave)
* Protoboard e jumpers

## Diagrama de Ligações

| Componente       | Pino Arduino                                                       | Função                     |
| ---------------- | ------------------------------------------------------------------ | -------------------------- |
| HC-SR04 TRIG     | D9                                                                 | Trigger do ultrassom       |
| HC-SR04 ECHO     | D10                                                                | Echo do ultrassom          |
| LM35             | A0                                                                 | Leitura analógica          |
| Toggle (pull‑up) | D11                                                                | Entrada digital com PULLUP |
| LCD (Adafruit)   | conforme biblioteca Adafruit\_LiquidCrystal (pino 0 como endereço) |                            |

> **Observação:** Ajuste o constructor `Adafruit_LiquidCrystal lcd_1(0);` caso seu módulo LCD utilize outro endereço.

## Configuração e Upload

1. Instale a biblioteca [Adafruit\_LiquidCrystal](https://github.com/adafruit/Adafruit_LiquidCrystal) na IDE do Arduino.
2. Abra o arquivo `Simulador_Ar_Condicionado.ino` na IDE.
3. Selecione a placa `Arduino Uno` e a porta correta em **Tools**.
4. Clique em **Upload**.

## Uso

1. Energize o sistema.
2. Ative o interruptor toggle para habilitar a detecção.
3. Aproxime um objeto a menos de 10 cm do sensor ultrassônico. (10 cm para fins de facilidade na simulação, numa situação real essa distancia seria menor que 1 cm)
4. Aumente a temperatura (ou simule valores altos) acima de 20 °C no LM35. (No código fonte, é usad-0 o valor de 70, já que é assim que o arduíno entende a temperatura, porém, no simulador ela equivale a 20 °C)
5. O display mudará para **Ar Ligado** quando todas as 3 condições forem verdadeiras. Caso contrário, mostrará **Ar Desligado**.

## Licença

Este projeto está sob a licença MIT. Sinta-se livre para adaptar e reutilizar o código.

Link para a página do projeto: [Simulador de Ar Condicionado](https://www.tinkercad.com/things/dolAu5RwqGz-simulador-de-ar-condicionado)