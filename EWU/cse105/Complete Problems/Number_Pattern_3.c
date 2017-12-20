#include<stdio.h>
main(){
    int i,line_number, x, y, counter,z;
    line_number = 7;
    counter = 1;
    for(i=1;i<=line_number;i++){
        for(x=line_number - i;x>=0;x--){
            printf(" ");
        }
        for(y=i;y>=1;y--){
            printf("%d", y);
        }
        for(z=2;z<=i;z++){
            printf("%d", z);
        }
        printf("\n");
    }
}
