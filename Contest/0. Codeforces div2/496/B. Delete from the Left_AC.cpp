#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    string str1, str2;
    int sz1,sz2, counter = 0, ans;
    cin >> str1 >> str2;
    sz1 = str1.size() - 1;
    sz2 = str2.size() - 1;
    while(1){
        if(sz1 < 0 || sz2<0){
            break;
        }
        if(str1[sz1] == str2[sz2]){
            counter++;
        }else{
            break;
        }
        sz1--;
        sz2--;
    }
    sz1 = str1.size();
    sz2 = str2.size();
    //msg(sz1, sz2)
    //cc(counter)
    if(counter == sz1){
        ans = sz2 - counter;
    }else if(counter == sz2){
        ans = sz1 - counter;
    }else{
        ans = (str1.size() + str2.size()) - 2*counter;
    }

    cout << ans << endl;

    return 0;
}
