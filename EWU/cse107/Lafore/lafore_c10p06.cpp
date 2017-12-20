#include<iostream>
#include<cstring>
using namespace std;
#define check(a) cout<<a<< endl;
int strcomp(char *str1, char *str2){
    if(strlen(str1) > strlen(str2)){
        return 1;
    }else if(strlen(str2) > strlen(str1)){
        return -1;
    }else{
        for(int i=0;str1[i];i++){
            if(str1[i] > str2[i]){
                return 1;
            }else if(str1[i] < str2[i]){
                return -1;
            }
        }
        return 0;
    }
}



int main(){
    char a[] = "helloo" , b[] = "world";
    cout << strcomp(a, b) << endl;
    cout << strcmp(a,b) << endl;
	return 0;
}
