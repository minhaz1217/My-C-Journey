#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,a,last,counter;
    vector<int>vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size()-1;i++){
        if(vec[i] == vec[i+1]){
            vec[i] = -1;
            vec[i+1] = -1;
            i+=1;
        }
    }
    sort(vec.begin(),vec.end());
    counter = 0;
    for(int i=0;i<vec.size();i++){
        if(vec[i] != -1){
            counter += abs(vec[i] - vec[i+1]);
            i++;
        }
    }
    cout << counter << endl;





    return 0;
}
