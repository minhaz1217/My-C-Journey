#include<stdio.h>
main(){
    int r,l,s;
    r = 0;
    l = 15;
    s = 10;
    do{
        r= l%s;
        l =s;
        s =r;
    }while(s!=0);
    printf("%d\n", l);
}
