#include <Arduino.h>

// PARAMETROS
int MAX = 2971;// MAX 2971  0 % MOLHADO
int MIN = 1000;// MIN 1000 100% MOLHADO

//PINOS
#define SENSOR 35
#define RED 5
#define YELLOW 18
#define GREEN 19
#define LED_PIN 2


void setup() {
  Serial.begin(115200);
  pinMode(SENSOR, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int leitura = analogRead(SENSOR);
  int percentage = map(leitura, MIN, MAX, 100, 0);
  Serial.println(percentage);
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);
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
  delay(5*60*1000);
}

