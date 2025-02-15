#include <stdio.h>
#include <math.h>
#define IOTA 0.0000000001

double integration(double x, double y) {
   return 1./36*(12*x*y*sqrt(x*x+y*y)+6*y*y*y*log(sqrt(x*x+y*y)+x)-3*x*x*x*log(sqrt(x*x+y*y)+y)\
      +9*x*x*x*atanh(y/sqrt(x*x+y*y))-2*y*y*y);
}

int main() {
   /*
   int t;
   scanf("%d", &t);
   while(t--) {
      double x1, y1, x2, y2, u1, v1, u2, v2;
      scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
      scanf("%lf %lf %lf %lf", &u1, &v1, &u2, &v2);
   }*/
   printf("%.10f", integration(1, 1));
}
