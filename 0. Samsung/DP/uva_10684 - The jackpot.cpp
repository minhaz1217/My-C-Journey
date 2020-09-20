#include<iostream>
using namespace std;

int arr[10005],n;
int kadanes(){
    long long int currMax = 0, totalMax = 0;
    for(int i=0;i<n;i++){
//        if(arr[i] < 0){
//            totalMax = max(totalMax , currMax);
//            currMax = 0;
//        }
        if(currMax + arr[i] >= 0){
            currMax = currMax + arr[i];
            totalMax = max(totalMax , currMax);

        }else{
            totalMax = max(totalMax , currMax);
            currMax = 0;
        }
//        cout << " " << currMax << " ";
    }
    totalMax = max(totalMax , currMax);
    return totalMax;
}

int main(){
    while(1){
        cin >> n;
        if(n ==0){
            break;
        }
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
    long long int ans = kadanes();
        if(ans <= 0){
            cout << "Losing streak." << endl;
        }else{
            cout << "The maximum winning streak is " << ans << "." << endl;
        }
    }
    return 0;
}
