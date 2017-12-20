#include<stdio.h>
int main(){
    double cpAmount,iRate,year, totalAmount;
    printf("Enter capital amount: ");
    scanf("%lf" , &cpAmount);
    printf("Enter interest rate(in %%): ");
    scanf("%lf" , &iRate);
    printf("Enter year: ");
    scanf("%lf" , &year);
    totalAmount = cpAmount + ((cpAmount * (iRate/100))*year);
    printf("After %.0lf years your %.2lf taka will be %.2lf taka.\n", year, cpAmount , totalAmount);


	return 0;
}
