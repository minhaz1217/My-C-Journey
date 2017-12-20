#include<iostream>
using namespace std;
class Angle{
private:
    int degree;
    float minute;
    char direction;
public:
    Angle(int d=0,float m=0, char di='\0'): degree(d), minute(m), direction(di){}
    void setAngle(){
        cout << "Enter degree: ";
        cin >> degree;
        cout << "Enter minute: ";
        cin >> minute;
        cout << "Enter direction(N, S, E, W): ";
        cin >> direction;
    }
    void getAngle(){
        cout << degree << '\xF8' << minute<< "' "<< direction << endl;
    }

};
int main(){
    Angle a1;
    a1.setAngle();
    a1.getAngle();
	return 0;
}
