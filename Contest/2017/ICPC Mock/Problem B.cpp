#include<iostream>
using namespace std;
int main(){
    int tc,cn,out,in,total =0,maximum =0,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> cn;
        maximum =0;
        total=0;
        cn--;
        while(cn--){
            cin >> in >> out;
            total -= out;
            total += in;
            if(total > maximum){
                maximum = total;
            }
        }
        cout << "Case " << caseCounter++ <<": "<< maximum << endl;
    }
	return 0;
}
