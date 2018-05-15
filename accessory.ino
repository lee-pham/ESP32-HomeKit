#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>

const char* ssid = "*************";
const char* password = "*****";


void setup(void)
{  
    Serial.begin(115200);

    // Connect to WiFi network
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Set up mDNS responder:
    // - first argument is the domain name, in this example
    // - second argument is the IP address to advertise
    //   we send our IP address on the WiFi network
    if (!MDNS.begin("esp32")) {
        Serial.println("Error setting up MDNS responder!");
        while(1) {
            delay(1000);
        }
    }
    //server.begin();
    MDNS.addService("hap", "tcp", 51828);
    MDNS.addServiceTxt("hap", "tcp", "md", "esp32");
    MDNS.addServiceTxt("hap", "tcp", "ci", "1");
    MDNS.addServiceTxt("hap", "tcp", "c#", "1");
    MDNS.addServiceTxt("hap", "tcp", "id", "FF:3C:ED:5A:1B:A2");
    //MDNS.addServiceTxt("hap", "tcp", "sh", "D4G2BG==");
    MDNS.addServiceTxt("hap", "tcp", "ff", "0");
    MDNS.addServiceTxt("hap", "tcp", "s#", "1");
    MDNS.addServiceTxt("hap", "tcp", "sf", "1");
}

void loop(void)
{
}
