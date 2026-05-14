#include "Servo.h"
#include "IRremote.h"
#include "Display.h"
#include "HC-SR04.h"
#include "Car_motors.h"

#define SCL_Pin    A5  //Set clock pin to A5
#define SDA_Pin    A4  //Set data pin to A4
#define SERVO_Pin  A3  

#define SIG_RIGHT   0xC23D  
#define SIG_LEFT    0x22DD  
#define SIG_DIRECT  0x629D  
#define SIG_STOP    0xA857 

enum
{

  degree_coefficient = 90,

  spining_speed      = 240,     //degree per second
  driving_speed      = 80,       //cm per second

  HCtrig_pin = 12,
  HCecho_pin = 13,
  
  IRrecv_Pin = 3, 

};

unsigned char bitmapArrowright[] = {  0x00,   0x00,   0x00,   0x00,   0x00, 0x00,   0x18,   0x24,   0x42,   0x81,   0x00,   0x00, 0x00,   0x00,   0x00,   0x00  };
unsigned char bitmapArrowleft[] = {  0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x81,   0x42,   0x24,   0x18,   0x00,   0x00,  0x00, 0x00,   0x00, 0x00  };
unsigned char smile[] = { 0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00 };

car_motors motors(5, 2, 4, 6); 

HCSRO4 hcsr04(HCtrig_pin, HCecho_pin);

Display display(8, 16, SCL_Pin, SDA_Pin);

Servo servo;                // create servo object to control a servo 

IRrecv irrecv (IRrecv_Pin);             // порт IR Sencor


float way[3];

void setup (){
  servo.attach(SERVO_Pin);            // attaches the servo om pin 13 to the servo object

  irrecv.enableIRIn();        //запускаем IR Sencor
  
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
    way[i] = hcsr04.send_and_read_sound_pulse();
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
  motors.spin_drive(grad, way[spining_direction], spining_speed, driving_speed, spining_direction);
  
} 