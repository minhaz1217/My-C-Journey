#include<bits/stdc++.h>

using namespace std;


class Seats : public Airlines{
    public:
    void Class()
    {
        int f_choice, c_choice, s_num;
        int total = 0;
        char dic;
        flights : cout << endl << "Choose your flight: "<<endl;
        cin>>f_choice;
        if(f_choice == 1 || f_choice == 2 || f_choice == 3){
        cout<<endl<<"Enter your choise";
        cout<<endl<<"Enter 1 for FIRST CLASS"<<endl<<endl<<"Enter 2 for ECONOMY"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>c_choice;
        cout<<endl<<endl;
        cout<<"How many sits do you want: ";
        cin>>s_num;

        if (c_choice==1)
        {
            total = 6000*s_num;
        }
        else if (c_choice==2)
        {
            total = 4000*s_num;
        }




        cout<<endl<<endl<<"Total Ticket price is: "<<total<<endl << "Do you proceed to buy(Y/N): ";
        cin>>dic;
        dic=toupper(dic);

        if(dic=='N')
        {

        }
        else if(dic == 'Y'){
            cout << "Booking seat: " << endl;
            for(int i=1;i<=s_num;i++){
                cout << "A-" << i;
                cout << " ";
            }
            cout <<endl << "Please collect the ticket(s) from: ";
            cout << "Counter: " << "C-420";
            cout << endl;
            cout << "Remember to collect your ticket 2 hours before immigration" << endl;
        }
        else{
            cout<<"Invalid"<<endl;
        }
        }

        else if(f_choice == 0){
            Airlines :: back();
        }
        else {
            cout<<"No flight in that Number";
            goto flights;
        }


    }
    };

