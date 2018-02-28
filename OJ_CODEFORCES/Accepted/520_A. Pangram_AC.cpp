#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long n,arr[26],i,flag;
    string str;
    cin >> n;
    cin >> str;

    for(i=0;i<26;i++){
        arr[i] = 0;
    }
    if(n < 26){
        cout << "NO" << endl;
    }else{
        for(i=0;str[i];i++){
            if(str[i] <= 'z' && str[i] >= 'a'){
                arr[(str[i] - 'a')] = 1;
            }else{
                arr[(str[i] - 'A')] = 1;
            }


        }
        flag = 0;
        for(i=0;i<26;i++){
            if(arr[i] != 1){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }



	return 0;
}
