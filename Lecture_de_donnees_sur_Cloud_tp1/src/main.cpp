#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

char ssid[] = "Ooredoo _S20_4EBF" ;
char pass[] = "7730C317" ;
WiFiClient client;
// Configuration ThingSpeak
unsigned long myChannelNumber = 455630;  
const char * myWriteAPIKey = "JOMKSF62IFOY42XO";
unsigned int temperatureField=1;
void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid,pass);
  ThingSpeak.begin(client);
}

void loop(){
  float temperature =ThingSpeak.readFloatField(myChannelNumber,temperatureField,myWriteAPIKey);
  Serial.print("Current temp is: ");
  Serial.print(temperature);
  Serial.println("C");
  
  delay(5000);
}