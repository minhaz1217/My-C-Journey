#include<iostream>
using namespace std;
int main(){
    int i,j,n,q,flag =0,caseCounter=1,temp;
    for(;;){
        cin >> n >> q;
        if(n==0 && q==0){
            break;
        }
        int mar[n+1],qrr[q];
        for(i=1;i<n+1;i++){
            cin >> mar[i];
        }
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(mar[j]<mar[i]){
                    temp = mar[i];
                    mar[i] = mar[j];
                    mar[j] = temp;
                }
            }
        }
        cout << "CASE# " << caseCounter++ <<":"<< endl;
        for(i=0;i<q;i++){
            cin >> qrr[i];
            flag = 0;
            for(j=1;j<=n;j++){
                if(qrr[i] == mar[j]){
                    flag = 1;//found it
                    break;
                }
            }
            if(flag == 1){
                cout << qrr[i] << " found at " << j << endl;
            }else{
                cout << qrr[i] << " not found" << endl;
            }
        }
    }

	return 0;
}
