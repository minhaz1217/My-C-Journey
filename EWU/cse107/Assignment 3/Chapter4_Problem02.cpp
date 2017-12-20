#include<iostream>
using namespace std;
struct Point{
    int x,y;
};
int main(){
    Point p1, p2;
    cout << "Enter coordinates for p1: ";
    cin >> p1.x >> p1.y;
    cout << "Enter coordinates for p2: ";
    cin >> p2.x >> p2.y;
    cout << "Coordinates of p1 + p2 are: " << (p1.x + p2.x) << ", " << (p1.y + p2.y) << endl;
	return 0;
}
