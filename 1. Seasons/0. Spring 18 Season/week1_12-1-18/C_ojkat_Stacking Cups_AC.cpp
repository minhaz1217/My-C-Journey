#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n,i,j;
    string a,b;
    char *p;
    cin >> n;
    int arr[n+1];
    string arr2[n+1];
    for(i=0;i<n;i++){
        cin >> a >> b;
        if(strtoll(a.c_str(), &p, 10) == 0){
            arr[i] = strtoll(b.c_str(), &p, 10);
            arr2[i] = a;
        }else{
            arr[i] = strtoll(a.c_str(), &p, 10)/2;
            arr2[i] = b;
        }
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i] >= arr[j]){
                swap(arr[i], arr[j]);
                swap(arr2[i], arr2[j]);
            }
        }
    }
    for(i=0;i<n;i++){
        cout << arr2[i] << endl;
    }

    return 0;
}
