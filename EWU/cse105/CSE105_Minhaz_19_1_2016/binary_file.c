#include<stdio.h>
main(){
    int a[5];
    FILE *fpb;
    //fpb = fopen("C:\\Users\\Minhaz\\Documents\\Codeblocks 2016\\CSE105_Minhaz_19_1_2016\\data1.dat", "wb");
    int i;
    for(i=0;i<5;i++){
        a[i] = i;
    }
    //fwrite(&a, sizeof(a), 5,fpb);
    //fclose(fpb);
    printf("%d", sizeof(a));
}
