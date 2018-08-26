#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int tc,sz,n,a,sum,first,second,currMin,ans;
    cin >> tc;

    while(tc--){
    vector<long long int>vec, vec2,vec3,finalVec;
    map<long long int , int > mp;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a;
            vec.push_back(a);
        }
        sz = vec.size();
        sort(vec.begin(), vec.end());
        currMin = INT_MAX;
        for(int i=0;i<sz-1;i++){
            if(vec[i] == vec[i+1] && !mp[vec[i]]){
                //mp[vec[i]] = 2;
                vec2.push_back(vec[i]);
                vec2.push_back(vec[i]);
                i++;
            }
        }
        for(int i=0;i<vec2.size()-3;i++){
            sum = 0;
            first = 0;
            second = 0;
            vec3.clear();
            //msg(i, vec2.size())
            for(int j=i;j<i+4;j++){
                sum += vec2[j];
                //msg(j, vec2[j])
                vec3.push_back(vec2[j]);
            }
            first = vec2[i+1]*vec2[i+2];
            ans = sum*sum / first;
            if(ans < currMin){
                //msg(ans, currMin)
                finalVec = vec3;
                currMin = ans;
            }
        }
        for(int i=0;i<finalVec.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << finalVec[i];
        }
        cout << endl;
    }
    return 0;
}
