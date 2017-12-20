/*
6.31 (Palindromes) A palindrome is a string that’s spelled the same way forward and backward.
Some examples of palindromes are: “radar,” “able was i ere i saw elba,” and, if you ignore blanks, “a
man a plan a canal panama.” Write a recursive function testPalindrome that returns 1 if the string stored in the array is a palindrome and 0 otherwise. The function should ignore spaces and punctuation
in the string.
*/
#include<stdio.h>

main(){

    int testPalindrome(char name[]){
        int i,counter=0,flag=1,j;
        char name1[100],name2[100];

        for(i=0;name[i];i++){
            if(name[i] == ' '){
                continue;
            }else{
                name1[counter] = name[i];
                counter++;
            }
        }


        name1[counter] = NULL;

        for(i=0,j=counter-1;j>=0;i++,j--){
            name2[i] = name1[j];
        }
        name2[counter] = NULL;


        for(i=0;i<counter;i++){
            if(name1[i] != name2[i]){
                flag =0;
                break;
            }else{
                flag =1;
            }
        }
        if(flag == 1){
            return 1;
        }else{
            return 0;
        }

    }

    int x = testPalindrome("radar");
    printf("%d", x);
}
