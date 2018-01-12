#include <iostream>
#include <sstream>
using namespace std;

class Student{
    int age, standard;
    string first_name, last_name;
    public:
    void set_age(int a){
        age = a;
    }
    void set_standard(int a){
        standard = a;
    }
    void set_first_name(string a){
        first_name = a;
    }
    void set_last_name(string a){
        last_name = a;
    }
    int get_age(){
       return age;
    }
    int get_standard(){
       return standard;
    }
    string get_first_name(){
       return first_name;
    }
    string get_last_name(){
       return last_name;
    }
    string to_string(){
        stringstream ss,ss2;
        ss << age;
        string s1,s2;
        ss >> s1;
        ss2 << standard;
        ss2 >> s2;
        cout << s2 << endl;
        string str = s1 +"," + first_name + "," + last_name + "," + s2;
        return str;
    }
};



int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
