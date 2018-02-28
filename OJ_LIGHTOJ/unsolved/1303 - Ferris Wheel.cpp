#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    cin >> tc;
    while(tc--){
        cin >> n >> m;
        int arr[m+1], arr2[n+1][m+1];
        for(i=0;i<=n;i++){

            for(j=0;j<=m;j++){
                arr[i] = 0;
                arr2[i][j] = 0;
            }
        }

        queue<int>q;
        for(i=1;i<=n;i++){
            q.push(i);
        }
        curr = 1;
        while(1){
            if(curr > m){
                curr = 1;
            }
            if(arr[crrr] == 0 && !q.empty()){
                k = q.front();
                if(arr2[k] >= m)
                arr[curr] = q.front();
                q.pop();
            }else if(arr[curr]> 0){
                if(q.empty()){
                    q.push(arr[curr]);
                    arr[curr] = 0;
                }else{
                    q.push(arr[curr]);
                    arr[curr] = q.front();
                    q.pop();
                }
            }
            curr++;
            time += 5;


        }
    }

    return 0;
}
