#include<iostream>
#include<vector>
using namespace std;
int main(){
    long int tc,qCount, qType,i,j,pID,rID;
    vector<long int> vec;
    cin >> tc;
    while(tc--){
        cin >> qCount;
        long int pid[qCount][qCount];

        for(i=0;i<qCount-1;i++){
            for(j=0;j<qCount-1;j++){
              pid[i][j] = -1;
            }
        }
        cout << "ASSIGNED" << endl;
        /*
        for(i=0;i<qCount;i++){
            cin >> qType;
            if(qType == 1){
                cin >> pID >> rID;
                for(j=0;j<=i;j++){
                }
            }else if(qType == 2){

            }
        }
        */

    }







	return 0;
}
