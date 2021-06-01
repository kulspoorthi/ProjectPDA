#include <ESP8266WiFi.h>
const char ssid[] = "smartparking";  //  your network SSID (name)
const char pass[] = "1234567890";       // your network password

WiFiServer server(80);
#include <SoftwareSerial.h>
SoftwareSerial RFID_Serial(13,18); 

char z[10];
int b1[10]={0};
int k=0,g=0;
char s;
int count1[8]={0};
int web[8]={0};
unsigned long previousMillis[8] = {0};
unsigned long currentMillis[8];
const int buttonPin = 15;  
//const int ledPin =  14; 
int mn=14,mp=12;
int buttonState = 0;
int ifo,ib; 
void setup() 

{ 
  Serial.begin(9600);
  RFID_Serial.begin(9600);
  gsmSerial.begin(9600); 
 // gsm();
pinMode(D0, OUTPUT);
  digitalWrite(D0, LOW);
 // pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(mn, OUTPUT);
   pinMode(mp, OUTPUT);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  server.begin();
  Serial.println("Server started");
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");    
}

void loop() {
 static int cnt=0;
 static int retf,retb;
 retf++;
 if((retf>=1)&&(retf<=20))
 {
 forword();
// Serial.println("FORWORD");
 }
else if((retf>=21) &&(retf<=40))
 {
  back();
//   Serial.println("BACK");
 }
if(retf>42)
{
  retf=0;
}
  if(digitalRead(buttonPin)==HIGH)
  {
    Serial.println("ALART MESSAGE SENDING");
    gsm();
  }
  if (RFID_Serial.available()>0) 
  {     
    s=(RFID_Serial.read());
    z[k]=s;
    k++;
  }
  
  if(k==10)
  {
    if((z[0]=='1')&&(z[1]=='3')&&(z[2]=='0')&&(z[3]=='3')&&(z[4]=='6')&&(z[5]=='7')&&(z[6]=='8')&&(z[7]=='4'))
    {k=0;
    Serial.println("alert");
    currentMillis[0] = millis();
    if(b1[0]==0)
    {
      b1[0]=1;
    gsm1();
    }
     count();
    }
    if((z[0]=='0')&&(z[1]=='4')&&(z[2]=='0')&&(z[3]=='5')&&(z[4]=='8')&&(z[5]=='9')&&(z[6]=='5')&&(z[7]=='1'))
    {k=0;
    Serial.println("alert2");
    currentMillis[1] = millis();
    if(b1[1]==0)
    {
      b1[1]=1;
    gsm1();
    }
    count();
     }
    if((z[0]=='0')&&(z[1]=='0')&&(z[2]=='4')&&(z[3]=='6')&&(z[4]=='0')&&(z[5]=='9')&&(z[6]=='3')&&(z[7]=='5'))
    {k=0;
    Serial.println("alert3");
    currentMillis[2] = millis();
    if(b1[2]==0)
    {
      b1[2]=1;
    gsm1();
    }
    count();
    }
    if((z[0]=='1')&&(z[1]=='3')&&(z[2]=='0')&&(z[3]=='3')&&(z[4]=='6')&&(z[5]=='8')&&(z[6]=='0')&&(z[7]=='7'))
    {k=0;
    Serial.println("alert4");
    currentMillis[3] = millis();
    if(b1[3]==0)
    {
      b1[3]=1;
    gsm1();
    }
    count();
    }
    if((z[0]=='1')&&(z[1]=='3')&&(z[2]=='0')&&(z[3]=='3')&&(z[4]=='3')&&(z[5]=='7')&&(z[6]=='4')&&(z[7]=='1'))
    {k=0;
    Serial.println("alert5");
    currentMillis[4] = millis();
    if(b1[4]==0)
    {
      b1[4]=1;
    gsm1();
    }
    count();
    }
    if((z[0]=='0')&&(z[1]=='9')&&(z[2]=='2')&&(z[3]=='5')&&(z[4]=='5')&&(z[5]=='9')&&(z[6]=='2')&&(z[7]=='1'))
    {k=0;
    Serial.println("alert6");
    currentMillis[5] = millis();
    if(b1[5]==0)
    {
      b1[5]=1;
    gsm1();
    }
    count();
    }
    if((z[0]=='0')&&(z[1]=='2')&&(z[2]=='5')&&(z[3]=='1')&&(z[4]=='1')&&(z[5]=='9')&&(z[6]=='2')&&(z[7]=='2'))
    {k=0;
    Serial.println("alert7");
    currentMillis[6] = millis();
    if(b1[6]==0)
    {
      b1[6]=1;
    gsm1();
    }
    count();
    }
  }
  webserver();
}
void buzzer()
{
  digitalWrite(D0, HIGH);
  delay(2000);
  digitalWrite(D0, LOW);
  return ;
}

