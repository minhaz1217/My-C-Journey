#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int arr[100] = {0}, c,tc, i,counter = 0;
    string str;
    cin >> tc;
    while(tc--){
        cin >> str;
        counter = 0;
        for(i=0;i<100;i++){
            arr[i] = 0;
        }
        for(i=0;str[i];i++){
            if(str[i] >= 'A' && str[i] <='Z'){
                c = str[i] - 'A';
            }else if(str[i] >= 'A' && str[i] <='z'){
                c = str[i] - 'A';
            }
            arr[c]++;
        }
        for(i=0;i<=100;i++){
            if(arr[i] >= 2){
                counter++;
            }
        }
        if(counter >= 2){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }

    return 0;
}
