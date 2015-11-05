/*
Description

Farmer John's cows have entered into a competition with Farmer Bob's cows. They have drawn lines on the field so it is a square grid with N × N points (2 ≤ N ≤ 100), and each cow of the two herds has positioned herself exactly on a gridpoint. Of course, no two cows can stand in the same gridpoint. The goal of each herd is to form the largest square (not necessarily parallel to the gridlines) whose corners are formed by cows from that herd.

All the cows have been placed except for Farmer John's cow Bessie. Determine the area of the largest square that Farmer John's cows can form once Bessie is placed on the field (the largest square might not necessarily contain Bessie).

Input
Line 1: A single integer, N
Lines 2..N+1: Line i+1 describes line i of the field with N characters. The characters are: 'J' for a Farmer John cow, 'B' for a Farmer Bob cow, and '*' for an unoccupied square. There will always be at least one unoccupied gridpoint.

Output
Line 1: The area of the largest square that Farmer John's cows can form, or 0 if they cannot form any square.

Sample Input

6
J*J***
******
J***J*
******
**B***
******

Sample Output

4
*/


#include <stdio.h>

void readip(int a[100][100], int n)
{
	int i,j;
	char str[100];
	for(i=0; i<n; ++i)
	{
		scanf("%s", str);
		for(j=0; j<n; ++j)
		{
			if(str[j] == 'J') a[i][j] = 1;
			else if (str[j] == '*') a[i][j] = 0;
			else a[i][j] = -1;
			printf("%d",a[i][j]);
		}
		printf("\n%s\n",str);
	}
}

int main() {
	int n, a[100][100], maxi=0, ar;
	scanf("%d", &n);
	
	readip(a, n);
	
	int i,j,k,l;
	
	int t,h,b,c;
	
	for(i=0; i<n; ++i)
	{
		for(j=0; j<n; ++j)
		{
			if(a[i][j]==-1) continue;
			
			for(k=0; i+k<n; ++k)
			{
				for(l=1; j+l<n; ++l)
				{
					ar = k*k+l*l;
					if(ar<=maxi) continue;
					
					if(i+l>=n || j-k<0) continue;
					if(i+l+k>=n || j-k+l>=n) continue;
					
					t = a[i][j];
					h = a[i+k][j+l];
					b = a[i+l][j-k];
					c = a[i+l+k][j-k+l];
					
					if(t+h+b+c>=3) maxi = ar;
				}
			}
		}
	}
	
	printf("%d\n",maxi);
	
	return 0;
}

