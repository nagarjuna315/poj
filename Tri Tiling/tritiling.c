#include<stdio.h>

int main ()
{
	int n, a[16],i,j;
	
	a[0] = 1;
	
	for(i=1; i<16; ++i)
	{
		a[i] = a[i-1]*3;
		j = i-2;
		
		while(j>=0)
		{
			a[i] += a[j]*2;
			j--;
		}
	}
	
	while(1)
	{
		scanf("%d", &n);
		if(n==-1) break;
		
		if(n & 1) printf("0\n");
		
		else printf("%d\n",a[n/2]);
		
	}
	return 0;
}