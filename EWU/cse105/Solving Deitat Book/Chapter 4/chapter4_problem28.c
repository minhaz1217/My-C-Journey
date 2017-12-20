/*
4.28 (Calculating Weekly Pay) A company pays its employees as managers (who receive a fixed
weekly salary), hourly workers (who receive a fixed hourly wage for up to the first 40 hours they
work and “time-and-a-half”—i.e., 1.5 times their hourly wage—for overtime hours worked), commission
workers (who receive $250 plus 5.7% of their gross weekly sales), or pieceworkers (who receive
a fixed amount of money for each of the items they produce—each pieceworker in this
company works on only one type of item). Write a program to compute the weekly pay for each
employee. You do not know the number of employees in advance. Each type of employee has its
own pay code: Managers have paycode 1, hourly workers have code 2, commission workers have
code 3 and pieceworkers have code 4. Use a switch to compute each employee’s pay based on that
employee’s paycode. Within the switch, prompt the user (i.e., the payroll clerk) to enter the appropriate
facts your program needs to calculate each employee’s pay based on that employee’s paycode.
[Note: You can input values of type double using the conversion specifier %lf with scanf.]
*/

#include<stdio.h>
main(){
    int i,paycode;
    double payAmount, weeklySalary,total, hourlySalary, hoursWorked,itemCost,item;

    for(;;){
        printf("Enter the paycode of the worker:\n 1 for Managers \n 2 for hourly workers \n 3 for commission workers \n 4 for pieceworkers \n");
        scanf("%d", &paycode);
        if(paycode > 4 || paycode <=0){
            break;
        }
        switch(paycode){
        case 1:
            printf("Enter the weekly salary of this manager: ");
            scanf("%lf", &weeklySalary );
            total += weeklySalary;
            printf("This Worker will get %.2lf this week\n", weeklySalary );
            break;
        case 2:
            printf("Enter the hourly salary of this worker: ");
            scanf("%lf", &hourlySalary);
            printf("Enter how many hours this worker worked: ");
            scanf("%lf", &hoursWorked);
            payAmount =0;
            if(hoursWorked > 40){
                total += (hoursWorked - 40)* (hourlySalary * 1.5);
                payAmount += (hoursWorked - 40)* (hourlySalary * 1.5);
                hoursWorked = 40;
            }
                total += hoursWorked * hourlySalary;
                payAmount += hoursWorked * hourlySalary;

            printf("This Worker will get %.2lf this week.\n", payAmount );
            break;
        case 3:
            printf("Enter the gross weekly salary of this commission worker: ");
            scanf("%lf", &weeklySalary);
            total += 250 + weeklySalary + (weeklySalary * .057);
            payAmount = 250 + weeklySalary + (weeklySalary * .057);
            printf("This Worker will get %.2lf this week\n", payAmount );
            break;
        case 4:
            printf("Enter how many items this worker produced: ");
            scanf("%lf", &item );
            printf("Enter the cost for this type of item: ");
            scanf("%lf", &itemCost);
            total += (double) itemCost * item;
            payAmount = (double) itemCost * item;
            printf("This Worker will get %.2lf this week\n", payAmount );
            break;
        }
    }
    printf("The total amount this company has to pay this week for all workers is : %.2lf", total);


}
