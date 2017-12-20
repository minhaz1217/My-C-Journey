#include<iostream>
#include<fstream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int arr[6],i;
    ifstream infile("test.txt");
    for(i=0;i<6;i++){
        infile >> arr[i];
        cout << arr[i] << endl;
    }
    infile.close();
	return 0;
}
