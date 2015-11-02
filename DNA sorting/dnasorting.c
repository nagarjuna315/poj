/*
Description
One measure of ``unsortedness'' in a sequence is the number of pairs of entries that are out of order with respect to each other. For instance, in the letter sequence ``DAABEC'', this measure is 5, since D is greater than four letters to its right and E is greater than one letter to its right. This measure is called the number of inversions in the sequence. The sequence ``AACEDGG'' has only one inversion (E and D)---it is nearly sorted---while the sequence ``ZWQM'' has 6 inversions (it is as unsorted as can be---exactly the reverse of sorted).

You are responsible for cataloguing a sequence of DNA strings (sequences containing only the four letters A, C, G, and T). However, you want to catalog them, not in alphabetical order, but rather in order of ``sortedness'', from ``most sorted'' to ``least sorted''. All the strings are of the same length.

Input
The first line contains two integers: a positive integer n (0 < n <= 50) giving the length of the strings; and a positive integer m (0 < m <= 100) giving the number of strings. These are followed by m lines, each containing a string of length n.

Output
Output the list of input strings, arranged from ``most sorted'' to ``least sorted''. Since two strings can be equally sorted, then output them according to the orginal order.

Sample Input

10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

Sample Output

CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA

*/



#include <stdio.h>
#include <stdlib.h>
	
int main() {
	
	int n,m, a[4],i,j;
	
	scanf("%d %d", &n, &m);
	
	int s[100];
	
	for(i=0; i<100; ++i)
		s[i] = 0;
	
	char* st[100];
	
	//read input strings and measure their sortedness
	for(i=0; i<m; ++i)
	{
		st[i] = malloc((n+1) * sizeof(char));
		
		scanf("%s", st[i]);
		
		for(j=0; j<4; ++j) 
			a[j] = 0;
		
		for(j=0; j<n; ++j)
		{
			switch(st[i][j])
			{
				case 'A':
					s[i] += a[1] + a[2] + a[3];
					break;
					
				case 'C':
					a[1]++;
					s[i] += a[2] + a[3];
					break;
					
				case 'G':
					a[2]++;
					s[i] += a[3];
					break;
					
				case 'T':
					a[3]++;
					break;
					
			}
		}
		
	}
	
	//sort the strings
	for(i=1; i<m; ++i)
	{
		for(j=i-1; j>=0; --j)
		{
			if(s[j]<=s[j+1]) break;
		
			int ti = s[j];
			s[j] = s[j+1];
			s[j+1] = ti;
			
			char* tc = st[j+1];
			st[j+1] = st[j];
			st[j] = tc;
 		}
	}
	
	for(i=0; i<m; ++i) 
	{
		printf("%s\n", st[i] );
	}
	
	return 0;
}
