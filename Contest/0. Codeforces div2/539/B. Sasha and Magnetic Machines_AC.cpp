#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int mark[105];
int main(){
    int flag;
    for(int i=0;i<105;i++){
        flag = 1;
        mark[i] = 1;
        for(int j=2;j<=i;j++){
            if(i%j == 0 && i!=j){
                flag = 0;
                mark[i] = 0;
                break;
            }
        }
    }

    int exceptPrimeFound,currMin,root,sum,sum2,myFound,myFoundIndex,n,a,found;
    vector<int>vec;
    cin >> n;
    sum = 0;
    exceptPrimeFound  =0;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
        if(mark[a] == 0){
            //msg("FOUND", a)
            exceptPrimeFound = 1;
        }
        sum += a;
    }
    //cc(exceptPrimeFound)
    if(exceptPrimeFound ){
        found = 0;
        currMin = sum;
        sort(vec.begin(),vec.end());
        for(int i=vec.size()-1;i>=0 && !found ;i--){
            if(mark[vec[i]] == 0){
                root = sqrt(vec[i]);
                for(int j=2;j<=root;j++){
                    if(vec[i]%j == 0){
                        sum2 = sum - (vec[i]+vec[0]) + (vec[0]*j + vec[i]/j);
                        currMin = min(currMin, sum2);
                    }
                }
            }
        }
        //sum2 = sum + (vec[0]*myFound) + (vec[myFoundIndex]/myFound) - vec[myFoundIndex] - vec[0];
        //msg2(sum, sum2,myFound)
        cout << currMin << endl;
        /*
        if(sum2 < sum){
            cout << sum2 << endl;
        }else{
            cout << sum << endl;
        }
        */
    }else{
        cout << sum << endl;
    }

    return 0;
}
