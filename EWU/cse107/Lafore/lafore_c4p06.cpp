#include<iostream>
using namespace std;
enum eType{ laborer, secretary, manager, accountant, executive, researcher};
int main(){
    eType e;
    char a;
    cout << "Enter first letter of employee type:( laborer, secretary, manager, accountant, executive, researcher ): ";
    cin >> a;
    switch(a){
    case 'l':
        e = laborer;
        cout << "Employee type is laborer." << endl;
        break;
    case 's':
        e = secretary;
        cout << "Employee type is secretary." << endl;
        break;
    case 'm':
        e = manager;
        cout << "Employee type is manager." << endl;
        break;
    case 'a':
        e = accountant;
        cout << "Employee type is accountant." << endl;
        break;
    case 'e':
        e = executive;
        cout << "Employee type is executive." << endl;
        break;
    case 'r':
        e = researcher;
        cout << "Employee type is researcher." << endl;
        break;
    }
	return 0;
}
