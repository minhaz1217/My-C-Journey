#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ch;

    cout << "1. Enam " << endl;
    cout << "2. Sagor " << endl;
    cout << "3. Asif " << endl;
    cout << "4. Farin " << endl;

    cin >> ch;

    if(ch==1)
    {
        system("cls");
        cout << setw(50) << "Enam" << endl ;
    }
    else if(ch==2)
    {
        system("cls");
        cout << setw(50) << "Sagor" << endl ;
    }
    else if(ch==3)
    {
        system("cls");
        cout << setw(50) << "Asif" << endl ;
    }
    else if(ch==4)
    {
        system("cls");
        cout << setw(50) << "Farin my ...." << endl ;
    }
    else{
        system("cls");
        cout << "invaild" << endl;
    }
    return 0;
}
