/*
There are N lines, each line always start with character ’0’ followed by ’.’, then unknown
number of digits x, finally each line always terminated with three dots ”...”. See an example below.
2
0.1227...
0.517611738...
*/

#include <cstdio> // or <cstdio>
//#include<stdio.h>
using namespace std;
char digits[100]; // using global variables in contests can be a good strategy
int main()
{   int N;
    scanf("%d", &N);
    while (N--)   // we simply loop from N, N-1, N-2, ... 0
    {
        scanf("0.%[0-9]...", &digits); // surprised?
        //scanf("%c", &digits); // surprised?
        printf("the digits are 0.%s\n", digits);
    }
}
