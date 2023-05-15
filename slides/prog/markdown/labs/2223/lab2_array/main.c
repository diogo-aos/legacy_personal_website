#include <stdio.h>
#include <math.h>
#include "lab1.h"

double target_x = -20631.634499587468;
double target_y = 13314.636406242847;

double vec_ang(double x1, double y1, double x2, double y2){
  double angle = atan((y2-y1)/(x2-x1));
  if (x2-x1 < 0) return angle + 180;
  else if (x2-x1 > 0 && y2-y1<0) return angle+360;
  else return angle;
}

double vec_mag(double x1, double y1, double x2, double y2){
  
}

int main(void) {

  return 0;
}
