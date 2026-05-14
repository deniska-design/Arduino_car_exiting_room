// class to controll motor

#ifndef CAR_MOTORS_MODULE
#define CAR_MOTORS_MODULE

typedef enum
{
  left    = 2,
  center  = 1,
  right   = 0,
}direction;

class car_motors 
{
  int *motor_pins = new(int);
public:
  car_motors(int pin1, int pin2, int pin3, int pin4);
  void move_directly();
  void stop();
  void move_rightly();
  void move_leftly();
  void spin_drive(int degree, int distance, int spining_speed, int driving_speed, direction spining_direction);
};

  car_motors::car_motors(int pin1, int pin2, int pin3, int pin4)
  {
    motor_pins[1] = pin1;
    motor_pins[2] = pin2;
    motor_pins[3] = pin3;
    motor_pins[4] = pin4;
  }

  void car_motors::move_directly()
  {
    digitalWrite( motor_pins[1], LOW);
    digitalWrite( motor_pins[2], HIGH);
    digitalWrite( motor_pins[3], LOW);
    digitalWrite( motor_pins[4], HIGH);
  }

  void car_motors::stop()
  {
    digitalWrite( motor_pins[1],LOW );
    digitalWrite( motor_pins[2],LOW );
    digitalWrite( motor_pins[3],LOW );
    digitalWrite( motor_pins[4],LOW );
  }

  void car_motors::move_rightly()
  {
    digitalWrite( motor_pins[1], LOW);        
    digitalWrite( motor_pins[2], HIGH);
    digitalWrite( motor_pins[3], HIGH);
    digitalWrite( motor_pins[4], LOW);
  }

  void car_motors::move_leftly()
  {
    digitalWrite( motor_pins[1], HIGH);     
    digitalWrite( motor_pins[2], LOW);
    digitalWrite( motor_pins[3], LOW);
    digitalWrite( motor_pins[4], HIGH);
  }

  void car_motors::spin_drive(int degree, int distance, int spining_speed, int driving_speed, direction spining_direction)
  {
    int delay_time;
    if(spining_direction == right)
    {
      move_rightly();
    }else if(spining_direction == left)
    {
      move_leftly();
    }
    delay_time = (degree*1.0)/(spining_speed*1.0)*1000.0;
    delay(delay_time);
    stop();
    delay(500);
    move_directly();
    delay_time = ((distance*1.0)/(driving_speed*1.0))*(1000*1.0);
    delay(delay_time);
    stop();
  }

#endif