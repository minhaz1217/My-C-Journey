/*
6.10 (Sales Commissions) Use a single-subscripted array to solve the following problem. A company
pays its salespeople on a commission basis. The salespeople receive $200 per week plus 9% of
their gross sales for that week. For example, a salesperson who grosses $3,000 in sales in a week receives
$200 plus 9% of $3,000, or a total of $470. Write a C program (using an array of counters)
that determines how many of the salespeople earned salaries in each of the following ranges (assume
that each salesperson’s salary is truncated to an integer amount):
a) $200–299
b) $300–399
c) $400–499
d) $500–599
e) $600–699
f) $700–799
g) $800–899
h) $900–999
i) $1000 and over
*/
#include<stdio.h>
main(){
    int counter[9], i,pay, salary;
    for(i=0;i<9;i++){
        counter[i] = 0;
    }
    for(;;){
        printf("Enter the gross sales for this worker: ");
        scanf("%d", &pay);
        if(pay == 0){
            break;
        }
        salary = 200 + (pay*.09);
        if(salary >= 200 && salary < 300){
            counter[0]++;
        }else if(salary >= 300 && salary < 400){
            counter[1]++;
        }else if(salary >= 400 && salary < 500){
            counter[2]++;
        }else if(salary >= 500 && salary < 600){
            counter[3]++;
        }else if(salary >= 600 && salary < 700){
            counter[4]++;
        }else if(salary >= 700 && salary < 800){
            counter[5]++;
        }else if(salary >= 800 && salary < 900){
            counter[6]++;
        }else if(salary >= 900 && salary < 1000){
            counter[7]++;
        }else if(salary >=1000){
            counter[8]++;
        }

    }
    for(i=0;i<8;i++){
        printf("Salary counter between %d and %d is: %d\n", (i+2)*100, (i+3)*100, counter[i]);
    }
    printf("Salary counter more than 1000 is: %d\n", counter[8]);

}
