//Ir remote control car
#include<Arduino.h>
#include<IRremote.h>

//change the button values based on ir remote used
#define BUTTON_2 17	//move forward
#define	BUTTON_4 20	//left turn
#define BUTTON_6 22	//right turn
#define BUTTON_8 25	//backword

//change the pin values according to your connection
#define IR_REC_PIN 2
#define LEFT_MOTOR_EN 5		//use pwm pin for speed control
#define RIGHT_MOTOR_EN 6	//use pwm pin for speed control
#define LEFT_MOTOR_IN1 7
#define LEFT_MOTOR_IN2 8
#define RIGHT_MOTOR_IN3 9
#define RIGHT_MOTOR_IN4 10

void move_forward();
void move_left();
void move_right();
void move_backward();
void stop();

unsigned long Received_command;
void setup()
{
  pinMode(IR_REC_PIN,INPUT);
  pinMode(LEFT_MOTOR_EN,OUTPUT);
  pinMode(LEFT_MOTOR_IN1,OUTPUT);
  pinMode(LEFT_MOTOR_IN2,OUTPUT);
  pinMode(RIGHT_MOTOR_EN,OUTPUT);
  pinMode(RIGHT_MOTOR_IN3,OUTPUT);
  pinMode(RIGHT_MOTOR_IN4,OUTPUT);
  IrReceiver.begin(IR_REC_PIN,ENABLE_LED_FEEDBACK);
}
void loop()
{
  if(IrReceiver.decode())
    Received_command = IrReceiver.decodedIRData.command;
  else
    Received_command = 0;
  if(Received_command == BUTTON_2)
    move_forward();
  else if(Received_command == BUTTON_4)
    move_left();
  else if(Received_command == BUTTON_6)
    move_right();
  else if(Received_command == BUTTON_8)
    move_backward();
  else
    stop();
  IrReceiver.resume();
}

void move_forward()
{
  digitalWrite(LEFT_MOTOR_EN,HIGH);
  digitalWrite(RIGHT_MOTOR_EN,HIGH);

  digitalWrite(LEFT_MOTOR_IN1,HIGH);
  digitalWrite(LEFT_MOTOR_IN2,LOW);

  digitalWrite(RIGHT_MOTOR_IN3,HIGH);
  digitalWrite(RIGHT_MOTOR_IN4,LOW);
}

void move_left()
{
  digitalWrite(LEFT_MOTOR_EN,HIGH);
  digitalWrite(RIGHT_MOTOR_EN,HIGH);

  digitalWrite(LEFT_MOTOR_IN1,HIGH);
  digitalWrite(LEFT_MOTOR_IN2,LOW);

  digitalWrite(RIGHT_MOTOR_IN3,LOW);
  digitalWrite(RIGHT_MOTOR_IN4,HIGH);
}

void move_right()
{
  digitalWrite(LEFT_MOTOR_EN,HIGH);
  digitalWrite(RIGHT_MOTOR_EN,HIGH);

  digitalWrite(LEFT_MOTOR_IN1,LOW);
  digitalWrite(LEFT_MOTOR_IN2,HIGH);

  digitalWrite(RIGHT_MOTOR_IN3,HIGH);
  digitalWrite(RIGHT_MOTOR_IN4,LOW);
}

void move_backward()
{
  digitalWrite(LEFT_MOTOR_EN,HIGH);
  digitalWrite(RIGHT_MOTOR_EN,HIGH);

  digitalWrite(LEFT_MOTOR_IN1,LOW);
  digitalWrite(LEFT_MOTOR_IN2,HIGH);

  digitalWrite(RIGHT_MOTOR_IN3,LOW);
  digitalWrite(RIGHT_MOTOR_IN4,HIGH);
}

void stop()
{
  digitalWrite(LEFT_MOTOR_EN,LOW);
  digitalWrite(RIGHT_MOTOR_EN,LOW);
}
