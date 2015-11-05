/*
Description
To calculate the circumference of a circle seems to be an easy task - provided you know its diameter. But what if you don't?

You are given the cartesian coordinates of three non-collinear points in the plane.
Your job is to calculate the circumference of the unique circle that intersects all three points.

Input
The input will contain one or more test cases. Each test case consists of one line containing six real numbers x1,y1, x2,y2,x3,y3, representing the coordinates of the three points. The diameter of the circle determined by the three points will never exceed a million. Input is terminated by end of file.

Output
For each test case, print one line containing one real number telling the circumference of the circle determined by the three points. The circumference is to be printed accurately rounded to two decimals. The value of pi is approximately 3.141592653589793.
*/

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main() {
	// your code goes here
	
	double a[2][3], x1,x2,x3,y1,y2,y3,rx,ry,c,r;
	
	while(1)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1, &x2,&y2,&x3,&y3);
		
		a[0][0] = 2 *(x1-x2);
		a[0][1] = 2 * (y1-y2);
		a[0][2] = (x1*x1 - x2*x2) + (y1*y1 - y2*y2);
		
		a[1][0] = 2 *(x1-x3);
		a[1][1] = 2 * (y1-y3);
		a[1][2] = (x1*x1 - x3*x3) + (y1*y1 - y3*y3);
		
		if(abs(a[0][1])<0.00000001 || abs(a[1][1])<0.00000001)
		{
			if(abs(a[0][1])<0.00000001)
			{
				rx = a[0][2]/a[0][0];
			}
			else
			{
				rx = a[1][2]/a[1][0];
			}
		}
		else
		{
			c = a[0][1]/a[1][1];
			a[0][0] -= c*a[1][0];
			a[0][1] -= c*a[1][1];
			a[0][2] -= c*a[1][2];
		
			rx = a[0][2]/a[0][0];
		}
		
		if(abs(a[0][0])<0.00000001 || abs(a[1][0])<0.00000001)
		{
			if(abs(a[0][0])<0.00000001)
			{
				ry = a[0][2]/a[0][1];
			}
			else
			{
				ry = a[1][2]/a[1][1];
			}
		}
		else
		{
			c = a[1][0]/a[0][0];
			a[1][0] -= c*a[0][0];
			a[1][1] -= c*a[0][1];
			a[1][2] -= c*a[0][2];
			ry = a[1][2]/a[1][1];
		}
			
		
		r = sqrt((rx-x1)*(rx-x1) + (ry-y1)*(ry-y1));
		
		c = 2 * PI * r;
		printf("%.2lf\n",c);
		
		if(getchar()==EOF) break;
	}
	return 0;
}
