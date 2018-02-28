#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
int main(){
    int ta=1,firstPosition = 1,tc,n,i,temp, notSorted,counter;
    string str;
    cin >> tc;
    while(tc--){
        vector<string>mainInput;
        map<string,int>mp;
        vector<int> sorted,vec,result;

        mainInput.push_back("-1");
        sorted.push_back(-1);
        vec.push_back(-1);
        cin>> n;
        cin.ignore();
        int mtime[n+4];


        for(i=1;i<=n;i++){
            getline(cin, str);
            mp[str] = i;
            mainInput.push_back(str);
            vec.push_back(i);
        }
        for(i=1;i<=n;i++){
            getline(cin,str);
            sorted.push_back(mp[str]);
        }
        notSorted = 1;
        counter = 0;
        while(notSorted){
            for(i=vec.size()-1;i>=firstPosition;i--){
                if(sorted[i] != vec[i]){
                    temp = vec[i];
                    vec.erase(vec.begin()+i);
                    vec.insert(vec.begin()+firstPosition, temp);

                    mtime[temp] = counter++;
                    result.push_back(temp);
                    //display(sorted);
                    //display(vec);
                    break;
                }
                if(vec == sorted){
                    notSorted = 0;
                    break;
                }
            }
        }
        if(ta > 1){
            cout << endl;
        }
        ta++;
        for(i=0;i<result.size();i++){
            if(mtime[result[i]] == i){
                cout << mainInput[result[i]] << endl;
            }
        }

    }
    cout << endl;



    return 0;
}
