#include <Arduino.h>

// // Setting PWM properties
// const int freq = 30000;
// const int pwmChannel = 0;
// const int resolution = 8;
// int dutyCycle = 200;

uint8_t enableLeftMotor = D7;
uint8_t enableRightMotor = D8;

uint8_t input1LeftMotor = D0;
uint8_t input2LeftMotor = D1;
uint8_t input1RightMotor = D2;
uint8_t input2RightMotor = D3;

uint8_t leftSensor = D5;//middle
uint8_t rightSensor = D6;//middle
uint8_t leftLeftSensor = D4;
uint8_t rightRightSensor = D9;


void setup() {
  
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftLeftSensor, INPUT);
  pinMode(rightRightSensor, INPUT);

  pinMode(input1LeftMotor, OUTPUT);//motor1
  pinMode(input2LeftMotor, OUTPUT);//motor1
  pinMode(enableLeftMotor, OUTPUT);//enable1
  pinMode(input1RightMotor, OUTPUT);//motor2
  pinMode(input2RightMotor, OUTPUT);//motor2
  pinMode(enableRightMotor, OUTPUT);//en2

  analogWriteRange(100);
  analogWriteFreq(100);
  analogWrite(enableLeftMotor, 30);//enable
  analogWrite(enableRightMotor, 30);

//move forward
  digitalWrite(input1LeftMotor, 1); 
  digitalWrite(input2LeftMotor, 0);
  digitalWrite(input1RightMotor, 0);
  digitalWrite(input2RightMotor, 1);
}

void turnLeft(){
  digitalWrite(input1LeftMotor, 0);
  digitalWrite(input2LeftMotor, 0);
  digitalWrite(input1RightMotor, 0);
  digitalWrite(input2RightMotor, 1);
}

void turnRight(){
  digitalWrite(input1LeftMotor, 1);
  digitalWrite(input2LeftMotor, 0);
  digitalWrite(input1RightMotor, 0);
  digitalWrite(input2RightMotor, 0);
}

void goForward(){
  digitalWrite(input1LeftMotor, 1);
  digitalWrite(input2LeftMotor, 0);
  digitalWrite(input1RightMotor, 0);
  digitalWrite(input2RightMotor, 1);
}

void stop(){
  digitalWrite(input1LeftMotor, 0);
  digitalWrite(input2LeftMotor, 0);
  digitalWrite(input1RightMotor, 0);
  digitalWrite(input2RightMotor, 0);
}

void turnLeft90deg(){
  digitalWrite(input1LeftMotor, 0);
  digitalWrite(input2LeftMotor, 1);
  digitalWrite(input1RightMotor, 0);
  digitalWrite(input2RightMotor, 1);
}

void turnRight90deg(){
    digitalWrite(input1LeftMotor, 1);
  digitalWrite(input2LeftMotor, 0);
  digitalWrite(input1RightMotor, 1);
  digitalWrite(input2RightMotor, 0);
}

void loop() {
  
  // digitalRead(D5) == 0 ? Serial.println("black") : Serial.println("white");
    // delay(1000); 


  if(digitalRead(leftLeftSensor) == 1 && digitalRead(rightRightSensor) == 1){
    if(digitalRead(leftSensor) == 1 && digitalRead(rightSensor) == 1){
      goForward();
    }
    if(digitalRead(leftSensor) == 0 && digitalRead(rightSensor) == 1){
      turnLeft();
    }
    if(digitalRead(leftSensor) == 1 && digitalRead(rightSensor) == 0){
      turnRight();
    }
    if(digitalRead(leftSensor) == 0 && digitalRead(rightSensor) == 0){
      stop();
    }
  } else{//probably 90 degree turn
    if(digitalRead(leftLeftSensor) == 0 && digitalRead(leftSensor) == 0){//90 degree left turn
      while(digitalRead(leftLeftSensor) == 0){
        turnLeft90deg();
      }
    }
    if(digitalRead(rightRightSensor) == 0 && digitalRead(rightSensor) == 0){//90 degree right turn
      while(digitalRead(rightRightSensor) == 0){
        turnRight90deg();
      }
    }

  }



}