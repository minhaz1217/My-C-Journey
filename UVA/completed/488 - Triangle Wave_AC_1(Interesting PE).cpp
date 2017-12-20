//UVA-488
#include<iostream>
using namespace std;
int main(){
    int a,m,f,i,j,temp,t;
    cin >> a;
    for(t=1;t<=a;t++){
        cin >> m>>f;
        for(i=1;i<=f;i++){
            for(j=1;j<=m;j++){
                temp=j;
                while(temp--){
                    cout << j;
                }
                cout << endl;
            }
            for(j=m-1;j>=1;j--){
                temp=j;
                while(temp--){
                    cout << j;
                }
                cout << endl;
            }
            if(t==a && i==f){

            }else{
            cout << endl;
            }
        }
    }
	return 0;
}
