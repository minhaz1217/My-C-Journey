#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    /*
    setiosflags
    resetiosflags
    setbase
    setfill
    setprecision
    setw
    */
    int n = 100;



    cout << setiosflags(ios::showbase | ios::uppercase);
    cout <<hex<< n << endl;
    //setiosflags(mase) is used to set masks with pipe (|)
    cout << resetiosflags(ios::showbase) << n << endl;
    cout << "Oct: " << setbase(8) << n << endl;
    cout << "Dec: " << setbase(10) << n << endl;
    cout << "Hex: " << setbase(16) << n << endl;
    //setbase(para) is para is 8 then its oct
    // if para is 10 then its dcimal
    // if para is 16 then its hex
    // if para is anyother number then it resets
    cout << "Any other: " << setbase(100) << n<< endl;

    cout << setw(10) << n << endl;
    cout << setw(20) << setfill('*') << n << endl;
    //setw(intvar) gives padding of intvar spaces
    //setfill(charvar) sets the padding spaces with charvar
    double d = 1000.12345678;
    cout << "Precision(4) Print: " << setprecision(4) << d << endl;
    cout << "Normal Print: " << d << endl;
    cout << "Only Fixed Print: " << fixed << d << endl;
    cout << "Fixed + Precision(4) Print: "  << fixed << setprecision(4) << d << endl;
    cout << "Scientific Print: " << scientific <<  d << endl;
    /*
    cout << "With Show base: " << hex << showbase << n << endl;
    cout << n << endl;
    cout << "With No Show base: " << hex << noshowbase<< n<< endl;
	cout << n << endl;*/
	return 0;
}
