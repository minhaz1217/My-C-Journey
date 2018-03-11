//http://acm.hust.edu.cn/vjudge/contest/view.action?cid=119841#problem/C
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
