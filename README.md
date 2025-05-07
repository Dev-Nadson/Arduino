
# Projetos Arduino
1. Controle de "Ar Condicionado" inteligente

## Descrição

Este projeto monitora se as portas estão fechadas, a temperatura e o interruptor físico. Quando todas as condições predeterminadas são atendidas, o sistema exibe no display LCD "Ar Ligado"; caso contrário, exibe "Ar Desligado".

## Diagrama de Ligações

| Componente       | Pino Arduino                                                       | Função                     |
| ---------------- | ------------------------------------------------------------------ | -------------------------- |
| HC-SR04 TRIG     | D9                                                                 | Trigger do ultrassom       |
| HC-SR04 ECHO     | D10                                                                | Echo do ultrassom          |
| LM35             | A0                                                                 | Leitura analógica          |
| Toggle (pull‑up) | D11                                                                | Entrada digital com PULLUP |
| LCD (Adafruit)   | conforme biblioteca Adafruit\_LiquidCrystal (pino 0 como endereço) |                            |

## Licença

Este projeto está sob a licença MIT. Sinta-se livre para adaptar e reutilizar o código.

Link para a página do projeto: [Simulador de Ar Condicionado](https://www.tinkercad.com/things/dolAu5RwqGz-simulador-de-ar-condicionado)