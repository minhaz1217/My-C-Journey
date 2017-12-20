#include<stdio.h>
main(){
    int i, len;
    char name[40] = "Dhaka";
    len = 0;
    for(i=0;name[i];i++){
        len++;
    }
    printf("%d , %d", i , len);
}
