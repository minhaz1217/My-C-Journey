#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<cctype>
#define check(a) cout<<a<< endl;

#define dash 80

using namespace std;

int busRent = 0;
void welcome();
int bus_in;
int from, to, num=1;
string taken[60];
class sit
{
private:
    int sit;
public:
    string seats;
    string line;
    char ch;
    // char ch;
    // string line, seats;
    string taken[60];
    int x;
    int counter = 0;
    int s1, i;
    string seat_choice, seat_cond;
    char dis;

    void display_ac()
    {

        ifstream myfile ("sit ac.txt");
        myfile.is_open();
        while ( getline (myfile,line) )
        {
            cout << line << endl;
        }
        myfile.close();


        if ( from==1 && to==1 && bus_in==1)
        {
            ifstream myfile;
            myfile.open("booked_sit_s_ac_d2s.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==1 && to==1 && bus_in==3)
        {
            ifstream myfile;

            myfile.open("booked_sit_h_ac_d2s.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if ( from==1 && to==1 && bus_in==5)
        {
            ifstream myfile;
            myfile.open("booked_sit_gl_d2s.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if ( from==1 && to==2 && bus_in==1)
        {
            ifstream myfile;
            myfile.open("booked_sit_s_ac_d2c.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==1 && to==2 && bus_in==3)
        {
            ifstream myfile;
            myfile.open("booked_sit_h_ac_d2c.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();

        }
        else if ( from==1 && to==2 && bus_in==5)
        {
            ifstream myfile;
            myfile.open("booked_sit_gl_d2c.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if ( from==2 && to==1 && bus_in==1)
        {
            ifstream myfile;
            myfile.open("booked_sit_s_ac_s2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==2 && to==1 && bus_in==3)
        {
            ifstream myfile;
            myfile.open("booked_sit_h_ac_s2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if ( from==2 && to==1 && bus_in==5)
        {
            ifstream myfile;
            myfile.open("booked_sit_gl_s2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if ( from==3 && to==1 && bus_in==1)
        {
            ifstream myfile;
            myfile.open("booked_sit_s_ac_c2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==3 && to==1 && bus_in==3)
        {
            ifstream myfile;
            myfile.open("booked_sit_h_ac_c2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if ( from==3 && to==1 && bus_in==5)
        {
            ifstream myfile;
            myfile.open("booked_sit_gl_c2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        sit::select();
    }

    void display_non_ac()
    {


        for( x=0; x<60; x++)
        {
            taken[x]="00";
        }

        ifstream myfile ("sit ac.txt");
        myfile.is_open();
        while ( getline (myfile,line) )
        {
            cout << line << endl;
        }
        myfile.close();

        if( from==1 && to==1 && bus_in==2)
        {
            ifstream myfile;
            myfile.open("booked_sit_s_non_ac_d2s.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();

            /*for(int i=0;seats[i];i+= 3){
            taken[counter][0] = seats[i];
            taken[counter][1] = seats[i+1];
            counter++;
            }*/
        }
        else if( from==1 && to==1 && bus_in==4)
        {
            ifstream myfile;
            myfile.open("booked_sit_h_non_ac_d2s.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==1 && to==2 && bus_in==2)
        {
            ifstream myfile;
            myfile.open("booked_sit_s_non_ac_d2c.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==1 && to==2 && bus_in==4)
        {
            ifstream myfile;
            myfile.open("booked_sit_h_non_ac_d2c.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==2 && to==1 && bus_in==2)
        {
            ifstream myfile;
            myfile.open("booked_sit_s_non_ac_s2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==2 && to==1 && bus_in==4)
        {
            ifstream myfile;
            myfile.open("booked_sit_h_non_ac_s2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==3 && to==1 && bus_in==2)
        {
            ifstream myfile;
            myfile.open("booked_sit_s_non_ac_c2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }
        else if( from==3 && to==1 && bus_in==4)
        {
            ifstream myfile;
            myfile.open("booked_sit_h_non_ac_c2d.txt");
            cout << "Booked sits are: ";
            getline(myfile, seats);
            cout << seats << endl;
            myfile.close();
        }


        sit::select();
    }

    void select()
    {
        //populating the taken array
        counter = 0;
        for(int i=0; seats[i]; i++)
        {
            taken[i]="00";
        }
        for(int i=0; seats[i]; i+=3)
        {
            taken[counter][0]=seats[i];
            taken[counter][1]=seats[i+1];
            counter++;
        }
        //populating ended

        cout << endl << endl;
        for(int i=0; i<dash; i++)
            cout << "_";
        //cout << endl << endl << "Enter Amount of sits you want: ";
        //cin >> s1;
        cout << endl << endl << "Enter the serial of the sit you want: ";
        cin.ignore();
        getline(cin, seat_choice);
        for(int i = 0; i < seat_choice.size(); i++)
        {
            seat_choice[i] = toupper(seat_choice[i]);
        }



        // check seat taken here
        int flag  =1; // if flag = 1 then seat is not taken, if 0 then seat is taken
        for(i=0;i<counter;i++){
            if(taken[i] == seat_choice){
                flag = 0;
                break;
            }
        }

        //checking if the seat_choice input is valid or not
        if(seat_choice.length() > 2){
            flag = 3;
        }else{
            int first_key = seat_choice[0], second_key = seat_choice[1];
            //first key can be A-J(ascii 64-74) second key can be 1-4(ascii 49 - 52) depending on buses
            if( !(first_key >= 65 && first_key <=74) ){
                flag = 3;
            }else{
                if(bus_in == 1 || bus_in == 3 || bus_in ==5){
                    if( !(second_key >=49 && second_key <= 51 ) ){
                        flag = 3;
                    }
                }else if(bus_in==2 || bus_in == 4){
                    if( !(second_key >=49 && second_key <= 52 ) ){
                        flag = 3;
                    }
                }
            }
        }

        if(flag == 0){
            cout << "Sorry the seat is already booked." << endl;
        }else if(flag ==3){
            cout << "Sorry the input is invalid. Enter valid seats." << endl;
        }else if(flag == 1){

            cout << "The seat is not booked." << endl;
            if ( from==1 && to==1 && bus_in==1)
            {
                ofstream myfile;
                myfile.open("booked_sit_s_ac_d2s.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if( from==1 && to==1 && bus_in==2)
            {
                ofstream myfile;
                myfile.open("booked_sit_s_non_ac_d2s.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if( from==1 && to==1 && bus_in==3)
            {
                ofstream myfile;
                myfile.open("booked_sit_h_ac_d2s.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();

            }
            else if( from==1 && to==1 && bus_in==4)
            {
                ofstream myfile;
                myfile.open("booked_sit_h_non_ac_d2s.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if ( from==1 && to==1 && bus_in==5)
            {
                ofstream myfile;
                myfile.open("booked_sit_gl_d2s.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if ( from==1 && to==2 && bus_in==1)
            {
                ofstream myfile;
                myfile.open("booked_sit_s_ac_d2c.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if( from==1 && to==2 && bus_in==2)
            {
                ofstream myfile;
                myfile.open("booked_sit_s_non_ac_d2c.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }

            else if( from==1 && to==2 && bus_in==3)
            {
                ofstream myfile;
                myfile.open("booked_sit_h_ac_d2c.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();

            }
            else if( from==1 && to==2 && bus_in==4)
            {
                ofstream myfile;
                myfile.open("booked_sit_h_non_ac_d2c.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if ( from==1 && to==2 && bus_in==5)
            {
                ofstream myfile;
                myfile.open("booked_sit_gl_d2c.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if ( from==2 && to==1 && bus_in==1)
            {
                ofstream myfile;
                myfile.open("booked_sit_s_ac_s2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if( from==2 && to==1 && bus_in==2)
            {
                ofstream myfile;
                myfile.open("booked_sit_s_non_ac_s2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }

            else if( from==2 && to==1 && bus_in==3)
            {
                ofstream myfile;
                myfile.open("booked_sit_h_ac_s2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if( from==2 && to==1 && bus_in==4)
            {
                ofstream myfile;
                myfile.open("booked_sit_h_non_ac_s2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if ( from==2 && to==1 && bus_in==5)
            {
                ofstream myfile;
                myfile.open("booked_sit_gl_s2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if ( from==3 && to==1 && bus_in==1)
            {
                ofstream myfile;
                myfile.open("booked_sit_s_ac_c2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if( from==3 && to==1 && bus_in==2)
            {
                ofstream myfile;
                myfile.open("booked_sit_s_non_ac_c2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }

            else if( from==3 && to==1 && bus_in==3)
            {
                ofstream myfile;
                myfile.open("booked_sit_h_ac_c2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();

            }
            else if( from==3 && to==1 && bus_in==4)
            {
                ofstream myfile;
                myfile.open("booked_sit_h_non_ac_c2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            else if ( from==3 && to==1 && bus_in==5)
            {
                ofstream myfile;
                myfile.open("booked_sit_gl_c2d.txt", ios::app);
                myfile << seat_choice << " " ;
                myfile.close();
            }
            cout << "Your seat has been booked at: " << seat_choice << endl;
        }
        /*if(taken[i] == seats){
                cout << "Sorry Seat's been Booked, Please choose another." << endl;
                sit::select();
        }*/
        cout << endl << endl << "Do you want to enter more?(Y/N): ";
        cin >> dis;

        if(dis == 'Y' || dis == 'y')
        {
            //adding the current chosen seat the the seat array
            if(flag != 0 && flag != 3){
                seats.append(1, seat_choice[0]);
                seats.append(1, seat_choice[1]);
                seats.append(1, ' ');
            }
            num++;
            select();
        }
        else
        {
            welcome();
        }
    }

};

class bus:public sit
{
private:
    int b;
public:
    void c_bus()
    {
        HANDLE word_colour;
        word_colour = GetStdHandle(STD_OUTPUT_HANDLE);

        for(int i=0; i<dash; i++)
            cout << "_";

        SetConsoleTextAttribute (word_colour, 10);
        cout << endl << endl << "Choose the bus you want to travel in:" << endl;

        SetConsoleTextAttribute (word_colour, 15);

        if(from==3 && to==1)
        {
            cout << endl << "(1) for Shohag Ac bus(500 tk/sit)" << endl
                 << "(2) for Shohag Non-Ac bus (400 tk/sit) " << endl << "(3) for Hanif Ac bus (500 tk/sit)"
                 << endl << "(4) for Hanif Non-Ac bus (400 tk/sit)" << endl
                 << "(5) for Green Line bus (600 tk/sit)" << endl << endl << "Enter your choice: ";
        }
        else if(from==1 && to==1)
        {
            cout << endl << "(1) for Shohag Ac bus(500 tk/sit)" << endl
                 << "(2) for Shohag Non-Ac bus (400 tk/sit) " << endl << "(3) for Hanif Ac bus (500 tk/sit)"
                 << endl << "(4) for Hanif Non-Ac bus (400 tk/sit)" << endl
                 << "(5) for Green Line bus (600 tk/sit)" << endl << endl << "Enter your choice: ";
        }
        else if(from==1 && to==2)
        {
            cout << endl << "(1) for Shohag Ac bus(600 tk/sit)" << endl
                 << "(2) for Shohag Non-Ac bus (500 tk/sit) " << endl << "(3) for Hanif Ac bus (600 tk/sit)"
                 << endl << "(4) for Hanif Non-Ac bus (500 tk/sit)" << endl
                 << "(5) for Green Line bus (700 tk/sit)" << endl << endl << "Enter your choice: ";
        }
        else if(from==2 && to==1)
        {
            cout << endl << "(1) for Shohag Ac bus(600 tk/sit)" << endl
                 << "(2) for Shohag Non-Ac bus (500 tk/sit) " << endl << "(3) for Hanif Ac bus (600 tk/sit)"
                 << endl << "(4) for Hanif Non-Ac bus (500 tk/sit)" << endl
                 << "(5) for Green Line bus (700 tk/sit)" << endl << endl << "Enter your choice: ";
        }

        cin >> bus_in;

        if (bus_in==1 || bus_in==3 || bus_in==5)
        {
            sit::display_ac();
        }
        else if(bus_in==2 || bus_in==4)
        {
            sit::display_non_ac();
        }
        else
        {
            cout << endl << endl << "Not available, Input again" << endl;
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

        HANDLE word_colour;
        word_colour = GetStdHandle(STD_OUTPUT_HANDLE);

        for(int i=0; i<dash; i++)
            cout << "_";

        SetConsoleTextAttribute (word_colour, 12);
        cout << endl << "Departure:" << endl;

        SetConsoleTextAttribute (word_colour, 15);

        cout << endl << "(1) for Dhaka" << endl << "(2) for Chittagong"
             << endl << "(3) for Sylhet" << endl << endl << "Enter your choice: ";

        cin >> from;

        for(int i=0; i<dash; i++)
            cout << "_";




        if(from==1)
        {
            SetConsoleTextAttribute (word_colour, 12);
            cout << endl << "Destination: ";
            SetConsoleTextAttribute (word_colour, 15);

            cout << endl << endl << "(1) for Sylhet" << endl << "(2) for Chittagong" << endl;
        }
        else if(from==2)
        {
            SetConsoleTextAttribute (word_colour, 12);
            cout << endl << "Destination: ";
            SetConsoleTextAttribute (word_colour, 15);

            cout << endl << endl << "(1) for Dhaka" << endl;
        }
        else if(from==3)
        {
            SetConsoleTextAttribute (word_colour, 12);
            cout << endl << "Destination: ";
            SetConsoleTextAttribute (word_colour, 15);

            cout << endl << endl << "(1) for Dhaka" << endl;
        }
        else
        {
            cout << endl << endl << "Not available, Input again" << endl << endl;
            division();
        }


        cout << endl << "Enter your choice: " ;
        cin >> to;


        /* if( (from==1 && to==1) ){

         }else if(from == 1 && ){}*/


        if (from==1 && to==1)
        {
            bus::c_bus();
        }
        else if(from==1 && to==2)
        {
            bus::c_bus();
        }
        else if(from==2 && to==1)
        {
            bus::c_bus();
        }
        else if(from==3 && to==1)
        {
            bus::c_bus();
        }
        else
        {
            cout << endl << endl << "Not available, Input agian." << endl;
            division();
        }
    }
};



int main()
{
    welcome();

    division div1;

    return 0;
}

void welcome()
{
    HANDLE word_colour;
    word_colour = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute (word_colour, 10);
    cout << endl << endl << setw(65) << "WELCOME to Automation Of Transportation System";

    SetConsoleTextAttribute (word_colour, 15);
    cout << endl << endl;
}

