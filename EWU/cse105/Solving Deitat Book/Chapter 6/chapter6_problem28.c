/*
6.28 (Duplicate Elimination) In Chapter 12, we explore the high-speed binary search tree data
structure. One feature of a binary search tree is that duplicate values are discarded when insertions
are made into the tree. This is referred to as duplicate elimination. Write a program that produces
20 random numbers between 1 and 20. The program should store all nonduplicate values in an array.
Use the smallest possible array to accomplish this task.
*/

#include<stdio.h>
main(){
    int i,j, flag, randd, arr[20],counter = 0;
    for(i=0;i<20;i++){
        arr[i] = 0;
    }

    for(i=0;i<20;i++){
        randd = (rand()%19) + 1;
        flag = 1;
        for(j=0;j<counter;j++){
            if(randd == arr[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            arr[counter] = randd;
            counter++;
        }
    }
    for(i=0;i<20;i++){
        printf("%d\n", arr[i]);
    }
}
