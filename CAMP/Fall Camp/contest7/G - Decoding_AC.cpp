#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int i,n,r,l;
    string str,str2;
    cin >> n;
    cin >> str;
    str2 = str;
    r = n-1;
    l = 0;
    //n++;
    int k = 1;
    for(i=n-1;i>=0;i--){
        if(k %2 == 0){
            str2[l++] = str[i];
        }else{
            str2[r--] = str[i];
        }
        k++;
    }
    cout << str2 << endl;


    return 0;
}
