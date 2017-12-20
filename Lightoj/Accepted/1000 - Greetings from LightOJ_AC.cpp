#include<iostream>
using namespace std;
int main(){
    int tc,a,b,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        cout << "Case " << caseCounter++ <<": " << (a+b) << endl;
    }
	return 0;
}
