#include<bits/stdc++.h>
//the calorie class
class Calorie{
private:
    float calorieTake;
    float calorieUsed;
    float calculatedCalorie;
public:
    Calorie(float ct=0, float cu=0, float c1=0):calorieTake(ct), calorieUsed(cu),calculatedCalorie(c1){}
    float getCalorieTake(){
        return calorieTake;
    }
    void setCalorieTake(float ct){
        calorieTake = ct;
    }
    float getCalorieUsed(){
        return calorieUsed;
    }
    void setCalorieUsed(float cu){
        calorieUsed = cu;
    }
    float getCalculatedCalorie(){
        return calculatedCalorie;
    }
    void setCalculatedCalorie(float c1){
        calculatedCalorie = c1;
    }
    void calculateCalorie(int bmr){
        calculatedCalorie = getCalorieTake() - bmr - getCalorieUsed();
    }
    void displayCalorie(){
        if(calculatedCalorie >= 0){
            cout << "You've gained " << calculatedCalorie << " calorie.";
        }else if(calculatedCalorie<0){
            cout << "You've lost " << calculatedCalorie*-1 << " calorie.";
        }
    }
};
