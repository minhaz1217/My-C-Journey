#include<stdio.h>
main(){
    int a[5],b,i;
    i=1;
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    printf("%d\n", a[i++]);
    printf("%d", a[i]);

}