void webserver()
{
WiFiClient client = server.available();
  if (!client) {
    return;
  }
 Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE html>");
client.println("<html>");
client.println("<meta http-equiv=\"refresh\" content=\"2\">");
client.println("<body style=\"background: linear-gradient(to bottom, #00ffcc 0%, #669999 100%);\">");

client.println("<head>");
client.println("<style>");
client.println("table {");
    client.println("font-family: arial, sans-serif;");
    client.println("border-collapse: collapse;");
    client.println("width: 100%;");
client.println("}");

client.println("td, th {");
    client.println("border: 1px solid #dddddd;");
    client.println("text-align: left;");
    client.println("padding: 18px;");
client.println("}");

client.println("tr() {");
    client.println("background-color: #dddddd;");
client.println("}");
client.println("</style>");
client.println("</head>");

client.println("<h2><font size=\"10\" color=\"WHITE\">NO PARKING DATABASE</font></h2>");

client.println("<table>");
  client.println("<tr>");
    client.println("<th>REG NUMBER</th>");
    client.println("<th>OWNER NAME</th>");
    client.println("<th>ADDRESS</th>");
    client.println("<th>Number of times Violated</th>");
  client.println("</tr>");
  if(web[0]==1)
  {
  client.println("<tr>");
    client.println("<td>KA 0805</td>");
    client.println("<td>ALBERT</td>");
    client.println("<td>123 5TH CROSS XYZ</td>");
    client.println("<td>");
    client.println((count1[0])-1);
  client.println("</tr>");
  }
  if(web[1]==1)
  {
  client.println("<tr>");
    client.println("<td>KA 1958 </td>");
    client.println("<td>JOHN</td>");
    client.println("<td>35 6TH CROSS HJD</td>");
    client.println("<td>");
    client.println((count1[1])-1);
  client.println("</tr>");
  }
  if(web[2]==1)
  {
  client.println("<tr>");
    client.println("<td>KA R37</td>");
    client.println("<td>DAVID</td>");
    client.println("<td>ROYAL HOUSE 39TH CROSS MND</td>");
    client.println("<td>");
    client.println((count1[2])-1);
  client.println("</tr>");
  }
  if(web[3]==1)
  {
  client.println("<tr>");
    client.println("<td>KA GD78</td>");
    client.println("<td>TONY</td>");
    client.println("<td>DILKUSH XY P.O CVC</td>");
    client.println("<td>");
    client.println((count1[3])-1);
  client.println("</tr>");
  }
  if(web[4]==1)
  {
  client.println("<tr>");
    client.println("<td>KA UC38</td>");
    client.println("<td>KEVIN</td>");
    client.println("<td>DREAM HOUSE 3RD CROSS AMA</td>");
    client.println("<td>");
    client.println((count1[4])-1);
  client.println("</tr>");
  }
  if(web[5]==1)
  {
  client.println("<tr>");
    client.println("<td>BEN</td>");
    client.println("<td>KA 9F3</td>");
    client.println("<td>23 56TH CROSS KNS</td>");
    client.println("<td>");
    client.println((count1[5])-1);
  client.println("</tr>");
  }
  if(web[6]==1)
  {
  client.println("<tr>");
    client.println("<td>SALIM</td>");
    client.println("<td>KA 9453</td>");
    client.println("<td>26 68TH CROSS BKN</td>");
    client.println("<td>");
    client.println((count1[06])-1);
  client.println("</tr>");
  }
client.println("</table>");

client.println("</body>");
client.println("</html>");

  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 loop();
}
  

}
