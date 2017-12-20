/*
4.17 (Calculating Credit Limits) Collecting money becomes increasingly difficult during periods
of recession, so companies may tighten their credit limits to prevent their accounts receivable
(money owed to them) from becoming too large. In response to a prolonged recession, one company
has cut its customers’ credit limits in half. Thus, if a particular customer had a credit limit of $2000,
it’s now $1000. If a customer had a credit limit of $5000, it’s now $2500. Write a program that
analyzes the credit status of three customers of this company. For each customer you’re given:
a) The customer’s account number
b) The customer’s credit limit before the recession
c) The customer’s current balance (i.e., the amount the customer owes the company).
Your program should calculate and print the new credit limit for each customer and should
determine (and print) which customers have current balances that exceed their new credit limits.
*/
#include<stdio.h>
main(){
    int accountNumber[3], creditLimit[3], currentBalance[3], i, newLimit;

    for(i=1;i<=3;i++){
        printf("Enter Account Number of Customer %d: ", i);
        scanf("%d", &accountNumber[i-1]);
        printf("Enter Credit Limit of Customer %d: ", i);
        scanf("%d", &creditLimit[i-1]);
        printf("Enter Current Balance of Customer %d: ", i);
        scanf("%d", &currentBalance[i-1]);
    }
    for(i=0;i<3;i++){
        newLimit = creditLimit[i]/2;
        printf("\nThe new limit of customer %d is %d", i+1, newLimit);
        if(newLimit < currentBalance[i]){
            printf("\nCustomer %d has exceeded their new credit limits", i+1);
        }
    }




}
