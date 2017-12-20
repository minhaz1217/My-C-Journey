#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
using namespace std;
#define check(a) cout<<a<< endl;
/*
void reversit(string str){
    string temp;
    int i,j;
    char c;
    temp = str;
    for(i=0,j=str.length()-1;i<=str.length();i++,j--){
        temp[i] = str[j];
    }
    temp[i-1] = '\0';
    cout << temp << endl;
}
*/
void reversit(char str[]){
    char temp[strlen(str)];
    int i,j;
    for(i=0,j=strlen(str)-1;j>=0;i++,j--){
        temp[i] = str[j];
    }
    temp[i] = '\0';
    cout << temp;
}

int main(){
    string str;
    //cout << "Enter a string: ";
    //getline(cin, str);
    //cout << "The reverse of it is: " << reversit("heladfadflo") << endl;
    char c[200];
    cout << "Enter a string: ";
    gets(c);
    reversit(c);
	return 0;
}
