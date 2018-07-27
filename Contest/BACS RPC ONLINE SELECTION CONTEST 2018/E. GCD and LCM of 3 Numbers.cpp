#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

vector<long long int>divisor[104];

void populateDiv(long long int n, int pos){
    //msg("HI", n)
    int sq,i;
    sq = sqrt(n) +1;
    for(i=1;i<=sq;i++){
        if(n%i == 0){
            if(n/i == i){
                divisor[pos].push_back(i);
            }else{
                divisor[pos].push_back(i);
                divisor[pos].push_back(n/i);
            }
        }
    }
    //sort(divisor[pos].begin(), divisor[pos].end());
}


int main(){

    long long int gc,tc,mapCounter = 1,f,g,a,b,c,n,sz,counter, pos,i,j,mul,arr[3];
    cin >> tc;
    mapCounter = 1;
    map<long long int, long long int>mp;
    while(tc--){
        cin >> f >> g;

        map<pair<long long int, pair<long long int, long long int> >, int>myMp;

        n = f*g;
        mul = f*g;
        if(!mp[n]){
            mp[n] = mapCounter++;
            populateDiv(n,mp[n]);
        }
        pos = mp[n];
        sz = divisor[pos].size();
        counter = 0;
        /*
        cc("DIV")
        for(i=0;i<sz;i++){
            cout << divisor[pos][i] << " ";
        }
        cout << endl << endl;
        */

        for(i=0;i<sz;i++){
            for(j=0;j<sz;j++){
                a = divisor[pos][i];
                b = divisor[pos][j];
                if( mul%(a*b) == 0 && mul >= a*b){
                    c = mul/(a*b);
                    gc = __gcd(a,__gcd(b,c));
                    if(gc == g){
                        counter++;
                        arr[0] = a;
                        arr[1] = b;
                        arr[2] = c;
                        sort(arr, arr+3);

                        a  =arr[0];
                        b  =arr[1];
                        c  =arr[2];
                        if(!myMp[make_pair(a, make_pair(b,c))]){
                            myMp[make_pair(a, make_pair(b,c))] = 1;
                        }

                    }
                }
            }
        }
        //msg("ANS: ", counter)
        //msg("ANS: ", myMp.size())
        cout << myMp.size() << endl;

    }

    return 0;
}
