#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long unsigned int m, arr[7],temp;
    int tc,n,counter = 0,i,j;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        int total=0;
        for(i=0;i<n;i++){
            cin >> arr[i];
            total+=arr[i];
        }
        if(total<m){
            cout<<-1<<endl;
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
        while(m>0){
            m-=arr[n-1];
            n--;
            counter++;
        }

        cout << counter << endl;
    }


    return 0;
}
