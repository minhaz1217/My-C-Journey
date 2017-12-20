#include<iostream>
using namespace std;
class Data{
private:
    static int totalserialnumber;
    int mySerialNumber;
public:
    Data(){
        totalserialnumber++;
        mySerialNumber = totalserialnumber;
    }
void report(){
    cout << "I'm object number " << mySerialNumber << endl;
}

};
int Data::totalserialnumber = 0;


int main(){
    Data d1,d2,d3;
    d1.report();
    d2.report();
    d3.report();
	return 0;
}
