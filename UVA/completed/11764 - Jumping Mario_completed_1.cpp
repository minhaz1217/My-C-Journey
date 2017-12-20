#include<iostream>
using namespace std;
int main(){
    int tk,n,prev,cur,lj=0,sj=0,caseCounter = 1,i;
    cin >> tk;
    while(tk--){
        cin >> n;
        if(cin.eof()){
            break;
        }
        lj=0;
        sj = 0;
        for(i=0;i<n;i++){
            cin >> cur;
            if(i!=0){
                if(cur > prev){
                    lj++;
                }else if(cur < prev){
                    sj++;
                }
            }
            prev = cur;
        }
        cout << "Case " << caseCounter++ << ": " << lj << " " << sj << endl;
    }

	return 0;
}
