#include<bits/stdc++.h>
using namespace std;
int main(){
    long long i,counter = 0,tc;
    string str;
    char prev;
    cin >> tc;
    cin >>str;
    prev = str[0];
    for(i=1;str[i];i++){
        if(str[i] == prev){
            counter++;
        }
        prev = str[i];
    }
    cout << counter << endl;
	return 0;
}
