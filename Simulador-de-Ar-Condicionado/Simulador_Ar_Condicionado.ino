#include <Adafruit_LiquidCrystal.h> // Biblioteca para controlar o display LCD

const int trigPin = 9;  // Pino de disparo do sensor de distância
const int echoPin = 10; // Pino de recepção do sensor de distância
const int LM35 = A0;    // Pino analógico do temperatura LM35
int toggle = 11;        // Pino do interruptor
int temperatura;

Adafruit_LiquidCrystal lcd_1(0);

String estadoAtual = "";
String estadoAnterior = "";

void setup() {
  pinMode(toggle, INPUT_PULLUP); 
  pinMode(trigPin, OUTPUT);     
  pinMode(echoPin, INPUT);            

  Serial.begin(9600);           
  lcd_1.begin(16, 2);            
  lcd_1.print("Inicializando");  
  estadoAnterior = "false"; 
}

void loop() {

  temperatura = int((float(analogRead(LM35)) * 5 / 1024.0) / 0.01);
  Serial.println(temperatura);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  bool cond = (distance < 10 && temperatura > 70 && digitalRead(toggle) == LOW);

  if (cond) {
    estadoAtual = "true"; // Define o estado "ligado"    
  } else {
    estadoAtual = "false";// Define o estado "desligado"
  }

  // Atualiza o display apenas se o estado mudou evitando piscar
  if (estadoAtual != estadoAnterior) {
    lcd_1.clear();                           
    if (estadoAtual == "true") {
      lcd_1.setCursor(7, 0);
      lcd_1.print("Ar"); 
      lcd_1.setCursor(5, 1); // Firula pra usar as duas linhas do lcd
      lcd_1.print("Ligado");
    } else {
      lcd_1.setCursor(7, 0);  
      lcd_1.print("Ar");
      lcd_1.setCursor(3, 1);
      lcd_1.print("Desligado"); 
    }
    estadoAnterior = estadoAtual; // Atualiza o estado anterior
  }

  delay(200); // Pausa de 200 ms para evitar leituras muito rápidas
}
