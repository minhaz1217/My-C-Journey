#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int tc,counter;
    string str,str1, revStr;
    int arr[27];
    cin >> tc;
    while(tc--){
        cin >> str;
        counter = 0;
        for(int i=0;i<27;i++){
            arr[i] = 0;
        }
        for(int i=0;str[i];i++){
            arr[ str[i]-'a' ]++;
        }
        for(int i=0;i<27;i++){
            if(arr[i] >0){
                counter++;
            }
        }
        if(counter == 1){
            cout << "-1" << endl;
        }else{
            revStr = str;
            reverse(revStr.begin(), revStr.end());
            if(str != revStr){
                cout << str << endl;
            }else{
                str1 = "";
                for(int i=0;i<27;i++){
                    if(arr[i] > 0){
                        for(int j=0;j<arr[i];j++){
                            str1 += (i + 'a');
                        }
                    }
                }
                cout << str1 << endl;
            }
        }
    }


    return 0;
}
