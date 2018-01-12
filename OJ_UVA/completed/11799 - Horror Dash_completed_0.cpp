#include<iostream>
using namespace std;
int main(){
    int tk,n,num,big = 0,caseCounter = 1;
    cin >> tk;
    while(tk--){
        cin >> n;
        big = 0;
        while(n--){
            cin >> num;
            if(num>big){
                big = num;
            }
        }
        cout << "Case " << caseCounter++ << ": "<<big << endl;
    }

	return 0;
}
