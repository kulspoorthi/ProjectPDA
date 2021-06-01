#include <NewPing.h>
#define TRIGGER_PIN1  10
#define ECHO_PIN1     9

#define MAX_DISTANCE 200

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);

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

  unsigned int duration1 = sonar1.ping(); // Send ping, get ping time in microseconds (uS).
   int dist1 = sonar1.convert_cm(duration1); /// pasanger's
 
  if ((dist1 > 0) && (dist1 < 30))
{
  

    delay(500);
      digitalWrite(G, HIGH);
   digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
      Serial.println("Ambulance Detected Green Signal ON");
      delay(2000);


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
