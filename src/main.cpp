#include <Arduino.h>

// bool sensorLeft = 0;
// bool sensorRight = 0;

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

uint8_t leftSensor = D5;
uint8_t rightSensor = D6;


void setup() {

  // pinMode(D5, INPUT);
//to test
  /*
  pinMode(leftSensor, INPUT);
  pinMode(RightSensor, INPUT);


  pinMode(input1LeftMotor, OUTPUT);//motor1
  pinMode(input2LeftMotor, OUTPUT);//motor1
  pinMode(enableLeftMotor, OUTPUT);//enable1
  pinMode(input1RightMotor, OUTPUT);//motor2
  pinMode(input2RightMotor, OUTPUT);//motor2
  pinMode(enableRightMotor, OUTPUT);//en2

  digitalWrite(input1LeftMotor, 0);
  digitalWrite(input2LeftMotor, 1);
  digitalWrite(input1RightMotor, 1);
  digitalWrite(input2RightMotor, 0);
  */

  pinMode(D0, OUTPUT);//motor1
  pinMode(D1, OUTPUT);//motor1
  pinMode(D7, OUTPUT);//enable1
  pinMode(D2, OUTPUT);//motor2
  pinMode(D3, OUTPUT);//motor2
  pinMode(D8, OUTPUT);//en2

  analogWriteRange(100);
  analogWriteFreq(100);
  analogWrite(D7, 30);//enable
  analogWrite(D8, 30);

  //sensor1 = 0;
  //Serial.begin(9600);

  //go forward
  digitalWrite(D0, 0);
  digitalWrite(D1, 1);
  digitalWrite(D2, 1);
  digitalWrite(D3, 0);
}

// the loop function runs over and over again forever
void loop() {
  // digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // // but actually the LED is on; this is because
  // // it is active low on the ESP-01)
  // delay(1000);                      // Wait for a second
  // digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  // delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)


  // sensor1 =  digitalRead(D5);
  
  // sensor1 == 0 ? Serial.println("black") : Serial.println("white");
  
  // delay(1000); 

  if(digitalRead(leftSensor)==1 && digitalRead(rightSensor)==1){
    goForward();
  }
  if(digitalRead(leftSensor)==0 && digitalRead(rightSensor)==1){
    turnLeft();
  }
  if(digitalRead(leftSensor)==1 && digitalRead(rightSensor)==0){
    turnRight();
  }
  if(digitalRead(leftSensor)==0 && digitalRead(rightSensor)==0){
    turnLeft();
  }

}

void turnLeft(){
  digitalWrite(input1LeftMotor, 0);
  digitalWrite(input2LeftMotor, 0);
  digitalWrite(input1RightMotor, 1);
  digitalWrite(input2RightMotor, 0);
}

void turnRight(){
  digitalWrite(input1LeftMotor, 0);
  digitalWrite(input2LeftMotor, 1);
  digitalWrite(input1RightMotor, 0);
  digitalWrite(input2RightMotor, 0);
}

void goForward(){
  digitalWrite(input1LeftMotor, 0);
  digitalWrite(input2LeftMotor, 1);
  digitalWrite(input1RightMotor, 1);
  digitalWrite(input2RightMotor, 0);
}

void stop(){
  digitalWrite(input1LeftMotor, 0);
  digitalWrite(input2LeftMotor, 0);
  digitalWrite(input1RightMotor, 0);
  digitalWrite(input2RightMotor, 0);
}