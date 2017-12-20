#include<stdio.h>
main(){
    int i,age,counter=0;
    for(i=0;i<10;i++){
        printf("Enter age: ");
        scanf("%d", &age);
        if(age < 50 || age>60){
            continue;
        }else{
            counter++;
        }
    }
    printf("%d", counter);
}
