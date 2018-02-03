#include<iostream>
#include<queue>
using namespace std;
int main(){
    long long caseCounter= 1,tc,a,u,v,founder;
    cin >> tc;
    while(tc--){
        queue<pair<int, int> > q;
        cin >> a;
        q.push(make_pair(a, 0));
        int arr[a+2] = {0};
        arr[a] = 1;
        //cout << a << endl;
        founder = 5000000;
        while(!q.empty()){
            u = q.front().first;
            v = q.front().second;
            q.pop();
            //msg(u,v)
            if(u==1){
                founder = min(founder,v);
                break;
                //break;
            }
            if(u>1){
            if(u-1 == 1){
                founder = v+1;
                break;
            }else{
                if(!arr[u-1]){
                q.push(make_pair(u-1, v + 1));
                arr[u-1] = 1;
                }
            }
            if(u%3 == 0 && !arr[u/3]){
                if(u/3 == 1){
                    founder = v+1;
                    break;
                }else{
                    q.push(make_pair(u/3, v + 1));
                    arr[u/3] = 1;
                }
            }
            if(u%2 == 0 && !arr[u/2]){
                if(u/2 == 1){
                    founder = v+1;
                    break;
                }else{
                    q.push(make_pair(u/2, v + 1));
                    arr[u/2] = 1;
                }
            }
            }
        }
        cout << "Case " << caseCounter++ << ": " << founder << endl;
        //cout << founder << endl;

    }

    return 0;
}
