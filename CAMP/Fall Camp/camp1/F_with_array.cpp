#include<iostream>
using namespace std;
int main(){
    int N,Q, q,x,y,lastAns = 0, md,i;
    cin >> N >> Q;
    int arr[N][Q] = {0}, arrSize[N] = {0};
    /*
    for(i=0;i<N;i++){
        cout << arr[i][1] << endl;
    }
    */

    while(Q--){
        cin >> q >> x >> y;
        if(q == 1){
            md = (x^lastAns)%N;
            arr[md][arrSize[md]++] = y;
        }else if(q == 2){
            md = (x^lastAns)%N;
            lastAns = arr[md][y % arrSize[md]];
            cout << lastAns << endl;
        }
    }

    return 0;
}
