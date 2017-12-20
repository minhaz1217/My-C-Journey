#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
#define check(a) cout<<a<< endl;
class String{
private:
    char *str;
public:
    String(char *s){
        int length = strlen(s);
        str = new char[length+1];
        strcpy(str,s);
    }
    ~String(){
        cout << "Deleting str." << endl;
        delete[] str;
    }
    void display(){
        cout << str << endl;
    }
    void upit(){
        for(int i=0;str[i];i++){
            str[i] = toupper(str[i]);
        }
    }
};
int main(){
    String s1 = "Who knows nothing doubs nothing.";
    cout << "s1= ";
    s1.display();
    s1.upit();
    cout << "s1= ";
    s1.display();
	return 0;
}
