#include<iostream>
using namespace std;
int main(){
    int n,x,y,flag = 0;
    for(;;){
        cin >> n;

        if(n==0){
            break;
        }

        flag = 0;
        for(y=1;y<=n/2;y++){
            for(x=1;x<=n/2;x++){
                if((x*x*x - y*y*y) == n){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
        }
        if(flag == 1){
            cout << x << " " << y << endl;
        }else{
            cout << "No solution" << endl;
        }
    }
	return 0;
}
