/*
6.19 (Dice Rolling) Write a program that simulates the rolling of two dice. The program should
use rand twice to roll the first die and second die, respectively. The sum of the two values shouldthen be calculated. [Note: Because each die can show an integer value from 1 to 6, then the sum of
the two values will vary from 2 to 12, with 7 being the most frequent sum and 2 and 12 the least
frequent sums.] Figure 6.24 shows the 36 possible combinations of the two dice. Your program
should roll the two dice 36,000 times. Use a single-subscripted array to tally the numbers of times
each possible sum appears. Print the results in a tabular format. Also, determine if the totals are reasonable;
i.e., there are six ways to roll a 7, so approximately one-sixth of all the rolls should be 7.
*/

#include <stdlib.h>
#include<stdio.h>
main(){
    int dice1, dice2, sum,counter[12],i;
    for(i=0;i<12;i++){
        counter[i] = 0;
    }

    for(i=0;i<36000;i++){
        dice1 = (int)(rand()%5) + 1;
        dice2 = (int)(rand()%5) + 1;
        sum = (int)dice1 + dice2;
        counter[sum-1]++;
    }
    for(i=0;i<12;i++){
        printf("We got %d, %d times.\n", i+1, counter[i]);
    }
}
