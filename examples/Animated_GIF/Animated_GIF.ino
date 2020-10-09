#include <plot.h>
void setup() {
  Serial.begin(115200);
  plPlotter *plotter;
  plPlotterParams *plotter_params;
  plotter_params = pl_newplparams();
  pl_setplparam(plotter_params, "BIMAPSIZE", (void*)"320x240");
  plotter = pl_newpl_r ("gif", stdin, stdout, stderr, plotter_params);
  pl_openpl_r (plotter);
  pl_fspace_r (plotter,-0.5, -0.5, 149.5, 99.5);
  pl_pencolorname_r (plotter, "red");
  pl_linewidth_r (plotter, 5);
  pl_filltype_r (plotter, 1);
  pl_fillcolorname_r (plotter, "black");
  for (int i = 0; i < 180 ; i += 15) {
    pl_erase_r (plotter);
    pl_ellipse_r (plotter, 75, 50, 40, 20, i);
  }
  pl_closepl_r (plotter);
  pl_deletepl_r (plotter); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
