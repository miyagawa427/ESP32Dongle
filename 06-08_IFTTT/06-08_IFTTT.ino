//https://magazine.halake.com/entry/esp32_ifttt?utm_source=feed

#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "AP01-01"; //ここを変える。
const char* password =  "1qaz2wsx"; //ここを変える。
 
const String endpoint = "https://maker.ifttt.com/trigger/";//定型url
const String eventName = "SchooMyIoT";//IFTTTのEvent Name
const String conn = "/with/key/";//定型url
const String Id = "dg3wFxKYz14w7H873MTa0";//自分のIFTTTのYour Key　ここを変える
const String value ="?value1=aaa&value2=bbbb&value3=ccccc";//値 value1=xxxx value2=xxxxx value3=xxxxx

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) {
 
    HTTPClient http;
 
    http.begin(endpoint + eventName + conn + Id + value); //URLを指定
    int httpCode = http.GET();  //GETリクエストを送信
 
    if (httpCode == 200) { //返答がある場合
      Serial.println("200.OK");
    }else {
      Serial.println("Error on HTTP request");
    }
    http.end(); //Free the resources
  }
  delay(30000);   //30秒おきに更新
}
