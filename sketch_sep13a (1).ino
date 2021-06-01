#include <NewPing.h>
#define TRIGGER_PIN1  10
#define ECHO_PIN1     9
#define TRIGGER_PIN2  8
#define ECHO_PIN2     7
#define MAX_DISTANCE 200

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
int R = 13;
int Y = 12;
int G = 11;

void setup()
{
  Serial.begin(9600);
  Serial.println("PROJECT NAME");
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  digitalWrite(R, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(G, LOW);
}

void loop()

{

  static int cnt1 = 0;

  static int cnt2 = 0;
  unsigned int duration1 = sonar1.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int duration2 = sonar2.ping();

  int dist1 = sonar1.convert_cm(duration1); /// pasanger's
  int dist2 = sonar2.convert_cm(duration2);
  //  int dist=distance();// we r calling afunction and that is returning a value
  //  Serial.println(dist1);Serial.println(dist2);

  // Serial.print("Distance");Serial.println(t);

  //Serial.print("Sensor1 Distance : ");Serial.println(dist1);
  //Serial.print("Sensor2 Distance : ");Serial.println(dist2);
  //delay(1000);

  if ((dist1 > 0) && (dist1 < 30))
{
  cnt1++;
  Serial.println(cnt1);
    delay(500);
    if (cnt1== 5)
    {
      digitalWrite(R, HIGH);
   digitalWrite(G,LOW);
    digitalWrite(Y,LOW);
      Serial.println("Passanger Detected RED Signal ON");
      delay(2000);
      cnt1=0;

}
  }
  
  
  else if ((dist2>0)&&(dist2<20))
  {
  cnt2++;
  if(cnt2=5)
  {
    digitalWrite(G,HIGH);
   digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    Serial.println("Vachile dencity detected GREEN Signal ON");
    delay(2000);
    }
  
  }
  
  else
  {
    sig();
    Serial.println("Traffic signal in normal Condition");
  }

}

void sig()
{
  int i,j;
for(i=0;i<10;i++)
{
  digitalWrite(R,HIGH);
   digitalWrite(G,LOW);
    digitalWrite(Y,LOW);
  Serial.println(" RED Signal ON");
  delay(1000);
  }

for(i=0;i<5;i++)
{
  digitalWrite(Y,HIGH);
   digitalWrite(R,LOW);
    digitalWrite(G,LOW);
   Serial.println(" YELLOW Signal ON");
  delay(1000);

  }
for(i=0;i<10;i++)
{

 digitalWrite(G,HIGH);
  digitalWrite(Y,LOW);
   digitalWrite(R,LOW);
 Serial.println(" GREEN  Signal ON");
 delay(1000);

}

 
}
