#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int tc,s,a,taken,counter,sz,sum;
    pair<long long int,long long int>f;
    char c;
    vector<long long int>mid;
    vector<pair<long long int,long long int> > all;
    cin >> tc;
    while(tc--){
        cin >> c >> s;
        if(c == 'G'){
            a = 0;
        }else if(c == 'F'){
            a = 1;
        }else if(c == 'M'){
            a = 2;
        }else{
            a = 3;
        }
        all.push_back(make_pair(s, a));
    }
    sort(all.begin(), all.end());
    mid.assign(4,0);
    mid[0] = 1;
    mid[1] = 1;
    mid[2] = 2;
    mid[3] = 2;
    counter = 6;
    sz = all.size()-1;
    taken = 0;
    sum = 0;
    for(int i=sz;i>=0 && taken != 11;i--){
        f = all[i];
        if(mid[f.second] > 0){
            counter--;
            mid[f.second]--;
            taken++;
            //msg3("TAKING", f.second, f.first, taken)
            sum += f.first;
        }else{
            if(f.second == 0){
                continue;
            }
            if(11 - taken-counter > 0){
                sum+=f.first;
                taken++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
