/*6.36 (Print a String Backward) Write a recursive function stringReverse that takes a character
array as an argument, prints it back to front and returns nothing. The function should stop processing
and return when the terminating null character of the string is encountered.
*/

#include<stdio.h>

main(){
    void stringReverse(char str[]){
        int i,length =0;
        for(i=0;str[i];i++){
            length++;
        }

        for(i=length-1;i>=0;i--){
            printf("%c", str[i]);
        }
    }
    stringReverse("hello world");
}
