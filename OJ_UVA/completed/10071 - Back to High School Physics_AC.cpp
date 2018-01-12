#include<iostream>
using namespace std;
int main(){
    int a,b,arr[100000],arrCounter = 0;
    for(;;){
        cin >> a;
        if(cin.eof()){break;}
        cin >> b;
        if(cin.eof()){break;}
        arr[arrCounter] = a*b*2;
        arrCounter++;
    }
    for(a=0;a<arrCounter;a++){
        cout << arr[a] << endl;
    }
	return 0;
}



// DOUBLE SOLUTION




/*
#include<iostream>
using namespace std;
int main(){
	long long num1, num2;
    for(;;){
        cin >> num1 >> num2;
        if(cin.eof()){
            break;
        }else{
            cout << num1*num2 * 2 << endl;
        }
    }
    return 0;
}

*/
