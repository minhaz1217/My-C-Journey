//UVALIVE - 7230


#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc, a,last,first,temp,flag,i;
    cin >> tc;
    while(tc--){
        cin >> a;
        int arr[a],arr2[a];
        temp =a;
        for(i=0;i<a;i++){
            cin >> arr[i];
            //cout << arr[i] << endl;
        }
        sort(arr, arr+a);
        flag = 1;
        first = 0;
        last = a-1;
        for(i=0;i<a;i++){
            if(flag == 1){
                arr2[first] = arr[i];
                first++;
                flag = 0;
            }else{
                arr2[last] = arr[i];
                last--;
                flag = 1;
            }
        }
        temp = 0;
        //cout << "CHECKING" << endl;
        for(i=1;i<a;i++){
            //cout << arr[i] << " ";
            temp = max(temp , abs(arr2[i] - arr2[i-1]) );
        }
        cout << temp << endl;
    }

    return 0;
}
