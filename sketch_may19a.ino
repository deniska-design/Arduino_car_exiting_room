#include "Servo.h"
#include "HC-SR04.h"
#include "Car_motors.h"

#define SERVO_Pin  A3  

enum
{
  degree_coefficient = 90,
  HCtrig_pin = 12,
  HCecho_pin = 13,
};

car_motors motors(5, 2, 4, 6); 
HCSRO4 hcsr04(HCtrig_pin, HCecho_pin);
Servo servo;                // create servo object to control a servo 

float way[3];

void setup (){
  servo.attach(SERVO_Pin);            // attaches the servo om pin 13 to the servo object
  
  Serial.begin(9600);         //скорость передачи данных
}

void loop ()
{  
  
  float delay_time; 
  int grad;
  direction spining_direction;
  
  for (int i = 0; i < 3; i++)
  {
    servo.write(i*degree_coefficient);              // tell servo to go to position in variable 'pos'
    delay(1000);
    way[i] = hcsr04.read_distance();
    delay(10);
  }
  
  
  if((way[right] > way[left]) && (way[right] > way[center]))
  {
    grad = 90;
    spining_direction = right;
  }else if((way[left] > way[right]) && (way[left] > way[center]))
  {
    grad = 90;
    spining_direction = left;
  }else if((way[center] > way[right]) && (way[center] > way[left]))
  {
    grad = 0;
    spining_direction = center;
  }
  motors.spin(grad, spining_direction);
  motors.drive(way[spining_direction]);
} 
