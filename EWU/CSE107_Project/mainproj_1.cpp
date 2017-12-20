//set - sets data using parameters
// get - gets data usign RETURN
// take - takes data using cin or scanf
#include<iostream>
using namespace std;
class BasicData{
private:
    string name;
    float weight;
    float caloriIntake;
public:
    BasicData(string n="", float wei=0){
        name = n;
        weight = wei;
        caloriIntake = 0;
    }
    string getName(){
        return name;
    }
    float getWeight(){
        return weight;
    }
    float getCaloriIntake(){
        return caloriIntake;
    }
    void setName(string n){
        name = n;
    }
    void setWeight(float w){
        weight = w;
    }
    void setCaloriIntake(float ci){
        caloriIntake = ci;
    }
    void takeName(){
        cout << "Enter your name: ";
        cin >> name;
    }
    void takeWeight(){
        cout << "Enter your weight: ";
        cin >> weight;
    }
    void takeCaloriIntake(){
        cout << "Enter your calori intake: ";
        cin >> caloriIntake;
    }
    void takeData(){
        this ->takeName();
        this->takeWeight();
        this -> takeCaloriIntake();
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Weight: " << weight << endl;
        cout << "Calori Intake: " << caloriIntake << endl;
    }
};
class HighWeight{
};
class NormalWeight{
};
class LowWeight{
};
int main(){
    BasicData b1;
    b1.takeData();
    b1.display();
    return 0;
}

