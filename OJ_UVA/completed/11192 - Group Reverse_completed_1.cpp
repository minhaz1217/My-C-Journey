#include<iostream>
using namespace std;
int main(){
    int n,i,j,len,p;
    string str;
    char temp;
    for(;;){
        cin >> n;
        if(n==0){
            break;
        }
        cin >> str;
        len = str.length() / n;
        //check(len)
        for(p=0;p<n;p++){
            for(i=p*len,j=len*(p+1)-1;i<=j;i++,j--){
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
            //check(str)
        }
        cout << str<< endl;
    }


	return 0;
}
