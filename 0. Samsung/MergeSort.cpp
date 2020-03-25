#include<iostream>
using namespace std;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
int arr[100];
int merge(int l, int r){
    int mid = (l+(r-l)/2), n1 = mid-l + 1, n2 = r-mid;
//    msg2(l,r,mid)
    int i=0,j=0,k=0;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int i = 0;i<n2;i++){
        R[i] = arr[i+mid+1];
    }
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        k++,i++;
    }
    while(j<n2){
        arr[k] = R[j];
        k++,j++;
    }
}
int margeSort(int l, int r){
//    msg(l,r);
    if(r>l){
        int mid = l + (r-l)/2.0;
        margeSort(l, mid);
        margeSort(mid+1, r);
        merge(l, r);
    }
}


int main(){
    for(int i=0;i<10;i++){
        arr[i] = (rand()) %100;
    }
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    margeSort(0,9);
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
