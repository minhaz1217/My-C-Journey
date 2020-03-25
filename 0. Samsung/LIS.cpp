#include<iostream>
using namespace std;

#define MX 504
int arr[MX];
int d[MX],n,p[MX];
int LIS(){
    for(int i=0;i<n;i++){
        d[i] = 0;
        p[i] = -1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && d[i]< d[j]+1){
                p[i] = j;
                d[i] = max(d[i], d[j]+1);

            }
        }
    }
    int mx = d[0], pos = 0;
    for(int i=0;i<n;i++){
        if(d[i]>mx){
            d[i] = mx;
            pos = i;
        }
    }

    while(pos!=-1){
        cout << arr[pos] << " ";
        pos = p[pos];
    }
    cout <<  endl;
}

int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    LIS();
    for(int i=0;i<n;i++){
        cout << d[i]  << " ";
    }
    cout << endl;
    return 0;
}
