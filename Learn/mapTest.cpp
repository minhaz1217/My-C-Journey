#include<iostream>
#include<map>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    /*
    map<int , string> myname;
    myname[0] = "HELLO";
    myname[5] = "1";
    myname[6] = "2";
    myname[7] = "3";
    myname[8] = "4";
    myname[90] = "5";
    cout << "Map size: " << myname.size() << endl;
    for(map<int, string>::iterator ii = myname.begin(); ii!= myname.end(); ++ii){
        cout << (*ii).first << " : " << (*ii).second << endl;
    }
    */
    map<int , int, string> mine;
    mine[0] = pair<int , string>(4, "hi");


	return 0;
}
