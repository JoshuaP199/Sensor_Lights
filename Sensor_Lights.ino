#include "SR04.h"

//Declare LEDs
#define GREEN 2
#define YELLOW 3
#define RED 4

//Declare sensor
#define TRIG_PIN 12
#define ECHO_PIN 11

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

void setup() {
  //Set up serial monitor
  Serial.begin(9600);

  //Set LEDs to outputs
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  //set LEDs to 0V(off)
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

void loop() {
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
  if (a < 10){ //if something is less than 10 cm away have Red turn on
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
  }
  else if (a < 20) { //if something is less than 20cm and more than 10 cm turn yellow on
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, LOW);
  }
  else { // if something is 20 or more cm have green turn on
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
  }
  delay(10);
}
