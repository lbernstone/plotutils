#include <plotutils.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "larryb";
const char *passwd = "clownfish";
const char* filename = "/graph.gif";

WebServer server;

void setup() {
    Serial.begin(115200);
    SPIFFS.begin(true);
    File datafile = SPIFFS.open("/datafile", "w");
    datafile.print("0.0 0.0 1.0 0.2 2.0 0.0 3.0 0.4 4.0 0.2 5.0 0.6");
    datafile.close();
    String pxFilename = "-o/spiffs" + (String)filename;
    char* arguments[4] = {"graph", 
                          "-Tgif",
                          (char*)pxFilename.c_str(),
                          "/spiffs/datafile"
                          };
    graph(4, arguments);
    WiFi.begin(ssid,passwd);
    WiFi.waitForConnectResult();
    server.begin();
    server.serveStatic("/", SPIFFS, "/graph.gif");
    server.onNotFound([](){server.send(404, "text/plain", "404 - File not found");});
    Serial.print("http://");
    Serial.println(WiFi.localIP());
}
    
void loop() {
  server.handleClient();
  delay(150);
}
