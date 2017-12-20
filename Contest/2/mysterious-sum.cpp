#include<iostream>
using namespace std;
int main(){
    int a,b,c,caseCounter =1,temp;
    cin >> a;
    while(a--){
        cin >> b >> c;
        cout << "Case " << caseCounter << ": " << (b+c) << (b-c) << endl;
        caseCounter++;
    }

	return 0;
}
