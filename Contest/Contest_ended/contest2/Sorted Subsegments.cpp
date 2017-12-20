//https://www.hackerrank.com/contests/101hack38/challenges/sorted-subsegments
#include<iostream>
using namespace std;
int main(){
    int n,q,k,i,j,a,temp;
    cin >> n >> q >> k;
    int num[n], qrr[q][2];
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    for(i=0;i<q;i++){
        cin >> qrr[i][0] >> qrr[i][1];
    }
    for(a=0;a<q;a++){
        for(i=qrr[a][0];i<=qrr[a][1];i++){
            for(j=i+1;j<=qrr[a][1];j++){
                if(num[i] > num[j]){
                    temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }
            }
        }
    }
    cout << num[k] << endl;
}
