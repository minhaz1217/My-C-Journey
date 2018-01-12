#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i,j,a,l,r,len,biggest = 0,lCounter =1, currentBiggest =0,caseCounter =1;
    cin >> a;
    while(a--){
        biggest = 0;
        cin >> l >> r;
        cin >> len;
        int arr[len+1];
        for(i=0;i<len;i++){
            cin >> arr[i];
        }
        for(i=l;i<=r;i++){
            lCounter = 1;
            for(j=1;j<=l/2;j++){
                if(i%j == 0){
                    lCounter++;
                }
            }
            if(arr[lCounter] > biggest){
                currentBiggest = i;
                biggest = arr[lCounter];
            }

        }
        cout << "Case " << caseCounter++ <<": " << currentBiggest<< endl;

    }

	return 0;
}
