#include<iostream>
#include<map>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    map <int , string> nameMap;
    nameMap[1] = "One";
    nameMap[2] = "Two";
    nameMap[3] = "Three";
    nameMap[4] = "Four";
    nameMap[5] = "Five";
    nameMap[6] = "Six";
    nameMap[7] = "Seven";
    nameMap[8] = "Eight";
    cout << nameMap[1]<< endl;
    //nameMap.clear();
    //cout << nameMap.empty() << endl;
    nameMap.insert(pair<int, string>(9, "Nine"));
    nameMap.insert(pair<int, string>(10, "Ten"));
    nameMap.insert(pair<int, string>(11, "Eleven"));
    nameMap.insert(pair<int, string>(-1, "Twelve"));
    nameMap.insert(pair<int, string>(4.5, "Thirteen"));
    nameMap.insert(pair<int, string>(14, "Fourteen"));
    cout << nameMap.size() << endl;
    map<int, string>::iterator it2 = nameMap.begin();
    it2 = nameMap.find(9);
    cout << "Found: " << it2->second << endl;
    nameMap.erase(it2);
    //map<int , string>::iterator it - nameMap.begin();



    for(map<int, string>::iterator it = nameMap.begin(); it != nameMap.end(); it++){
        cout << it->first << " : " << it->second <<endl;
    }
	return 0;
}
