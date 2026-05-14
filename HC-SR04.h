// class for controlling HC-SRO4 

#ifndef HCSRO4_MODULE
#define HCSRO4_MODULE

class HCSRO4
{
  int trig_pin, echo_pin;
  float duration, distance;  
public:
  HCSRO4(int HCTrig_Pin, int HCEcho_Pin);
  float send_and_read_sound_pulse();
  void show_distance();
};

HCSRO4::HCSRO4(int HCTrig_Pin, int HCEcho_Pin)
{
  trig_pin = HCTrig_Pin;
  echo_pin = HCEcho_Pin;
  pinMode(trig_pin, OUTPUT);  
	pinMode(echo_pin, INPUT);
  digitalWrite(echo_pin,LOW);  
  digitalWrite(trig_pin, LOW); 
}

float HCSRO4::send_and_read_sound_pulse()
{  
  digitalWrite(echo_pin,LOW);  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = (duration*.0343)/2;

  return distance;
}

void HCSRO4::show_distance()
{
  Serial.print("Distance: ");  
	Serial.println(distance);  
}

#endif