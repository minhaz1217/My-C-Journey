#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,a,k,mm,maxColor,flag,color = 0;
    vector<int> vec;
    vector<pair<int,int> > vec2;
    map<int,int>mp,colored;
    cin >> n >> k;
    mm = 0;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
        vec2.push_back( make_pair( a, i ) );
        if(!mp[a]){
            mp[a] = 1;
        }else{
            mp[a]++;
        }
        mm = max(mm,a);
    }
    sort(vec2.begin(), vec2.end());
    flag = 1;
    for(int i=1;i<=mm;i++){
        if(mp[i]>k){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        for(int i=0;i<vec2.size();i++){
            vec[ vec2[i].second ]  = (i%k)+1;
        }


        for(int i=0;i<vec.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << vec[i];
        }
        cout << endl;
    }

    return 0;
}
