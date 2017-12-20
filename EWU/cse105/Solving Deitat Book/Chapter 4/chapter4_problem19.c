/*
4.19 (Calculating Sales) An online retailer sells five different products whose retail prices are
shown in the following table:
Product number Retail price
1 $ 2.98
2 $ 4.50
3 $ 9.98
4 $ 4.49
5 $ 6.87
Write a program that reads a series of pairs of numbers as follows:
a) Product number
b) Quantity sold for one day
Your program should use a switch statement to help determine the retail price for each product.
Your program should calculate and display the total retail value of all products sold last week.
*/
#include<stdio.h>
main(){
    int pId , count;
    double totalPrice, price;
    for(;;){
        printf("Enter product id and quantity: ");
        scanf("%d %d", &pId, &count);
        if(pId < 1 || pId > 5){
            break;
        }
        switch(pId){
        case 1:
            price = 2.98;
            break;
        case 2:
            price = 4.50;
            break;
        case 3:
            price = 9.98;
            break;
        case 4:
            price = 4.49;
            break;
        case 5:
            price = 6.87;
            break;
        default:
            price = 0;
        }
        totalPrice += price * count;
    }
    printf("Total retail value of all products sold last week: %lf", totalPrice);
}
