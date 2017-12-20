#include<stdio.h>
#include<math.h>
main(){
    double p,c=1,d=2,n=1;
    for(;;){
        printf("Enter Original Cost: ");
        scanf("%lf", &c);
        if(c==0){break;}
        printf("Enter Rate of Depreciation (per year): ");
        scanf("%lf", &d);
        printf("Enter Number of Years: ");
        scanf("%lf", &n);
        p = c* pow((1-d),n);
        printf("The Present vlaues after %lf years: %lf\n", n, p);
    }
}
