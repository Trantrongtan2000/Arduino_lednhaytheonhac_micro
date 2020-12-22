int pin[]={2,3,4,5,6,7,8,9}; //Do-Xanhla-Xanhduong-Vang-Vang-Xanhduong-Xanhla-Do
int jack=A2;
int data;
int ledStatus;
int v=50;
void setup() {
  for(int i=0;i<8;i++)
  {
    pinMode(pin[i],OUTPUT);
    digitalWrite(pin[i],1);
  }
  delay(500);
  for (int i=0;i<8;i++)
  {
    digitalWrite(pin[i],0);
  }
}
void loop() {
  data=analogRead(jack);
  mode(data);
  led(ledStatus);
  delay(v);
}
void mode(int d)
{
  d=500-d;
  if(d==0){ledStatus=0;}
  if(d<15&&d>0){ledStatus=1;v=90;}
  if(d>=15&&d<40){ledStatus=2;v=60;}
  if(d>=40&&d<70){ledStatus=3;v=50;}
  if(d>=70&&d<100){ledStatus=4;v=40;}
  if(d>=100&&d<130){ledStatus=5;v=20;}
  if(d>=200){ledStatus=6;v=20;}
}
void led(byte s)
{
  switch (s)
  {
    case 0:
    for(int i=0;i<8;i++)
    {
      digitalWrite(pin[i],0);
    }
    break;
    case 1:
    digitalWrite(pin[2],1);
    digitalWrite(pin[3],1);
    digitalWrite(pin[5],1);
    digitalWrite(pin[0],0);
    digitalWrite(pin[1],0);
    digitalWrite(pin[4],0);
    digitalWrite(pin[6],0);
    digitalWrite(pin[7],0);
    break;
    case 2:
    digitalWrite(pin[2],0);
    digitalWrite(pin[3],0);
    digitalWrite(pin[5],0);
    digitalWrite(pin[0],0);
    digitalWrite(pin[1],1);
    digitalWrite(pin[4],1);
    digitalWrite(pin[6],1);
    digitalWrite(pin[7],0);
    break;
    case 3:
    digitalWrite(pin[2],1);
    digitalWrite(pin[3],0);
    digitalWrite(pin[5],1);
    digitalWrite(pin[0],1);
    digitalWrite(pin[1],0);
    digitalWrite(pin[4],0);
    digitalWrite(pin[6],0);
    digitalWrite(pin[7],1);
    break;
    case 4:
    digitalWrite(pin[2],0);
    digitalWrite(pin[3],0);
    digitalWrite(pin[5],0);
    digitalWrite(pin[0],1);
    digitalWrite(pin[1],1);
    digitalWrite(pin[4],0);
    digitalWrite(pin[6],1);
    digitalWrite(pin[7],1);
    break;
    case 5:
    digitalWrite(pin[2],0);
    digitalWrite(pin[3],1);
    digitalWrite(pin[5],0);
    digitalWrite(pin[0],1);
    digitalWrite(pin[1],0);
    digitalWrite(pin[4],1);
    digitalWrite(pin[6],0);
    digitalWrite(pin[7],1);
    break;
    case 6:
    for(int i=0;i<8;i++)
    {
      digitalWrite(pin[i],1);
    }
    break;
  }
}
