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
class Ship{
private:
    int mySerial;
    static int TOTALSERIAL;
    Angle lon, lat;
public:
    Ship(){
        TOTALSERIAL++;
        mySerial = TOTALSERIAL;
    }
    void setShip(){
        cout << "Latitude: \n";
        lat.setAngle();
        cout << "Longitude: \n";
        lon.setAngle();
    }
    void getShip(){
        cout << "My serial is: " << mySerial << endl;
        cout << "My Position: ";
        cout << "Latitude: ";
        lat.getAngle();
        cout << "Longitude: ";
        lon.getAngle();
    }

};
int Ship::TOTALSERIAL = 0;


int main(){
    Ship s1;
    s1.setShip();
    s1.getShip();
	return 0;
}
