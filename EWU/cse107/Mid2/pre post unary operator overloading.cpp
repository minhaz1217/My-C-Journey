#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class Counter{
private:
    int i;
public:
    Counter(int a){
        i = a;
    }
    void display(){
        cout << i << endl;
    }

    Counter operator ++(){
        return Counter(++i);
    }
    Counter operator ++(int){
        cout << i << endl;
        return Counter(i++);
    }

};
int main(){
    Counter a(2);
    a++;
    a.display();
	return 0;
}
