#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;
int f1(vector<int>vec){
    return (vec[0] + vec[1] + vec[2]);
}
int f2(vector<int>vec){
    return (vec[0] + vec[1] - vec[2]);
}
int f3(vector<int>vec){
    return (vec[0] + vec[1] * vec[2]);
}

int f4(vector<int>vec){
    return (vec[0] - vec[1] + vec[2]);
}

int f5(vector<int>vec){
    return (vec[0] - vec[1] - vec[2]);
}


int f6(vector<int>vec){
    return (vec[0] - vec[1] * vec[2]);
}

int f7(vector<int>vec){
    return (vec[0] * vec[1] + vec[2]);
}

int f8(vector<int>vec){
    return (vec[0] * vec[1] - vec[2]);
}

int f9(vector<int>vec){
    return (vec[0] * vec[1] * vec[2]);
}

int main(){
    int a,b,c,i,ans = INT_MAX;
    vector<int>vec;
    cin >> a >> b >> c;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    sort(vec.begin(), vec.end());
    for(i=1;i<=8;i++){
        next_permutation(vec.begin(), vec.end());
        //cc(f1(vec))
        ans = min(ans, min( f1(vec),min(f2(vec), min(f3(vec), min(f4(vec), min(f5(vec), min(f6(vec), min(f7(vec), min(f8(vec), f9(vec))))))))));
    }
    cout << ans << endl;
    //cout << (vec[0] -vec[2] * vec[1]) << endl;


    return 0;
}
