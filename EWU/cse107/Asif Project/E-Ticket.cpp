#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
using namespace std;

void welcome();

class sit
{
private:
    int sit;
public:
    display_ac()
    {
        string line;
        ifstream myfile ("sit ac.txt");
        myfile.is_open();
        while ( getline (myfile,line) )
        {

            cout << line << endl;
        }
        myfile.close();
        sit::select();
    }

    display_non_ac()
    {
        string line;
        ifstream myfile ("sit non ac.txt");
        myfile.is_open();
        while ( getline (myfile,line) )
        {
            cout << line << endl;
        }
        myfile.close();
        sit::select();
    }

    select()
    {
        int s1;
        string s2;
        cout << endl << endl << "Enter Ammount of sits you want: ";
        cin >> s1;
        cout << endl << endl << "Enter the sit numbers you want: ";
        cin.ignore();
        getline(cin, s2);

    }
};


class bus:public sit
{
private:
    int b;
public:
    c_bus()
    {
        int v;

        HANDLE word_colour;
        word_colour = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute (word_colour, 9);
        cout << "Choose the bus you want to travel in:" << endl;

        SetConsoleTextAttribute (word_colour, 15);

        cout << endl << "(1) for Shohag Ac bus" << endl
             << "(2) for Shohag Non-Ac bus" << endl << "(3) for Hanif Ac bus" << endl << "(4) for Hanif Non-Ac bus"
             << endl << "(5) for Green Line bus" << endl << "Enter your choice: ";

        cin >> v;

        if (v==1 || v==3 || v==5){
            sit::display_ac();
        }
        else if(v==2 || v==4){
            sit::display_non_ac();
        }
        else{
            cout << endl << "Not available, Input again" << endl;
            c_bus();
        }
    }

};
class division: public bus
{
private:
    int div;
public:
    division()
    {
        int f, g;
        HANDLE word_colour;
        word_colour = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute (word_colour, 10);
        cout << "Departure:" << endl;

        SetConsoleTextAttribute (word_colour, 15);

        cout << endl << "(1) for Dhaka" << endl << "(2) for Chittagong"
             << endl << "(3) for Sylhet" << endl << endl << "Enter your choice: ";

        cin >> f;
class sit
{
private:
    int sit;
public:
    display_ac()
    {
        string line;
        ifstream myfile ("sit ac.txt");
        myfile.is_open();
        while ( getline (myfile,line) )
        {
            cout << line << endl;
        }
        myfile.close();
        sit::select();
    }

    display_non_ac()
    {
        string line;
        ifstream myfile ("sit non ac.txt");
        myfile.is_open();
        while ( getline (myfile,line) )
        {
            cout << line << endl;
        }
        myfile.close();
        sit::select();
    }

    select()
    {
        int s1;
        string s2;
        cout << endl << endl << "Enter Ammount of sits you want: ";
        cin >> s1;
        cout << endl << endl << "Enter the sit numbers you want: ";
        getline(cin, s2);

    }
};
        SetConsoleTextAttribute (word_colour, 10);
        cout << endl << endl << "Destination: ";
        SetConsoleTextAttribute (word_colour, 15);


        if(f==1)
        {
            cout << endl << endl << "(1) for Sylhet" << endl << "(2) for Chittagong" << endl;
        }
        else if(f==2)
        {
            cout << endl << endl << "(1) for Dhaka" << endl << "(2) for Sylhet" << endl;
        }
        else if(f==3)
        {
            cout << endl << endl << "(1) for Dhaka" << endl << "(2) for Chottagong" << endl;
        }
        else
        {
            cout << "Not available, Input again" << endl << endl;
            division();
        }


        cout << endl << "Enter your choice: " ;
        cin >> g;

        if (g!=1 && g!=2)
        {
            cout << "Not available, Input agian." << endl;
            division();
        }
        else
        {
            bus::c_bus();
        }
    }
};



int main()
{
    welcome();

    division d1;

    return 0;
}

void welcome()
{
    HANDLE word_colour;
    word_colour = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << endl << endl << "\t\tWELCOME to ";

    SetConsoleTextAttribute (word_colour, 10);
    cout << "ticketing.com";

    SetConsoleTextAttribute (word_colour, 15);
    cout << endl << endl;
}

