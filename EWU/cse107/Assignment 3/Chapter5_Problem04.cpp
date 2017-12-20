#include<iostream>
using namespace std;
struct Distance{
    int feet;
    float inches;
};
Distance largerDistance(Distance a, Distance b){
    if(a.feet > b.feet){
        return a;
    }else if(a.feet == b.feet){
        if(a.inches > b.inches){
            return a;
        }else{
            return b;
        }
    }else{
        return b;
    }
}
int main(){
    Distance num1,num2,num3;
    cout << "Enter first distance(feet inches): ";
    cin >> num1.feet >> num1.inches;
    cout << "Enter second distance(feet inches): ";
    cin >> num2.feet >> num2.inches;
    num3 = largerDistance(num1,num2);
    cout << "The larger distance is: " << num3.feet << " feet, " << num3.inches << " inches." << endl;


	return 0;
}
