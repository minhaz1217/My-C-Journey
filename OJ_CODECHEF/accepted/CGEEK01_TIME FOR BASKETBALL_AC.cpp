#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,i,j,a,k,n,counter = 0;
    string str;
    cin >> tc;
    while(tc--){
        cin >> a;
        queue<int>q;
        int arr[a+1];
        for(i=1;i<=a;i++){
            cin >> k;
            q.push(k);
            arr[i] = k;
        }
        cin >> str;
        cin >>n;
        counter = 0;
        for(i=0;str[i];i++){
            if(str[i] == '1'){
                counter++;
            }
            if(counter == 3){
                break;
            }
        }
        i = i%a;
        for(j=1;j<=i;j++){
            k = q.front();
            q.pop();
            q.push(k);
        }
        for(i=1;i<=n;i++){
            q.pop();
        }
        cout << q.front() << endl;



    }

    return 0;
}
