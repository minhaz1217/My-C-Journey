#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    int tc,i,k,counter, big,index;
    string str1,str2;
    cin >> tc;
    while(tc--){
        map<string, int>mp;
        map<int, string>mp2;
        vector<int>vec;
        vec.push_back(-1);
        counter = 1;
        cin >> k;
        while(k--){
            cin >> str1 >> str2;
            if(!mp[str2]){
                mp[str2] = counter++;
                mp2[counter-1] = str2;
                vec.push_back(0);
            }
            vec[mp[str2]]++;
        }
        big = INT_MIN;
        for(i=1;i<vec.size();i++){
            //msg(i,vec[i])
            if(big < vec[i]){
                big  = vec[i];
                index = i;
            }
        }
       // msg(index, big)
        cout << mp2[index] << endl;

    }
    return 0;
}
