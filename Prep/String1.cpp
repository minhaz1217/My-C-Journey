#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    string str, str2,str3, str4;
    cout << "Insert" << endl;
    //insert
    str.insert(0, "HELLO");
    str.insert(2, "hi");
    cout << str << endl;
    cout << str.capacity() << endl;
    cout << "Push_back 'X'" << endl;
    str.push_back('X');
    cout << str << endl;
    // reverse iterators
    cout << "Rend" << endl;
    str3 = "This is a sentence";
    string c1, c2;
    copy(str3.begin(), str3.end(), back_inserter(c1));
    copy(str3.rbegin(), str3.rend(),  back_inserter(c2));
    cout << c1 << endl << c2 << endl;

    // assign
    cout << "Assign" << endl;
    str2 = "Hello There";
    str2.assign("hi", 3);
    // str.assign( firstString, length of the first string to assign);
    cout << str2 << endl;
    cout << str2.length() << endl;
    //Append
    cout << "Append 'this'" << endl;
    str.append("this", 2);
    cout << str << endl;

    // reserve
    cout << "Reserve" << endl;
    string::size_type newCapacity(100);
    str.reserve(newCapacity);
    cout << str.capacity() << endl;

    // substr
    cout << "\n\nSubstring" << endl;
    str4 = "This is a string";
    cout << str4.substr(4) << endl;
    cout << str4.substr(0,4) << endl;
    cout << str4.substr(str4.size() - 6, str4.size()) << endl;

    double f = 23.324;
    int a = 22;
    string si = "11";
    int b = stoi(si);
    cout << b << endl;
    cout << si << endl;

    return 0;
}
