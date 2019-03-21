#include <SoftwareSerial.h>
#define MotorR1 7
#define MotorR2 6
#define MotorRE 9
#define MotorL1 4
#define MotorL2 5
#define MotorLE 3
char c;
int hiz=250;
void setup()
{
   Serial.begin(9600);
   pinMode(MotorR1,OUTPUT);
   pinMode(MotorR2,OUTPUT);
   pinMode(MotorRE,OUTPUT);
   pinMode(MotorL1,OUTPUT);
   pinMode(MotorL2,OUTPUT);
   pinMode(MotorLE,OUTPUT);
}

void loop() 
{
 while(Serial.available())
 {
  delay(10);
  c=Serial.read();
  Serial.println(c);
 
  if(c=='0')
  {
  dur();
  }
  else if(c=='1')
  {
   
  ileri();
  }
 else if(c=='2')
  {
    geri();
  }
  else if(c=='3')
  {
  sagadon();
  }
 else if(c=='4')
  {
  soladon();
  }
  }
}
void ileri()
{
  digitalWrite(MotorR1,HIGH);
  digitalWrite(MotorR2,LOW);
  analogWrite(MotorRE,hiz);
  digitalWrite(MotorL2,HIGH);
  digitalWrite(MotorL1,LOW);
  analogWrite(MotorLE,165);//benim kullandıgım şasede sıkıntı nedeniyle saga cekiyordu bunun için sol motorun gucunu dusurdum....
}
void geri()
{
  digitalWrite(MotorR2,HIGH);
  digitalWrite(MotorR1,LOW);
  analogWrite(MotorRE,hiz);
  digitalWrite(MotorL1,HIGH);
  digitalWrite(MotorL2,LOW);
  analogWrite(MotorLE,hiz);
}
void soladon()
{
  digitalWrite(MotorR2,LOW);
  digitalWrite(MotorR1,HIGH);
  analogWrite(MotorRE,hiz);
  digitalWrite(MotorL1,LOW);
  digitalWrite(MotorL2,LOW);
  analogWrite(MotorLE,hiz);  
}
void sagadon()
{
  digitalWrite(MotorR2,LOW);
  digitalWrite(MotorR1,LOW);
  analogWrite(MotorRE,hiz);
  digitalWrite(MotorL1,LOW);
  digitalWrite(MotorL2,HIGH);
  analogWrite(MotorLE,hiz);  
}
void dur()
{
  digitalWrite(MotorR2,LOW);
  digitalWrite(MotorR1,LOW);
  digitalWrite(MotorRE,0);
  digitalWrite(MotorL1,LOW);
  digitalWrite(MotorL2,HIGH);
  digitalWrite(MotorLE,0);  
}
