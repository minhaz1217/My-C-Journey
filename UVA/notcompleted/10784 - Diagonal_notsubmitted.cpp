#include<iostream>
#include<cmath>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    // my input says there is at least 1 diagonal line in 2-gon.
    int rnum,num = 6,sum=0,counter = 1,i,j,caseCounter = 1;
    for(;;){
        cin >> rnum;
        if(rnum==0){break;}
        for(j=1;j<=rnum;j++){
            counter = 1;
            num = j;
            sum = (num-3) + ((num-3)*(num-2)/2);
            if(sum >= rnum){
                break;
            }
        }
        cout << "Case " << caseCounter++ <<": "<<j << endl;
    }

	return 0;
}
