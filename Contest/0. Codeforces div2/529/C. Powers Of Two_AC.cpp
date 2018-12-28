#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    int n,k,a,takeFull=0;
    vector<int>vec;
    cin >> n >> k;
    bitset<34>bt(n);
    a = (1<< (int)(floor(log2(n))));
    while(a != 1){
        //cc(a)
        //5msg("HI",a)
        bitset<34>bt(n);
        if(bt.count() == k){
            takeFull = 1;
            break;
        }
        if(2*a <= n && k-1 <=n-a){
            vec.push_back(a);
            n = n-a;
            k--;
        }else{
            a = a/2;
        }
    }
    if(takeFull == 1){
        bitset<34>bt(n);
        for(int i=0;i<34;i++){
            if(bt.test(i) == 1){
                //msg("FOUND", i)
                vec.push_back( (1<<i));
            }
        }
        cout << "YES"<< endl;
        sort(vec.begin(), vec.end());
        for(int i=0;i<vec.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << vec[i];
        }
        cout << endl;
    }else{
        if(k == n){
            for(int i=0;i<n;i++){
                vec.push_back(1);
            }
            cout << "YES"<< endl;
            sort(vec.begin(), vec.end());
            for(int i=0;i<vec.size();i++){
                if(i>0){
                    cout << " ";
                }
                cout << vec[i];
            }
            cout << endl;
        }else{
            //msg("VEC", vec.size())
        cout << "NO" << endl;
        }
    }

    return 0;
}
