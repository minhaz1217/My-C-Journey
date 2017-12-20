#include<stdio.h>
main(){
    int a, i,j,k, totalnumbercount,space,columnmaxnumber,currentnumber;
    int row, column;
    row =0;
    column =0;
    a = 2;
    totalnumbercount = 20;
    a = 0;

    for(i=1;i<=totalnumbercount; i ++){
        i = i + a; // 0 ,
        a += 1;
        column +=1;

    printf("%d\n", i);
    }

    printf("\n\n\n\n");
    space = column -1;
    currentnumber = 1;

    for(k=1;k<=column;k++){
            columnmaxnumber = columnmaxnumber + 1+ k;
        for(i=0;i<=space;i++){
            printf(" ");
        }
        space--;
    /*
        for(j=currentnumber; j<=columnmaxnumber;j++){
            printf("%d", currentnumber);
            currentnumber++;
        }
        */
        printf("*\n");
    }

    printf("%d", a);

    /*
         1
       2 3 4
     5 6 7 8 9
    */



















}
