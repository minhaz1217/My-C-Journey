#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int arr[5] = {1,2,3,4,5};
    ofstream outfile("outfile1.dat");
    for(int i=0;i<5;i++){
        outfile << arr[i] << endl;
    }
    outfile.close();
    int aarr[5];
    ifstream infile("outfile1.dat");
    for(int i=0;i<5;i++){
        infile >> aarr[i];
    }
    infile.close();
    for(int i=0;i<5;i++){
        cout << aarr[i] << endl;
    }
	return 0;
}
