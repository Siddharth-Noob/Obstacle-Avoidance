#include<AFMotor.h>

const int trig = 12;
const int echo = 11;
AF_DCMotor motor1(4);
AF_DCMotor motor2(1);
int isObstaclePin = 7;

int duration = 0;
int distance = 0;
int isObstacle = LOW;

void setup()
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  motor1.setSpeed(120);
  motor2.setSpeed(120);

  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration / 2) / 28.5 ;
  delay(50);
  Serial.println(distance);
  isObstacle = digitalRead(isObstaclePin);
  if ( distance < 15 || isObstacle == HIGH  )
  {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }
  else
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }

}
