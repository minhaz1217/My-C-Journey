#include<iostream>
using namespace std;
void Swap(int &a, int &b){
    int temp;
    temp = a;
    a=b;
    b = temp;
}
int main(){
    int num1 = 5, num2 = 10;
    Swap(num1, num2);
    cout << num1 << ", "<< num2 << endl;
	return 0;
}
