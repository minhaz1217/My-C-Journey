#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

#define MAX 1001
int main(){
    int arr[MAX] = {0}, arr2[MAX], i,j,x,tc,f,s, caseCounter =1;
    int sorted[MAX];
    for(i=1;i<MAX;i++){
        arr2[i] = i;
        for(j=1;j<MAX;j++){
            if(i%j == 0){
                arr[i]++;
            }
        }
    }
    for(i=2;i<MAX;i++){
        for(j=i+1;j<MAX;j++){
            f = arr[i];
            s = arr[j];
            if(s < f){
                swap(arr[i], arr[j]);
                swap(arr2[i], arr2[j]);
            }else if(f == s && j > i){
                swap(arr[i], arr[j]);
                swap(arr2[i], arr2[j]);
            }
        }
    }
    cin >> tc;
    while(tc--){
        cin >> x;
        cout << "Case "<< caseCounter++ << ": ";
        cout << arr2[x] << endl;
    }
    return 0;
}
