#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,counter=0;
    string str1,str2;
    //cin >> n;
    cin >> str2 >> str1;
    bitset<32> s1(str1), s2(str2);
    bitset<32> s3,temp;
    s3 = s1|s2;
    n = str1.size();

    int t;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            temp = s2;
            t = temp[j];
            temp[j] = temp[i];
            temp[i] = t;
            if( (s1|temp) != s3){
                counter++;
                msg(i+1,j+1)
            }
        }
    }
    cout << counter << endl;
    return 0;
}
