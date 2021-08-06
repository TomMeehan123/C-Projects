// Integrate.c
// 
// Sample solution for exercise 5.2
// numeric integration
// of function x^2 + 2x + 3
//
///////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

double integrate(double lower, double upper, int steps);
double f(double x);

int main()
{
  double y,z,result;
  int steps;
  int valueOK=0;
  
  while (!valueOK) {
    
    // read in values for y and z
    printf("\nPlease enter the limits y and z (-10.5 <= y < z <= 30.75): ");
    scanf("%lf%lf", &y, &z);
    // check that values are within valid range
    // scan in number of steps
    printf("\nPlease enter the number of steps: ");
    scanf("%i",&steps);
    if ( (-10.5<=y) && (y<z) && (z<=30.75) && (steps>0) ) valueOK=1;
    
  }
  
  // call integrate
  result = integrate(y,z,steps);
  
  // print result
  printf("\n\nIntegration of f(x) from %f to %f yields %f\n",y,z,result);
  
  return EXIT_SUCCESS;
}

///////////////////////////////////////////////
// integrate(lower, upper, steps)
// performs numeric integration of the function
// with the limit lower to upper by adding up
// the area of steps number of rectangles under 
// the curve of the function
//
// param: double lower - lower limit for integration
//        double upper - upper limit for integration
//	  int steps - number of rectangles used
// return: approximation of the numeric integration
//	   value from lower to upper
///////////////////////////////////////////////
double integrate(double lower, double upper, int steps)
{
  int i;
  double s;
  double result;
  
  // calculate width of each rectangle
  s = (upper-lower)/steps;
  // initialse result to zero
  result = 0;
  // add up the area of all rectangles
  for (i=0; i<steps; i++)
    result += f(lower + (i*s)) * s;
  
  // return result to calling function
  return result;
  
}

///////////////////////////////////////////////
// f(x)
// models the function to be integrated. In
// this case the function is x^2 + 2x + 3
//
// param:	double x - function value
// return:	fuction value at location x
///////////////////////////////////////////////
double f(double x) {
  return x*x + 2*x + 3;
}
