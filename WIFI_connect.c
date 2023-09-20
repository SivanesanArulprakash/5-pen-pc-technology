#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
const char* serverIp = "192.168.1.2";  // Replace with the IP of the other device
const int serverPort = 12345;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // Connect to the other device
  WiFiClient client;
  if (client.connect(serverIp, serverPort)) {
    // Send data to the other device
    client.print("Hello from Device 1!");

    // Receive data from the other device
    String response = client.readStringUntil('\r');
    Serial.println("Received: " + response);

    client.stop();
  } else {
    Serial.println("Connection failed");
  }

  delay(5000);  // Delay before the next communication attempt
}
