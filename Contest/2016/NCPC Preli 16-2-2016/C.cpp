#include<iostream>
using namespace std;
int main(){
    long long tc,n,r,counter = 0,i,caseCounter = 1;
    char ch;
    cin >> tc;
    while(tc--){
        cin >> n >> r;
        counter = 0;
        long long arr1[n];
        char arr2[n];
        for(i=0;i<n;i++){
            cin >> arr1[i];
        }
        for(i=0;i<n;i++){
            cin >> arr2[i];
        }
        for(i=0;i<n;i++){

            if(arr2[i] == arr2[i+1]){
                arr1[i+1] += arr1[i];
                continue;
            }
                //testing corner
                if(arr1[i] <=r){
                    counter++;
                    arr1[i+1] = arr1[i+1]-r;
                }else{
                    while(arr1[i] > r){
                        arr1[i] = arr1[i] - r*2;
                        counter++;
                    }
                    if(arr1[i] >0){
                        counter++;
                        arr1[i+1] -= r;
                    }
                }
        }




        cout<<"Case "<< caseCounter++ << ": " << counter<< endl;
    }

    return 0;
}
