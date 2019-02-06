#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    long long int n,a,sum;
    vector<long long int>vec;
    cin >> n;
    sum = 0;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
        sum += a;
    }
    sort(vec.begin(),vec.end());
    queue< pair<int>, vector<int> > q;
    for(int i=vec.size()-1;i>=0;i--){
        a = vec[i];

        q.push_back(make_pair(a,vec));

        while(!q.empty()){
            sum = q.first();
        `   vector<int>myVec = q.second();
            for(int j=myVec.size()-1;j>=0;j--){
                if(sum + myVec[j] < 360 && myVec[j] != 0){
                    myVec[j] = 0;
                    q.push( sum+myVec[j], myVec );
                }
            }
        }
    }

    return 0;
}
