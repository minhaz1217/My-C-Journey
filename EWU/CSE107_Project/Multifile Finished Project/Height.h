#include<bits/stdc++.h>

//The height class
class Height{
private:
    int foot, inches;
public:
    Height(int f, int i){
        foot = f;
        inches = i;
        this->roundNumbers();
    }
    int getFoot(){
        return foot;
    }
    int getInches(){
        return inches;
    }
    void setFoot(int f){
        foot = f;
    }
    void setInches(int i){
        inches = i;
    }
    void takeFoot(){
        cout << "Enter your height(feet): ";
        cin >> foot;
    }
    void takeInches(){
        cout << "Enter your height (inches): ";
        cin >> inches;
    }
    float convertToCm(){
        float cm = 2.54 * (foot * 12 + inches);
        return cm;
    }
    void takeHeight(int a=0){
        if(a==0){//get height in a single line
            cout << "Enter your height(feet inches): ";
            cin >> foot >> inches;
        }else if(a==1){//get height in 2 line
            this->takeFoot();
            this->takeInches();
        }
    }
    void roundNumbers(){
        if(inches >= 12){
            foot = foot + (inches/12);
            inches = inches %12;
        }
    }
    void display(){
        cout << foot << "`" << inches << "``" << endl;
    }
};
