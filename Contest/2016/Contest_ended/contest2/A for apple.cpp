//http://acm.hust.edu.cn/vjudge/contest/view.action?cid=119841#problem/A
#include<iostream>
using namespace std;
int main(){
    int a,num1,num2,i;
    cin >> a;
    int arr[a];
    for(i=0;i<a;i++){
        cin >> num1 >> num2;
        arr[i] = num1 + num2;
    }
    for(i=0;i<a;i++){
        cout << "Case " << i+1 << ": " << arr[i] << endl;
    }

}
