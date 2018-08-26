#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,m,q,sz1,sz2,i,a,b;
    string str1,str2,temp;
    cin >> n >> m >> q;
    cin >> str1 >> str2;
    sz1 = str1.size();
    sz2 = str2.size();
    vector<int>arr;
    arr.assign(1004,0);
    for(i=sz2-1;i<=sz1-sz2;i++){
        temp = str1.substr(i, sz2);
        msg(i, temp)
        if(temp == str2){
            arr[i] = 1 + arr[i-1];
        }else{
            arr[i] = 0+ arr[i-1];
        }
    }
    for(i=i;i<=sz1;i++){
        arr[i] = arr[i-1];
    }
    for(i=0;i<=sz1+sz2;i++){
        msg(i, arr[i])
    }
    for(i =0;i<q;i++){
        cin >> a >> b;
        a--,b--;
        if(b-a +1< m){
            cout << 0 << endl;
        }else{
            cout << arr[b]- arr[a-1] << endl;
        }
    }

    return 0;
}
