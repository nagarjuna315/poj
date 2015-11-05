#include <stdio.h>

int main() {
	// your code goes here
	
	int t,n,sum,div,r,mini,maxi;
	
	scanf("%d", &t);
	
	while(t--)
	{
		sum=0; div=2;
		scanf("%d", &n);
		
		mini = maxi = n;
		
		while(1)
		{
			r=n%div;
			if(r!=0) break;
			sum++;
			mini-=(1<<(sum-1));
			maxi+=(1<<(sum-1));
			div*=2;
		}
		
		printf("%d %d\n", mini, maxi);
		
	}
	return 0;
}
