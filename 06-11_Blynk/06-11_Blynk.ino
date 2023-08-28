//https://iotcircuithub.com/blynk-iot-platform-setup-esp8266-esp32/

#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPL6iC3ezk-Q"
#define BLYNK_DEVICE_NAME "SchooMyIoT"
#define BLYNK_AUTH_TOKEN "uq2ZQyTP4ecENYO7fTWENTLsHtOtUM3J" //18行目にも同じものを入れる。

#define ledPin 26 //OUTPUTA:26 OUTPUT:13

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "uq2ZQyTP4ecENYO7fTWENTLsHtOtUM3J";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "AP01-01";
char pass[] = "1qaz2wsx";

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0){ //Blynk Virtual Pin
  int ledStatus = param[0].asInt();
  digitalWrite(ledPin, !ledStatus);
  Serial.println("---------------");
  Serial.printf("LED Status = %d\r\n", ledStatus);
}