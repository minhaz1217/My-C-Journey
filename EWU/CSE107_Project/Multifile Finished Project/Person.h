#include<bits/stdc++.h>
class Person: public Height{
private:
    string name;
    int age;
    int weight;
public:
    Person(string n="", int a=0,int w=0, int f=0, int i=0):Height(f, i){
        name = n;
        age = a;
        weight = w;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    void takeName(){
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin , name);
    }
    int getAge(){
        return age;
    }
    void setAge(int a){
        age = a;
    }
    void takeAge(){
        cout << "Enter your age: ";
        cin >> age;
    }
    int getWeight(){
        return weight;
    }
    void setWeight(int w){
        weight = w;
    }
    void takeWeight(){
        cout << "Enter your weight: ";
        cin >> weight;
    }
    void takePerson(){
        this->takeName();
        this->takeAge();
        this->takeWeight();
        this->takeHeight();
    }
    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
        cout << "Height: ";
        Height::display();
    }
    virtual void calculateBmr(){};

    virtual float getCalorieTake(){};
    virtual void setCalorieTake(float ct){};
    virtual float getCalorieUsed(){};
    virtual void setCalorieUsed(int cu){};
    virtual void compare(){};
    virtual void saveToFile(string) =0;
    virtual void loadFromFile(string) =0;
};
