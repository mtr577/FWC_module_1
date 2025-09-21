//1) return a structure with area and perimeter of a circle from a function that takes radius as input. Print area and perimeter in main function.


#include<stdio.h>
#define pi 3.14
struct circle
{
	float parameter;
	float area;
};
struct circle cal(int radius)
{
	struct circle c;
	c.parameter = 2*pi*radius;
	c.area = 2*pi*radius*radius;
	return c;
}
int main()
{
	int radius;
	struct circle c;
	printf("Enter radius R: \n");
	scanf("%d",&radius);
	c = cal(radius);
	printf("Parameter of circle: %.3f\n",c.parameter);
	printf("Area of circle: %.3f\n",c.area);
	return 0;
}
