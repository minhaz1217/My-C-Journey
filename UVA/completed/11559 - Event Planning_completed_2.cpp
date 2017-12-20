#include<iostream>
using namespace std;
int main(){
    int n,b,h,w,mCost = 0,i,j;
    for(;;){
        cin >> n >> b >> h >> w;
        if(cin.eof()){
            break;
        }
        mCost = b+20;
        int hot[h][w+1];
        for(i=0;i<h;i++){
            for(j=0;j<w+1;j++){
                cin >> hot[i][j];
                if(j!=0 && hot[i][j]>=n && hot[i][0]*n <= b){
                    if(hot[i][0]*n <= mCost){
                        mCost = hot[i][0]*n;
                    }
                }
            }
        }
        if(mCost <= b){
            cout << mCost << endl;
        }else{
            cout << "stay home" << endl;
        }
    }

	return 0;
}
