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
    _INIT;

    long long int n,k,a,prev, st,counter,sum=0;
    string str;
    vector<long long int>vec;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    cin >> str;
    prev = str[0];
    st = 0;
    counter =1;
    for(int i=1;str[i];i++){
        if(str[i] != prev){
            if(counter > k){
                sort(vec.begin()+st, vec.begin()+st+counter);
                if(k == 1){
                    sum += vec[i-1];
                }else{
                    for(int j=i-k;j<=i-1;j++){
                        sum += vec[j];
                    }
                }
            }else{
                if(counter == 1){
                        //cc("HI")
                    sum += vec[st];
                }else{
                    for(int j=st;j<=st+counter-1;j++){
                        sum += vec[j];
                    }
                }
            }
            prev = str[i];
            st = i;
            counter =1;
        }else{
            counter++;
        }
        //msg(i, sum)
    }
    //msg(counter, sum)
    if(counter > k){
        sort(vec.begin()+st, vec.begin()+st+counter);
        if(k == 1){
            sum += vec[n-1];
        }else{
            for(int j=n-k;j<=n-1;j++){
                sum += vec[j];
            }
        }
    }else{
        if(counter == 1){
                //cc("HI")
            sum += vec[st];
        }else{
            for(int j=st;j<=st+counter-1;j++){
                sum += vec[j];
            }
        }
    }
/*
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
*/
    cout << sum << endl;

    return 0;
}
