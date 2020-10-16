#include <plot.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "myssid";
const char *passwd = "password";
const char* filename = "/draw_loops.gif";
#define MAXORDER 12

WebServer server;

void draw_c_curve (plPlotter *plotter, double dx, double dy, int order) {
  if (order >= MAXORDER) {
  /* continue path along (dx, dy) */
    pl_fcontrel_r (plotter, dx, dy);
  } else {
    draw_c_curve (plotter,0.5 * (dx - dy), 0.5 * (dx + dy), order + 1);
    draw_c_curve (plotter,0.5 * (dx + dy), 0.5 * (dy - dx), order + 1);
  }
}

int draw_main (FILE* outfile) {

  plPlotter *plotter;
  plPlotterParams *plotter_params;

  /* set a Plotter parameter */
  plotter_params = pl_newplparams ();
  pl_setplparam (plotter_params, "BITMAPSIZE", (void*)"600x600");
  
  /* create a Postscript Plotter that writes to standard output */
  if ((plotter = pl_newpl_r ("gif", stdin, outfile, stderr,
                                 plotter_params)) == NULL) {
       fprintf (stderr, "Couldn’t create Plotter\n");
       return 1;
  }
    
  if (pl_openpl_r (plotter) < 0) {   /* open Plotter */
    fprintf (stderr, "Couldn’t open Plotter\n");
    return 1;
  }
  pl_fspace_r (plotter, 0.0, 0.0, 1000.0, 1000.0); /* set coor system */
  pl_flinewidth_r (plotter, 0.25);    /* set line thickness */
  pl_pencolorname_r (plotter, "red"); /* use red pen */
  pl_erase_r (plotter);/* erase graphics display */
  pl_fmove_r (plotter, 600.0, 300.0); /* position the graphics cursor */
  draw_c_curve (plotter, 0.0, 400.0, 0);
  if (pl_closepl_r (plotter) < 0) {    /* close Plotter */
    fprintf (stderr, "Couldn’t close Plotter\n");
    return 1;
  }
  
  if (pl_deletepl_r (plotter) < 0) {   /* delete Plotter */
    fprintf (stderr, "Couldn’t delete Plotter\n");
    return 1;
  }
  return 0;
}

void setup() {
    Serial.begin(115200);
    SPIFFS.begin(true);
    String pxFilename = "/spiffs" + String(filename);
    FILE *outfile = fopen(pxFilename.c_str(), "w");
    draw_main(outfile);
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
