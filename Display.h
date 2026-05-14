// class for controlling display matrix

#ifndef DISPLAY_MODULE
#define DISPLAY_MODULE

class Display
{
  int high, weight, clock_pin, data_pin;
public:
  Display(int h, int w, int SCL_Pin, int SDA_Pin);
  void IIC_start();  
  void IIC_end();
  void IIC_send(unsigned char send_data);
  void matrix_display(unsigned char matrix_value[]);
  
};
 
Display::Display(int h, int w, int SCL_Pin, int SDA_Pin)
{
  high = h;
  weight = w;
  clock_pin = SCL_Pin;
  data_pin = SDA_Pin;
  pinMode(clock_pin,OUTPUT);           // порты Led Matrix:
  pinMode(data_pin,OUTPUT);
}

void Display::IIC_start()
{
  digitalWrite(clock_pin,HIGH);
  delayMicroseconds(3);
  digitalWrite(data_pin,LOW);
  delayMicroseconds(3);
}

void Display::IIC_end()
{
  digitalWrite(clock_pin,LOW);
  delayMicroseconds(3);
  digitalWrite(data_pin,LOW);
  delayMicroseconds(3);
  digitalWrite(clock_pin,HIGH);
  delayMicroseconds(3);
  digitalWrite(data_pin,HIGH);
  delayMicroseconds(3);
}

void Display::IIC_send(unsigned char send_data)
{
  for(char i = 0;i < high;i++)  //Every character has 8 bits
  {
      digitalWrite(clock_pin,LOW);  //pull down the SCL_Pin to change the signal of SDA
      delayMicroseconds(3);
      if(send_data & 0x01)  //1 or 0 of byte  is used to set high and low level of SDA_Pin
      {
        digitalWrite(data_pin,HIGH);
      }
      else
      {
        digitalWrite(data_pin,LOW);
      }
      delayMicroseconds(3);
      digitalWrite(clock_pin,HIGH); //Pull up SCL_Pin to stop data transmission
      delayMicroseconds(3);
      send_data = send_data >> 1;  //Detect bit by bit, so move the data right by one bit
  }
}

void Display::matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //the function to call the data transmission
  IIC_send(0xc0);  //Select address
  
  for(int i = 0;i < weight;i++) //Pattern data has 16 bytes
  {
     IIC_send(matrix_value[i]); //data to convey patterns
  }
  IIC_end();   //end the transmission of patterns data
  IIC_start();
  IIC_send(0x8A);  //display control, set pulse width to 4/16
  IIC_end();
}

#endif
