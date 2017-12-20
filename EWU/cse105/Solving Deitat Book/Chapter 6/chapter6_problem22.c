/*
6.22 (Total Sales) Use a double-subscripted array to solve the following problem. A company has
four salespeople (1 to 4) who sell five different products (1 to 5). Once a day, each salesperson passes
in a slip for each different type of product sold. Each slip contains:
a) The salesperson number
b) The product number
c) The total dollar value of that product sold that day
Thus, each salesperson passes in between 0 and 5 sales slips per day. Assume that the information
from all of the slips for last month is available. Write a program that will read all this information
for last month’s sales and summarize the total sales by salesperson by product. All totals should be
stored in the double-subscripted array sales. After processing all the information for last month,
print the results in tabular format with each column representing a particular salesperson and each
row representing a particular product. Cross total each row to get the total sales of each product for
last month; cross total each column to get the total sales by salesperson for last month. Your tabular
printout should include these cross totals to the right of the totaled rows and to the bottom of the
totaled columns.
*/

#include<stdio.h>
main(){
    int i,j, spNum, pNum;
    double sales[4][5], price,total=0;
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            sales[i][j] = 0;
        }
    }

    for(;;){
        printf("Enter your Sales Person Number: ");
        scanf("%d", &spNum);
        if(spNum == 0 || spNum >4){
            break;
        }
        printf("Enter the product number: ");
        scanf("%d", &pNum);
        if(pNum == 0 || spNum > 5){
            break;
        }
        printf("Enter total dollar value of that product sold that day: ");
        scanf("%lf", &price);
        sales[spNum -1][pNum - 1] +=price;
    }

        for(i=0;i<4;i++){
            printf("SalesPerson %d  ", i+1);
            for(j=0;j<5;j++){
                printf("Item%d sold: %lf  ", j+1, sales[i][j]);
                total += sales[i][j];
            }
            printf("Total: %lf", total);
            total =0;
        printf("\n");
        }
        total =0;
        for(i=0;i<5;i++){
            for(j=0;j<4;j++){
                total+= sales[j][i];
            }
            printf("     %lf", total);
            total = 0;
        }




}
