/*
6.15 (Duplicate Elimination) Use a single-subscripted array to solve the following problem.
Read in 20 numbers, each of which is between 10 and 100, inclusive. As each number is read, print
it only if it’s not a duplicate of a number already read. Provide for the “worst case” in which all 20
numbers are different. Use the smallest possible array to solve this problem.
*/
#include<stdio.h>
main(){
    int num,i, arr[20],j,currentLength=0,flag;
    for(i=0;i<20;i++){
        arr[i] = 0;
    }
    for(i=0;i<20;i++){

        printf("Enter a number: ");
        scanf("%d", &num);
        flag = 1;
        for(j=0;j<currentLength;j++){
            if(arr[j] == num){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            arr[currentLength] = num;
            printf("%d\n", num);
            currentLength++;
        }
    }
    for(i=0;i<currentLength;i++){
            printf("%d\n", arr[i]);
    }

}
