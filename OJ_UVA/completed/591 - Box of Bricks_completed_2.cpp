#include<iostream>
using namespace std;
int main(){
    int n,sum=0,i,avg,caseCounter = 1;
    for(;;){
        cin >> n;
        if(n==0){break;}
        int arr[n];
        sum = 0;
        for(i=0;i<n;i++){
            cin >> arr[i];
            sum+=arr[i];
        }
        avg = sum/n;
        sum = 0;
        for(i=0;i<n;i++){
            if(arr[i] < avg){
                sum += avg - arr[i];
            }
        }
        cout << "Set #" << caseCounter++ << endl <<"The minimum number of moves is " << sum <<"." << endl<<endl;

    }
    return 0;
}
