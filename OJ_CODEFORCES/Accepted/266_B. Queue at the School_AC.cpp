#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long n,t,i,j;
    string str;
    cin >> n >> t;
    cin >> str;
    for(j=1;j<=t;j++){
        for(i=0;str[i];i++){
            if(str[i]=='B' && str[i+1] == 'G'){
                str[i+1] = 'B';
                str[i] = 'G';
                i++;
            }
        }
    }
    cout << str << endl;
	return 0;
}
