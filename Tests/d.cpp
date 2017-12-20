//http://codeforces.com/problemset/problem/118/A

#include<iostream>
#include<ctype.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int counter = 0,i,flag=0,j;
    string vow = "aeiouyAEIOUY", str;
    char a[100];
    char b;
    cin >> str;
    for(j=0;str[j];j++){
        b = str[j];
        flag = 0;
        for(i=0;vow[i];i++){
            if(b == vow[i]){
                flag = 1;
                break;
            }
        }
        if(flag !=1 ){
            a[counter++] = tolower(b);
        }
    }

    a[counter] = NULL;

    for(i=0;a[i];i++){
        cout << "." << a[i];
    }


	return 0;
}
