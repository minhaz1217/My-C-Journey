#include<iostream>
using namespace std;
int main(){
    int n,bd=0,ww=0,caseCounter = 1,tk,i,temp,tie = 0;
    char a;
    cin >> tk;
    while(tk--){
    bd = 0;
    tie = 0;
    ww = 0;
    cin >> n;
    temp = n;
    for(i=0;i<temp;i++){
        cin >> a;
        if(a=='B'){
            bd++;
        }else if(a == 'W'){
            ww++;
        }else if(a == 'A'){
            n--;
        }else if(a== 'T'){
            tie++;
        }
    }
    if(n==0){
        cout << "Case " << caseCounter++ <<": ABANDONED" << endl;
    }else if(bd == n){
        cout << "Case " << caseCounter++ <<": BANGLAWASH" << endl;
    }else if(ww == n){
        cout << "Case " << caseCounter++ <<": WHITEWASH" << endl;
    }else if(bd==ww){
        cout << "Case " << caseCounter++ <<": DRAW " << bd << " " << tie << endl;
    }else if(bd > ww){
        cout << "Case " << caseCounter++ <<": BANGLADESH " << bd << " - " << ww <<endl;
    }else if(ww > bd){
        cout << "Case " << caseCounter++ <<": WWW " << ww << " - " << bd <<endl;
    }
    }

	return 0;
}
