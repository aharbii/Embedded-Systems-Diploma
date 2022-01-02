/******************************************************************************
 * Sheet.02
 * 
 * Problem.01:
 *      --> Write a program that reads the radius of a circle and calculates
 *          the area and circumference.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 31th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main()
{
    double radius;
    printf("Enter radius of the circle: ");
    scanf("%lf", &radius);

    double circumference = 2 * PI * radius;
    double area = PI * radius * radius;

    printf("Area          = %.4lf square units\n", area);
    printf("Circumference = %.4lf units\n", circumference);
    return 0;
}