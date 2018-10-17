#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define in freopen("army.in", "r", stdin);
#define out freopen("text.txt", "w", stdout);

vector<long long int>vec,vec2;



int main(){

    in
    //out
    vec.push_back(0);
    long long int sum,i=1, limit,n, tc,ans,ans2,limit2,caseCounter=1;
    sum = 0;
    vec2.push_back(0);
    while(sum <= 1000000000100000000){
        sum += (i*i);
        vec.push_back(sum);
        vec2.push_back(vec2[i-1]+i);
        i++;
    }

    cin >> tc;
    while(tc--){
        cin >>n;
        limit = lower_bound(vec.begin(), vec.end(), n) - vec.begin();
        n = n - vec[limit-1];
        ans = (limit-1) * (limit-1);
        if(vec2[limit] >= n){
            limit2 = lower_bound(vec2.begin(), vec2.end(), n)- vec2.begin();
            ans += limit2;
            cout << "Case "<< caseCounter++ << ": " << ans<<endl;
        }else{

            n = n - vec2[limit];
            ans =ans+ limit;
            i = limit-1;

            n = vec2[limit-1]-n;
            limit2 = upper_bound(vec2.begin(), vec2.end(), n)-vec2.begin();
            //msg(n, limit2)
            ans2 = (limit-1)-(limit2-1);
            ans = ans + ans2;

            cout << "Case "<< caseCounter++ << ": " << ans<<endl;


        }



    }

    return 0;
}
