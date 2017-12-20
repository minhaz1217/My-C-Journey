#include<iostream>
using namespace std;
class client{
private:
    int tv, fridge, fans;
public:
    void setItem(){
        cout << "How many tv do you want?: ";
        cin >> tv;
        cout << "How many fridge? : ";
        cin >> fridge;
        cout << "How many fans do you want?: ";
        cin >> fans;

    }
    void take(int t,int fr, int fn){
        tv -= t;
        fridge -= fr;
        fans -= fn;
    }
    void store(int t,int fr, int fn){
        tv+=t;
        fridge += fr;
        fans += fn;
    }
    void display(){
        cout << "Currently in inventory we have, " << endl;
        cout << "TV: " << tv << endl;
        cout << "Fridge: " << fridge << endl;
        cout << "Fans: " << fans << endl;
    }
};
int main(){
    client c1,c2;
    c1.setItem();
    c1.display();
    c1.take(5,4,7);
    cout << "After taking: " << endl;
    c1.display();
    c2.setItem();
    c2.display();
    c2.store(10,25,50);
    cout << "After storing: " << endl;
    c2.display();
	return 0;
}
