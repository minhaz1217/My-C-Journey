#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long tc,n,q,i,m,a,b,temp1,temp2;

    cin >> tc;
    while(tc--){
        cin >> n >> q;
        long long int arr[n+1];
        for(i=0;i<n;i++){
            cin >> arr[i];
        }

        while(q--){
            cin >> a >> b;
            m = n/2;
            while(m > 0 && m<n){
                check(m)
                if(arr[m] > a){
                    if(m-1 >=0 && arr[m-1] < a){
                        temp1 = m;
                        break;
                    }
                    m= m/2;
                }else if(arr[m] < a){
                    if(m+1 < n && arr[m+1] > a){
                        temp1 = m;
                        break;
                    }
                    m = (n + m) /2;
                }else{
                    temp1 = m;
                    break;
                }
            }

            m = n/2;
            while(m >=0 && m<n){
                    check(m)
                if(arr[m] > b){
                    if(m-1 >=0 && arr[m-1] < b){
                        temp2 = m;
                        break;
                    }
                    m= m/2;
                }else if(arr[m] < b){
                    if(m+1 < n && arr[m+1] > b){
                        temp2 = m;
                        break;
                    }
                    m = (n + m) /2;
                }else{
                    temp2 = m;
                    break;
                }
            }
            msg(temp1, temp2)

        }



    }

    return 0;
}
