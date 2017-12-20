//http://acm.hust.edu.cn/vjudge/contest/view.action?cid=119841#problem/E
#include<iostream>
using namespace std;
int main(){
    int arr[100000],arrCounter = 0;
    string str;
    for(;;){
        cin >> str;
        if(str == "*"){
            break;
        }
        if(str == "Hajj"){
            arr[arrCounter] = 1;
        }else if(str == "Umrah"){
            arr[arrCounter] = 0;
        }
        arrCounter++;
    }
    for(int i=0;i<arrCounter;i++){
        cout << "Case " << i+1 << ": ";
        if(arr[i] == 1){
            cout << "Hajj-e-Akbar" << endl;
        }else if(arr[i] == 0){
            cout << "Hajj-e-Asghar" << endl;
        }
    }
	return 0;
}
