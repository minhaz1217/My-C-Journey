#include<stdio.h>
int main(){
    int year;
    scanf("%d", &year);
    if(year % 400 == 0 || (year %100 != 0 && year %4 ==0)){
        printf("%d is Leap Year\n", year);
    }else{
        printf("%d is not Leap Year\n",year);}
    return 0;
}
