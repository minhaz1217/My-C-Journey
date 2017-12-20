#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int m, arr[7],temp,total = 0;
    int tc,n,counter = 0,i,j;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        total = 0;
        for(i=0;i<n;i++){
            cin >> arr[i];
            total += arr[i];
        }
        if(total < m){
            cout << -1 << endl;
            break;
        }else if(total == m){
            cout << n << endl;
            break;
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(arr[j] < arr[i]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        counter = 0;
        for(i=n-1;i>=0;i--){
            counter++;
            m = m - arr[i];
            if(m <= 0){
                break;
            }
        }
        cout << counter << endl;
    }
	return 0;
}
