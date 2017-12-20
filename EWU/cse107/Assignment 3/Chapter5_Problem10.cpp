#include<iostream>
using namespace std;
int globalCounter = 0;
void functionCounterWithGlobal(){
    globalCounter++;
    cout << "I've been called "<< globalCounter << " time(s)." << endl;
}
void functionCounterWithLocal(int &num){
    num++;
    cout << "I've been called " << num << " time(s)." << endl;
}
int main(){
    int i,localCounter = 0;
    for(i=0;i<10;i++){
        functionCounterWithGlobal();
    }
    cout << endl << endl;
    for(i=0;i<10;i++){
        functionCounterWithLocal(localCounter);
    }
	return 0;
}
