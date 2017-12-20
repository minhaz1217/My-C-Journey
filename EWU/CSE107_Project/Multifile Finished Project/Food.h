#include<bits/stdc++.h>
// a class that will handling the input for different food types
class Food{
private:
    string name;
    int calorieShow;
    float calorieCount;
    string quantity[3];
    // quantity[0] = many/much
    // quantity[1] = cup/PCS/100gram
public:
    Food(string n="", int cs = 0, float cc=0, string q1 = "", string q2 = "", string q3=""){
        name = n;
        calorieShow = cs;
        calorieCount = cc;
        quantity[0] = q1;
        quantity[1] = q2;
        quantity[2] = q3;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    int getCalorieShow(){
        return calorieShow;
    }
    void setCalorieShow(int cs){
        calorieShow = cs;
    }
    float getCalorieCount(){
        return calorieCount;
    }
    void setCalorieCount(float cc){
        calorieCount = cc;
    }
    string getQuantity1(){
        return quantity[0];
    }
    void setQuantity1(string q1){
        quantity[0] = q1;
    }
    string getQuantity2(){
        return quantity[1];
    }
    void setQuantity2(string q2){
        quantity[1] = q2;
    }
    string getQuantity3(){
        return quantity[2];
    }
    void setQuantity3(string q3){
        quantity[2] = q3;
    }
    void display1(){
        cout << name << " " << calorieShow << "calorie/" << quantity[2] << quantity[1];
    }
    void display2(){
        cout << "How " << quantity[0] << " " << name << " did you eat(" << quantity[1] << "): ";
    }
    friend class Display;
    void operator =(string s){
        name = s;
    }
};
