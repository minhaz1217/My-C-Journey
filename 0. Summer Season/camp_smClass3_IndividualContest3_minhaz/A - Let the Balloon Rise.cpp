#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 104




int main(){

    int n,i, curr, index;

    string str;
    int bloonCount = 1;
    while(scanf("%d", &n) == 1){
        cin.ignore();
            //msg("N" , n)
        if(n == 0){
            break;
        }
        int arr[n+4];
        map<string ,int > mp;
        map<int, string>mp2;
        bloonCount = 1;
        for(i=1;i<=n;i++){
            getline(cin, str);
            if(!mp[str]){
                mp[str] = bloonCount;
                mp2[bloonCount] = str;
                bloonCount++;
            }
            arr[i] = 0;
            arr[mp[str]]++;
        }
        curr = 0;
        index = 0;
        for(i=1;i<=n;i++){
            if(curr < arr[i]){
                curr = arr[i];
                index = i;
            }
        }
        //msg(curr, index)
        //cc(mp2[index])
        cout << mp2[index] << endl;

    }
    return 0;
}
