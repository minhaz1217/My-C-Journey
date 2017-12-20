#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,i,counter = 0,c;
    double b;
    cin >> a;
    for(i=1;i<=a;i++){
        counter++;
        if(i>2 && i%2 == 0){
            counter++;
        }
        if(i%2 != 0 && i>8){
            b=sqrt(i);
            c = sqrt(i);
            if(b-c ==0){
                counter++;
            }
        }
    }
    cout << counter;
	return 0;
}
