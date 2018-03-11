#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,a,i,counter,curr,sum;
    vector<int>vec,mv;
    cin >> n;
    n--;
    while(n--){
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    counter = 0;
    curr = vec[0];
    //cc(vec.size())
    sum = 0;
    for(i=0;i<vec.size();i++){
        //msg(curr,vec[i])
        if(vec[i] != curr){
            mv.push_back(sum);
            curr = vec[i];
            //msg(curr, sum)
            sum =1;
        }else{
            sum ++;
        }
    }
    mv.push_back(sum);
    for(i=0;i<mv.size();i++){
        cc(mv[i])
        counter += mv[i]%2;
    }
    cc(counter)
    return 0;
}
