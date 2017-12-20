#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int a,counter =0;
    char str[200];
    char *ptrCh;
    char strArr[200][21];
    cin >> a;
    while(a--){
        cin.ignore();
        gets(str);
        ptrCh = strtok(str, " .");
        //strArr[counter++] = ptrCh;
        while(ptrCh != NULL){
            strcpy(strArr[counter++],ptrCh);
            ptrCh = strtok(NULL, " .");
        }
        for(int i=0;i<counter;i++){
            cout << strArr[i] << endl;
        }

    }
	return 0;
}
