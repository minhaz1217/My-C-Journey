#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


#define MX 100004
int p[MX];
int val[MX];
int findSet(int x){
    if(p[x] == x){
        return x;
    }
    return findSet(p[x]);
}

int unionSet(int x, int y){
   // cc("HI")
    int l = findSet(x);
    int k = findSet(y);
    p[findSet(y)] = findSet(x);
    val[l] += val[k];

}


int main(){
    int tc,i,n,k,x,y,counter;
    string str1, str2;
    cin >> tc;
    while(tc--){
        map<string, int>mp;
        counter = 1;
        cin >> k;
        for(i=0;i<=k;i++){
            p[i] = i;
            val[i] = 1;
        }
        while(k--){
            cin >> str1 >> str2;
            //msg(str1, str2)
            if(!mp[str1]){
                mp[str1] = counter++;
            }
            if(!mp[str2]){
                mp[str2] = counter++;
            }
            x = mp[str1];
            y = mp[str2];
            if(x > y){
                swap(x,y);
            }
            if(findSet(x) != findSet(y)){
                unionSet(x,y);
            }
            cout << val[findSet(x)] << endl;
        }
    }
    return 0;
}
