 /*
 * CircleCalculation.c
 * Solution to exercise 1.6: retrieve the radius of
 * a circle and display diameter, circumference and
 * area of the circle.
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
  double radius;   // variable to hold radius
  double diameter; // variable to hold diameter
  double circum;   // variable to hold circumference
  double area;     // variable to hold area
  // constant for pi
  const double pi = 3.14159;

  // scan in radius until value >0 is entered
  do {
    printf("Please enter radius of a circle (>0): ");
    scanf("%lf", &radius);
  } while (radius < 0 );
  
  // perform calculations
  diameter = 2 * radius;
  circum = 2 * pi * radius;
  area = 2 * pi * radius * radius;  
  
  // print results (limited to 2 decimal places)
  printf("Circle with radius %.2f has diameter %.2f, "
	 "circumference %.2f and area %.2f\n", 
	 radius, diameter, circum, area);
  
  // print results (up to 12 decimal places)
  printf("Circle with radius %.12f has diameter %.12f, "
	 "circumference %.12f and area %.12f\n", 
	 radius, diameter, circum, area);

  // print results (in format [-]m.ddddd+-xx)
  printf("Circle with radius %e has diameter %e, "
	 "circumference %e and area %e\n", 
	 radius, diameter, circum, area);

  // terminate
  return EXIT_SUCCESS;
}
