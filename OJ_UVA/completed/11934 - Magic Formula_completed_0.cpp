#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,l,x,counter = 0;
    for(;;){
        cin >> a >> b >> c >> d >> l;

        if(a==0 && b ==0 && c ==0 && d==0 && l==0 ){
            break;
        }

        for(x=0;x<=l;x++){
            if((a*x*x + b*x + c)%d == 0){
                counter++;
            }
        }
        cout << counter;
    }
	return 0;
}
