#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

//got auth code in Blynk-App
char auth[] = "ALnAFPGPq6w7sxreKC0n2TOYCQ6dT5ku";
 
// WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WLAN-952631";
char pass[] = "*******";

int LED = D8; // Define LED 

void setup()
{
  // Debug console
  Serial.begin(115200);
 pinMode(LED, OUTPUT); //Set the LED (D8) as an output
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
 
}
 
// This function will be called every time button Widget
// in Blynk app writes values to the Virtual Pin V3
BLYNK_WRITE(V3) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(LED, HIGH); // Turn LED on.
  } else {
    digitalWrite(LED, LOW); // Turn LED off.
 }
}
