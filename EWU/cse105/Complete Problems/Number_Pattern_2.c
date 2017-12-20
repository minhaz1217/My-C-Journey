#include<stdio.h>
main(){
    int i,line_number, x, y, counter;
    line_number = 3;
    counter = 1;
    for(i=1;i<=line_number;i++){
        for(x=line_number - i;x>=0;x--){
            printf(" ");
        }
        for(y=i-1;y>=0;y--){
            printf("%d ", counter);
            counter++;
        }
        printf("\n");
    }
}
