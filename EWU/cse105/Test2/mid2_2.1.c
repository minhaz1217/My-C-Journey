#include<stdio.h>
main(){
    char ch[20] = "DhaKa";
    int i;
    for(i=0;ch[i];i++){
        if(ch[i] >= 'a' || 'A' &&ch[i] >= 'z' || 'Z'){
            printf("%c is a character\n" ,ch[i]);
        }
    }
}
