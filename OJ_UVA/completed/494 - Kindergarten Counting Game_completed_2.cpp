#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i,len,counter = 0,flag=0;
    string str;
    for(;;){
        getline(cin, str);
        if(cin.eof()){break;}
        flag = 0;
        counter = 0;
        len = str.length();
        for(i=0;i<len;i++){
            if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i] <=122)){
                if(i+1 == len){
                    counter++;
                }
                flag = 1;
            }else{
                if(flag==1){
                    counter++;
                    flag=0;
                }
            }
        }
        cout << counter << endl;
    }

	return 0;
}
