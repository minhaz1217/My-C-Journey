#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,a,b,i,j,c,flag,counter,sz,sz2;

    scanf("%lld", &n);
    counter = 0;
    vector<long long int> vec,vec2;
    map<long long int,int>mp;
    int myFlag[n];
    for(i=0;i<n;i++){
        scanf("%lld", &a);
        if(!mp[a]){
            mp[a] = 1;
            vec.push_back(a);
        }else{
            mp[a]++;
        }
    }
    vec2.push_back(1);
    for(i=0;i<30;i++){
        vec2.push_back((2<<i));
        //msg(i,vec[i-1])
    }

    sz = vec.size();
    sz2 = vec2.size();
    //cc("HI")
    for(i=0;i<sz2;i++){
        //cc(vec2[i])
    }
    counter = 0;
    for(i=0;i<sz;i++){
        a = vec[i];
        flag = 0;
        for(j=0;j<sz2;j++){
            b = vec2[j];
            //msg(a,b)
            if(b-a > 0 && mp[ (b-a) ]  ){
                if( b-a != a ){
                    flag = 1;
                    break;
                }else{
                    if(mp[a] > 1){
                        flag = 1;
                        break;

                    }
                }
            }
        }
        if(flag == 0){
            counter+=mp[a];
        }
    }
    cout << counter << endl;

    return 0;
}
