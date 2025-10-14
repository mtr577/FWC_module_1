//Human Following Robot
#include<Arduino.h>

//change the pin numbers according to your connetions
#define RIGHT_IR_PIN 2
#define LEFT_IR_PIN 3

#define TRIG_PIN 11
#define ECHO_PIN 12

#define LEFT_MOTOR_EN 6		//use pwm pin for speed control
#define RIGHT_MOTOR_EN 5	//use pwm pin for speed control
#define RIGHT_MOTOR_IN1 7
#define RIGHT_MOTOR_IN2 8
#define LEFT_MOTOR_IN3 9
#define LEFT_MOTOR_IN4 10

#define SAFE_DIST_LOW 5
#define SAFE_DIST_HIGH 10

void move_forward();
void move_left();
void move_right();
void move_backward();
void stop();

float duration, distance;
int left_ir_val, right_ir_val;

void setup()
{
	pinMode(RIGHT_IR_PIN,INPUT);
	pinMode(LEFT_IR_PIN,INPUT);
	pinMode(ECHO_PIN,INPUT);
	pinMode(TRIG_PIN,OUTPUT);
	pinMode(LEFT_MOTOR_EN,OUTPUT);
  	pinMode(LEFT_MOTOR_IN3,OUTPUT);
 	pinMode(LEFT_MOTOR_IN4,OUTPUT);
  	pinMode(RIGHT_MOTOR_EN,OUTPUT);
  	pinMode(RIGHT_MOTOR_IN1,OUTPUT);
 	pinMode(RIGHT_MOTOR_IN2,OUTPUT);
}

void loop()
{
	digitalWrite(TRIG_PIN,HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN,LOW);
	duration = pulseIn(ECHO_PIN,HIGH);	//gives microseconds
	distance = (duration/2)*0.034;		//343m/s=343*10^2cm/10^6microsecond=0.034cm/microseconds
	right_ir_val = digitalRead(RIGHT_IR_PIN);
	left_ir_val = digitalRead(LEFT_IR_PIN);
	
	if(distance > SAFE_DIST_HIGH)
		move_forward(); 	//irrespective of other obstacles
	else if(distance < SAFE_DIST_LOW)
		move_backward();
	else if(distance >= SAFE_DIST_LOW && distance <= SAFE_DIST_HIGH)
	{
		if(right_ir_val == 0 && left_ir_val ==1)	//object moves right
			move_right();
		else if(left_ir_val == 0 && right_ir_val ==1)	//object moves left
			move_left();
		else
			stop();
	}
	else
		stop();
}

void move_forward()
{
  digitalWrite(LEFT_MOTOR_EN,HIGH);
  digitalWrite(RIGHT_MOTOR_EN,HIGH);

  digitalWrite(LEFT_MOTOR_IN3,HIGH);
  digitalWrite(LEFT_MOTOR_IN4,LOW);

  digitalWrite(RIGHT_MOTOR_IN1,HIGH);
  digitalWrite(RIGHT_MOTOR_IN2,LOW);
}

void move_left()
{
  digitalWrite(LEFT_MOTOR_EN,HIGH);
  digitalWrite(RIGHT_MOTOR_EN,HIGH);

  digitalWrite(LEFT_MOTOR_IN3,HIGH);
  digitalWrite(LEFT_MOTOR_IN4,LOW);

  digitalWrite(RIGHT_MOTOR_IN1,LOW);
  digitalWrite(RIGHT_MOTOR_IN2,HIGH);
}

void move_right()
{
  digitalWrite(LEFT_MOTOR_EN,HIGH);
  digitalWrite(RIGHT_MOTOR_EN,HIGH);

  digitalWrite(LEFT_MOTOR_IN3,LOW);
  digitalWrite(LEFT_MOTOR_IN4,HIGH);

  digitalWrite(RIGHT_MOTOR_IN1,HIGH);
  digitalWrite(RIGHT_MOTOR_IN2,LOW);
}

void move_backward()
{
  digitalWrite(LEFT_MOTOR_EN,HIGH);
  digitalWrite(RIGHT_MOTOR_EN,HIGH);

  digitalWrite(LEFT_MOTOR_IN3,LOW);
  digitalWrite(LEFT_MOTOR_IN4,HIGH);

  digitalWrite(RIGHT_MOTOR_IN1,LOW);
  digitalWrite(RIGHT_MOTOR_IN2,HIGH);
}

void stop()
{
  digitalWrite(LEFT_MOTOR_EN,LOW);
  digitalWrite(RIGHT_MOTOR_EN,LOW);
}
