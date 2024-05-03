#include <Arduino.h>

// PARAMETROS
int MAX = 2971;// MAX 2971  0 % MOLHADO
int MIN = 1000;// MIN 1000 100% MOLHADO

//PINOS
int SENSOR = 35;
int RED = 5; 
int YELLOW = 18; 
int GREEN = 19; 


void setup() {
  Serial.begin(115200);
  pinMode(SENSOR, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  int leitura = analogRead(SENSOR);
  int percentage = map(leitura, MIN, MAX, 100, 0);
  Serial.println(percentage);
  delay(1000);

  if (percentage < 60) {
    Serial.println("RED");
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
  } else if (percentage >= 70 && percentage < 80) {
    Serial.println("YELLOW");
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
  } else {
    Serial.println("GREEN");
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
  }

}

// Umidade base para irrigar 75%
// < 75% RED | > 75% < 85% YELLOW | > 85% GREEN

