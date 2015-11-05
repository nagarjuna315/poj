#include <stdio.h>

int main(void) {
	// your code goes here
	
	int t, n,sum,div,q;
	
	scanf("%d", &t);
	
	while(t--)
	{
		sum=0; div=5;
		scanf("%d", &n);
		
		while(1)
		{
			q=n/div;
			sum+=q;
			div*=5;
			if(q==0) break;
		}
		
		printf("%d\n", sum);
		
	}
	return 0;
}
