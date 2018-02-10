#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 1005

int visited[MX];
int mat[MX][MX];
int place[MX];
int arr[MX];


int main(){
    int tc,k,n,m,i,j,u,v,caseCounter = 1,mm,counter;
    map<int, int> mp;
    queue<int> q;
    cin >> tc;
    while(tc--){
        cin >> k >> n >> m;
        mp.clear();
        //q.clear();
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j] = 0;
            }
            visited[i] = 0;
            place[i] = 0;
            arr[i] = INT_MAX;
        }



        for(i=0;i<k;i++){
            cin >> arr[i];
        }
        for(i=0;i<m;i++){
            cin >> u >> v;
            mat[u][v] = 1;
        }
        sort(arr, arr+k);
        for(i=0;i<k;i++){

            for(j=0;j<=n;j++){
                visited[j] = 0;
            }
            if(!visited[arr[i]]){
                q.push(arr[i]);
                //mp[arr[i]] = 1;
                visited[arr[i]]++;
                place[arr[i]]++;
                while(!q.empty()){
                    u = q.front();
                    q.pop();
                    for(j=1;j<=n;j++){
                        if(!visited[j] && mat[u][j]){
                            q.push(j);
                            visited[j]++;
                            place[j]++;
                        }
                    }
                }
            }
        }
        /*
        for(i=0;i<=n;i++){
            cout << place[i] << " ";
            //cout << arr[i] << " ";
        }
        cout << endl;
        */
        sort(place, place+n+1);
        //cout << place[n] << endl;
        mm = place[n];
        counter = 0;
        for(i=n;i>=0;i--){
            if(place[i]!=mm){
                break;
            }
            counter++;
        }
        cout << "Case "<< caseCounter++ << ": " << counter << endl;


    }


    return 0;
}
