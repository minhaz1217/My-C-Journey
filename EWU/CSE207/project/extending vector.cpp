#include<bits/stdc++.h>
#include<string.h>
#include<cstring>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
template<class T>
class Vector : public vector<T> {
    public:
    void myFunc(){
        cout << "Hello From myFunc()" << endl;
    }
    int length(){
        return 2;
    }
    void printAll(){
        vector<int>::iterator it;
        it = this->begin();
        cout << "PRINTING" << endl;
        while(it!= this->end()){
            cout << *it << endl;
            it++;
        }
    }
//Your functions here
// I forgot the name of the internal container of stl containers :(
};
//#define vector Vector

//worked
/*
class String: public basic_string<char>{
public:
    String(basic_string<char> a):basic_string<char>(a){}
    void myF(){
        cout << "HI "<< endl;
    }
};
*/
template<

    class CharT,
    class Traits = std::char_traits<CharT>,
    class Allocator = std::allocator<CharT>
> class basic_string;

class String: public std::string{
public:
    String(basic_string<char> a):basic_string<char>(a){}
    void myF(){
        cout << "HI "<< endl;
    }
};


int main(){
    Vector<int> v;
    v.push_back(5);
    v.push_back(50);
    //check(v.length());
    cout << v[0] << endl;
    v.myFunc();
    v.printAll();
    msg("Vector address" , &v)
    cout << &v[0]<< endl;
    cout << &v[1]<< endl;
    cout << v.front() << endl;
    //cout << v.begin() << endl;
//    cout << &(v.begin()) << endl;


    /*
    //String st("HI");
    String ss("Hello");
    ss.myF();
    //ss = "HI";
    check(ss.length())

    cout << ss << endl;
    string myString = "hello String";


    */
    return 0;
}
