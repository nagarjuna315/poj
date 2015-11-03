/*Description
The cows in farmer John's herd are numbered and branded with consecutive integers from 1 to N (1 <= N <= 10,000,000). When the cows come to the barn for milking, they always come in sequential order from 1 to N.

Farmer John, who majored in mathematics in college and loves numbers, often looks for patterns. He has noticed that when he has exactly 15 cows in his herd, there are precisely four ways that the numbers on any set of one or more consecutive cows can add up to 15 (the same as the total number of cows). They are: 15, 7+8, 4+5+6, and 1+2+3+4+5.

When the number of cows in the herd is 10, the number of ways he can sum consecutive cows and get 10 drops to 2: namely 1+2+3+4 and 10.

Write a program that will compute the number of ways farmer John can sum the numbers on consecutive cows to equal N. Do not use precomputation to solve this problem.

Input
* Line 1: A single integer: N

Output
* Line 1: A single integer that is the number of ways consecutive cow brands can sum to N.

Sample Input

15

Sample Output

4
*/

#include <stdio.h>

int main() {

        int n,l=1, u=1, cs=1,t=1;

        scanf("%d", &n);

        while(l<(n/2+1))
        {
                if(cs<n)
                {
                        u++;
                        cs += u;
                }
                else if(cs>n)
                {
                        cs -= l;
                        l++;
                }
                else
                {
                        u++;
                        cs += u;
                        cs -= l;
                        l++;
                        t++;
                }
        }

        printf("%d\n", t);

        return 0;
}
