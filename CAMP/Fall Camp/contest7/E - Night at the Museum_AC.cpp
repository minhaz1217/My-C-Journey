


#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    string str;
    char temp;
    int curr, i,sum = 0,ci,tt;
    cin >> str;
    curr = 1;
    sum = 0;
    for(i=0;str[i];i++){
        temp = str[i];
        ci = temp - 'a' + 1;
        //msg(temp, ci)
        tt = min( abs(curr - ci), min( abs( curr + 26 - ci ), abs( 27-curr + ci-1) ));
        //msg("SUM: ", tt)
        sum += tt;
        curr = ci;
    }
    cout << sum << endl;


    return 0;
}
