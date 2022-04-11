#include <SoftwareSerial.h>

int f1 = 7;
int f2 = 6;
int hasObstacle = HIGH;
void setup() {
  //Setup Channel A
  pinMode(11, OUTPUT); //Initiates Motor Channel A pin
  pinMode(10, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(9, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin

  Serial.begin(9600);  
}

void loop() {
  int left = analogRead(A2); 
  int right = analogRead(A5); 
  Serial.print(left);
  Serial.print(" ");
  Serial.print(right);
  Serial.println();
  if (left < 900){
    motor_left();
  } else {
    motor_leftOff();
  }
  if (right < 900){
    motor_right();
  } else {
    motor_rightOff();
  }
  delay(100);
}


void motor_left()
{
  digitalWrite(11, HIGH); //Establishes forward direction of Channel A
  digitalWrite(10, LOW);   //Disengage the Brake for Channel A
}

void motor_right()
{
  digitalWrite(8, HIGH); //Establishes forward direction of Channel B
  digitalWrite(9, LOW);   //Disengage the Brake for Channel B
}

void motor_leftOff()
{
  digitalWrite(11, LOW); //Establishes forward direction of Channel A
  digitalWrite(10, LOW);   //Disengage the Brake for Channel A
}

void motor_rightOff()
{
  digitalWrite(8, LOW); //Establishes forward direction of Channel B
  digitalWrite(9, LOW);   //Disengage the Brake for Channel B
}
