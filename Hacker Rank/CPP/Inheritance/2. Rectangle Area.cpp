#include <iostream>
using namespace std;

//custom start
class Rectangle{
    public:
    int height,weight;
    void display(){
        cout << height << " " << weight << endl;
    }
};
class RectangleArea: public Rectangle{

    public:
    void read_input(){
        cin >> height >> weight;
    }
    void display(){
        cout << height*weight << endl;
    }
};
//custom end
int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}
