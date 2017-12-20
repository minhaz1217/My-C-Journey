#include<iostream>
using namespace std;
    int f91(int n){
        if(n<=100){
            return (f91(f91(n+11)));
        }else if(n>=101){
            return (n-10);
        }
    }
int main(){
    int a, arr[250000][2],arrCounter = 0;
    for(;;){
        cin >> a;
        if(a==0){break;}
        arr[arrCounter][0] = a;
        arr[arrCounter][1] = f91(a);
        arrCounter++;
    }

    for(a=0;a<arrCounter;a++){

        cout << "f91(" << arr[a][0] << ") = " << arr[a][1] << endl;
    }

	return 0;
}
