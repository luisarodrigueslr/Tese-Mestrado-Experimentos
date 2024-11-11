#include <ESP32Servo.h>

Servo miniServo; //definir objeto servo

void setup() {
  // Configurar os pinos dos botãos como entrada
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  miniServo.attach(9); //pino do servo
  miniServo.write(90); //posição inicial do servo
}

void loop() {
  // Lê o estado dos botões
  int button1State = digitalRead(2);
  int button2State = digitalRead(3);

  // Verifica qual botão é precionado e move para a posição pretendida
  // 3 posições 0º - admirado; 90º - normal; 180º - zangado
  if (button1State == HIGH) {
    miniServo.write(0); // Move para 0°
  } else if (button2State == HIGH) {
    miniServo.write(180); // Move para 180°
  } else {
    miniServo.write(90); // Move para 90°
  } 
  delay(50); //atraso de 50 milisegundos para debounce dos botões
}