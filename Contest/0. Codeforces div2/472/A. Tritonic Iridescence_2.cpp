#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;



int main(){
    int i,j,u,v,n,sz,possible, finalFlag,l,r;
    string str;
    vector<int>vec;


    cin >> n;
    cin >> str;
    finalFlag = 0;
    if(n==1){
        if(str == "?"){
            cout << "Yes"<< endl;
            return 0;
        }else{
            cout << "No"<<endl;
            return 0;
        }
    }
    possible = 1;
    for(i=0;i< n-1;i++){
        if(str[i] == str[i+1] && str[i] != '?'){
            possible = 0;
            break;
        }
        if(str[i] == '?'){
            vec.push_back(i);
        }
    }
    if(possible == 1){
        if(str[i] == '?'){
            vec.push_back(i);
        }
        sort(vec.begin(), vec.end());
        sz = vec.size();
        if(vec[0] == 0 || vec[sz-1] == n-1){
            finalFlag = 1;
        }
        for(i=0;i<sz-1 && !finalFlag;i++){
            if(vec[i] +1 == vec[i+1]){
               // cc("1")
                finalFlag = 1;
                break;
            }
        }

        if(finalFlag == 0){
            l = str[vec[0]-1];
            r = str[vec[0]+1];
            if(l<r){
                swap(l,r);
            }
            for(i=0;i<sz;i++){
                u = str[vec[i]-1];
                v = str[vec[i]+1];
                if(u<v){
                    swap(u,v);
                }
                if( !(l == u && r == v) ){
                    finalFlag = 1;
                    break;
                }
            }
        }
        //msg("HI",finalFlag)
    if(finalFlag == 1){
        cout << "Yes"<< endl;
    }else{
        cout << "No"<<endl;
    }



    }else{
        cout << "No"<< endl;
    }





    return 0;
}
