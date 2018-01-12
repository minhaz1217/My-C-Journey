#include<iostream>
using namespace std;
int main(){
    long long tc,counter,i,j,n;
    cin >> n;
    while(n--){
        cin >> tc;
        counter = 0;
        long long arr[tc];
        for(i=0;i<tc;i++){
            cin >> arr[i];
        }
        if(cin.eof()){
            break;
        }
        for(i=0;i<tc-1;i++){
            for(j=0;j<tc-i-1;j++){
                if(arr[j+1] < arr[j]){
                    swap(arr[j+1], arr[j]);
                    counter++;
                }
            }
        }
        cout << "Optimal train swapping takes " << counter <<" swaps."<< endl;



    }



    return 0;
}
