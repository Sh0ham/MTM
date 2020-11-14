#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct Points //Structure declaration
{
  float x;
  float y;
}Points;

typedef struct Circles
{
  struct Points center;
  float radius;
}Circles;

int isIncluded(Circles Circle, Points Point); //Function declaration

int main()
{
  Circles Circle; //Variables declaration
  Points Point;
  printf("Enter the coordinates of your point: "); //Retrieving data
  scanf("%f %f", &Point.x, &Point.y);
  printf("Enter the radius and the center of your circle: ");
  scanf("%f %f %f", &Circle.radius, &Circle.center.x, &Circle.center.y);
  isIncluded(Circle, Point) ? printf("\nThe point is included in the circle") : printf("\nThe point is not included in the circle"); //Printing result
  return 0;
}

/*Function name: isIncluded
Input: Circle and point
Output: One or zero, depends if the point is inside the circle
Algorithm: Measuring the distance between the given point and the center of the circle,
the point is included inside the domain if the distance is lesser than the radius*/
int isIncluded(struct Circles Circle, struct Points Point)
{
  float distance = sqrt(pow(Point.x - Circle.center.x, 2) + pow(Point.y - Circle.center.y, 2));
  return (distance < Circle.radius) ? 1 : 0; //Logic test
}
