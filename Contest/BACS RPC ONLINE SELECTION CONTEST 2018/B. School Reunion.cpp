#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int tc,caseCounter = 1;
    scanf("%d", &tc);
    while(tc--){
        int n,p,i,sz;
        long long int a,b,mMin;
        scanf("%d%d", &n,&p);
        vector<pair<long long int, long long int> >vec;
        for(i=0;i<n;i++){
            cin >> a >> b;
            vec.push_back(make_pair(b,a));
        }
        sort(vec.begin(),vec.end());
        mMin = INT_MAX;
        sz =vec.size();
        for(i=0;i<=sz-p;i++){
            //msg(vec[i].first, vec[i].second);
            if(vec[i].first >= vec[i+p-1].second){
                mMin = 0;
            }
            mMin = min(mMin, abs(vec[i].first - vec[i+p-1].second));
            //cc(mMin)
        }
        printf("Case %d: %lld\n",caseCounter++, mMin);

    }

    return 0;
}
