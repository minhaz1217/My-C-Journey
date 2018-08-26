#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,m,a,i,counter,curr;
    vector<long long int> vec;
    cin >> n >> m;
    counter = 0;
    curr = m;
    for(i =0;i<n;i++){
        cin >> a;
        if(a < curr){
            counter = 0;
            curr -= a;
        }else if(a >= curr){
            a -= curr;
            counter = 1;
            curr = m;
            if(a < curr){
                curr -= a;
            }else{
                counter += (a/curr);
                curr = a%curr;
            }
            if(curr == 0){
                curr = m;
                //counter++;
            }
        }
        vec.push_back(counter);
    }
    for(i=0;i<vec.size();i++){
        if(i>0){
            cout << " ";
        }
        cout << vec[i];
    }
    cout << endl;
    return 0;
}
