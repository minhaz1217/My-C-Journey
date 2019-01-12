#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    int n;
    char c;
    string str;
    vector<int>vec,arr;
    arr.assign(5,0);
    cin >> n;
    cin >> str;
    for(int i=0;i<str[i];i++){
        c = str[i];
        vec.push_back(c - '0');
        arr[ c - '0' ]++;
    }
    if( arr[0] == arr[1] && arr[0] == arr[2] ){
        cout << str << endl;
    }else{
        if(arr[0] < n/3){
            for(int i=0;str[i];i++){
                c = str[i];
                if(arr[ c- '0' ]>n/3 && c!= '0'){
                    arr[c-'0']--;
                    arr[0]++;
                    str[i] = '0';
                }
                if(arr[0] == n/3){
                    break;
                }
            }
        }
        if(arr[2] < n/3){
            for(int i=str.size()-1;i>=0;i--){
                c = str[i];
                if(arr[ c- '0' ]>n/3 && c!= '2'){
                    arr[c-'0']--;
                    arr[2]++;
                    str[i] = '2';
                }
                if(arr[2] == n/3){
                    break;
                }
            }
        }
        if(arr[1] < n/3){
            if(arr[2] > n/3){
                for(int i=0;str[i];i++){
                    c = str[i];
                    if(c== '2'){
                        arr[2]--;
                        arr[1]++;
                        str[i] = '1';
                    }
                    if(arr[1] == n/3 || arr[2] == n/3){
                        break;
                    }
                }
            }
            if(arr[0] > n/3){
                for(int i=str.size()-1;i>=0;i--){
                    c = str[i];
                    if(c == '0'){
                        arr[0]--;
                        arr[1]++;
                        str[i] = '1';
                    }
                    if(arr[1] == n/3 || arr[0] == n/3){
                        break;
                    }
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}
