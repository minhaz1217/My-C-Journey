#include<stdio.h>
#include<math.h>
main(){
    int num = 57,i,j,maxBase, oct = 0, power ;
    printf("Enter a number: ");
    scanf("%d", &num);

    for(i=1;i<100;i++){
        if(pow(2, i) > num){
            maxBase = i-1;
            break;
        }
    }
    printf("%d\n", maxBase);
    for(;num != 0;maxBase-- ){
        power = pow(2,maxBase);
        if(power <= num){
        oct = oct*10;
            oct += 1;
            num = num - power;
        }
    }
    printf("The Octal is: %o\n", num);
    printf("The hexadecimal is: %X\n", num);
    printf("The Binary is: %d\n", oct);

}
