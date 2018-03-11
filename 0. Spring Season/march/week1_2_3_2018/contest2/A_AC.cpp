//https://www.hackerrank.com/contests/w32/challenges/fight-the-monsters
#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    double a,hit,t,n,i;
    long long int sum,sz,counter;
    cin >> n >> hit >> t;
    vector<double>vec;
    for(i=0;i<n;i++){
        cin >> a;
        //a = ceil(hit * ceil(a/hit));
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    sum = 0;
    sz = vec.size();
    counter = 0;
    for(i=0;i<sz;i++){
        if(vec[i] > hit){
            t = t- ceil(vec[i]/hit);
            if(t<0){
                break;
            }else{
                counter++;
            }

        }else{
            t--;
            counter++;
        }
        if(t<=0){
            break;
        }
    }

    /*
    for(i=0;i<sz;i++){
        sum = vec[i]+sum;
        vec[i] = sum;
    }
    for(i=0;i<sz;i++){
        if(vec[i] >=t*hit){
            break;
        }
    }*/

    cout << counter << endl;
    return 0;
}
