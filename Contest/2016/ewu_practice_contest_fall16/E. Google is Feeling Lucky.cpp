#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc, arrRank[10], currentBig = 0,i,caseCounter = 1;
    string str[10];
    cin >> tc;
    while(tc--){
        currentBig = 0;
        for(i=0;i<10;i++){
            cin >> str[i] >> arrRank[i];
            if(arrRank[i] >= currentBig){
                currentBig = arrRank[i];
            }
        }
        cout << "Case #" << caseCounter++ << ":" << endl;
        for(i=0;i<10;i++){
            if(arrRank[i] == currentBig){
                cout << str[i] << endl;
            }
        }

    }
	return 0;
}
