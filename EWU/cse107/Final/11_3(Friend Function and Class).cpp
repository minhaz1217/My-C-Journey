#include<iostream>
using namespace std;
class Bclass;
void friendFunc();
class Aclass{
    int aint;
public:
    Aclass(int a=0){
        aint = a;
    }
void display(){
    cout << aint << endl;
}
friend Bclass;
friend void friendFunc();
};
class Bclass{
public:
    void display(){
        Aclass obja;
        obja.aint = 10;
        obja.display();
    }
};
void friendFunc(){
    Aclass obja2;
    obja2.aint = 50;
    obja2.display();
}
int main(){
    Bclass b;
    b.display();
    friendFunc();
	return 0;
}
