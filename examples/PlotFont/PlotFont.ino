#include <plotutils.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "myssid";
const char *passwd = "password";
const char* filename = "/font.gif";

WebServer server;

void setup() {
    Serial.begin(115200);
    SPIFFS.begin(true);
    String pxFilename = "-f/spiffs" + (String)filename;
    char* arguments[4] = {"plotfont", 
                          "-Tgif",
                          (char*)pxFilename.c_str(),
                          "HersheySans"
                          };
    plotfont(4, arguments);
    WiFi.begin(ssid,passwd);
    WiFi.waitForConnectResult();
    server.begin();
    server.serveStatic("/", SPIFFS, filename);
    server.onNotFound([](){server.send(404, "text/plain", "404 - File not found");});
    Serial.print("http://");
    Serial.println(WiFi.localIP());
}
    
void loop() {
  server.handleClient();
  delay(150);
}
