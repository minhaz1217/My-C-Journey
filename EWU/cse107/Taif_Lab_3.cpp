#include<iostream>
using namespace std;
class army{
private:
    int troops, tanks, trucks;
public:
    army(){
        troops = 0;
        tanks =0;
        trucks = 0;
    }
    void add_troops(){
        int quantity;
        cout << "How many troops do you want to add: ";
        cin >> quantity;
        troops += quantity;
    }
    void add_tanks(){
        int quantity;
        cout << "How many tanks do you want to add: ";
        cin >> quantity;
        tanks += quantity;
    }
    void add_trucks(){
        int quantity;
        cout << "How many trucks do you want to add: ";
        cin >> quantity;
        trucks += quantity;
    }
    void display1(){
        cout << "Total troops: " << troops << endl;
        cout << "Total tanks: " << tanks << endl;
        cout << "Total trucks: " << trucks << endl;
    }

};
class airforce{
private:
    int fighters, helos;
public:
    airforce(){
        fighters = 0;
        helos = 0;
    }
    void add_fighters(){
        int quantity;
        cout << "How many fighters do you want to add: ";
        cin >> quantity;
        fighters += quantity;
    }
    void add_helos(){
        int quantity;
        cout << "How many helos do you want to add: ";
        cin >> quantity;
        helos += quantity;
    }
    void display2(){
        cout << "Total fighters: " << fighters << endl;
        cout << "Total helos: " << helos << endl;
    }

};

class force: public army, public airforce{
    int boats;
public:
    force(){
        boats = 0;
    }
    void add_boats(){
        int quantity;
        cout << "How many boats do you want to add: ";
        cin >> quantity;
        boats += quantity;
    }
    void show_boats(){
        cout << "Total boats: " << boats << endl;
    }
};
int main(){
    force ar1, ar2;
    ar1.add_troops();
    ar1.add_tanks();
    ar1.add_trucks();
    ar1.add_fighters();
    ar1.add_helos();
    ar1.display1();
    ar1.display2();

    ar2.add_boats();
    ar2.add_fighters();
    ar2.add_helos();
    ar2.show_boats();
    ar2.display2();
	return 0;
}
