/*
Description
Write a program to read four lines of upper case (i.e., all CAPITAL LETTERS) text input (no more than 72 characters per line) from the input file and print a vertical histogram that shows how many times each letter (but not blanks, digits, or punctuation) appears in the all-upper-case input. Format your output exactly as shown.

Input
* Lines 1..4: Four lines of upper case text, no more than 72 characters per line.

Output
* Lines 1..??: Several lines with asterisks and spaces followed by one line with the upper-case alphabet separated by spaces. Do not print unneeded blanks at the end of any line. Do not print any leading blank lines.

Sample Input

THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!

Sample Output

                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

*/

#include <stdio.h>
	
int main() {
	
	char c;
	
	int a[26],i,j,max=-1,sp,prev;
	
	for(i=0; i<26; ++i) a[i] = 0;

	while((c=getchar())!=EOF)
	{
		if(c>='A' && c<='Z') a[c-'A']++;
	}

	
	for(i=0; i<26; ++i)
	{
		if(a[i]>max) max = a[i];
	}
	
	for(i=max; i>0; --i) 
	{
		prev = -1;
		
		for(j=0; j<26; ++j)
		{
			if(a[j]>=i) {
				sp = 2*j - prev - 1;
				prev = 2*j;
				while(sp>0)
				{
					printf(" ");
					sp--;
				}
				printf("*");
			}
		}
		printf("\n");
	}
	
	for(i=0; i<26; ++i) {
		printf("%c", i+'A');
		if(i<25) printf(" ");
	}
	return 0;
}
