#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n;
    string str1,str2;
    cin >> n;
    cin >> str1 >> str2;
    long long int counter00 = 0 , counter01 =0 , counter11=0, counter10=0, counter1 =0 , counter0 = 0;
    for(int i=0;str1[i];i++){
        if(str1[i] == '0' && str2[i] == '0'){
            counter00++;
        }else if(str1[i] == '1' && str2[i] == '0'){
            counter10++;
        }else if(str1[i] == '1' && str2[i] == '1'){
            counter11++;
        }else{
            counter01++;
        }

        if(str1[i] == '1'){
            counter1++;
        }
        if(str1[i] == '0'){
            counter0++;
        }
    }
    //msg2(counter01, counter10, counter1)
    cout << counter00*counter11 + counter01*counter10 + counter00 * counter10<< endl;
    return 0;
}
