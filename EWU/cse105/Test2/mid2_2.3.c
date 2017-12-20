#include<stdio.h>
#include<string.h>
double x()
{
    double y;
    int sum = 51, n=7;
    y = sum/n;
    printf("In Function: %lf\n", y);

    return y;

}


main()
{
double a = x();
    printf("%lf", a);
}
