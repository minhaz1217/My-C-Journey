//http://acm.hust.edu.cn/vjudge/contest/view.action?cid=119841#problem/D
#include<iostream>
using namespace std;
int main(){
    int a,i,q,p, arrCounter = 0;
    cin >> a;
    char arr[a];
    for(i=0;i<a;i++){
        cin >> p >> q;
        if(p > q){
            arr[arrCounter] = '>';
        }else if(q > p){
            arr[arrCounter] = '<';
        }else if(q == p){
            arr[arrCounter] = '=';
        }
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << arr[i] << endl;
    }
	return 0;
}
