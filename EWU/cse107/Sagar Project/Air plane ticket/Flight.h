#include<bits/stdc++.h>

using namespace std;



class Flight : public Seats
{

     protected:
        string from_date;
    public:


       virtual void read(){

            cout<<"enter your departing date : ";

        getline(cin,from_date);
        }

        virtual void display(){

            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("flight.txt");
            infile.is_open();
            while(getline(infile,str)){

                cout<<str<<endl;
            }
            Seats::Class();
        }


        virtual void owdatoshy(){

            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("owdatoshy.txt");
            infile.is_open();
            while(getline(infile,str)){

                cout<<str<<endl;
            }
            Seats::Class();
        }
         virtual void owcttodh(){

            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("owcttodh.txt");
            infile.is_open();
            while(getline(infile,str)){

                cout<<str<<endl;
            }
            Seats::Class();
        }


        virtual void displayround1(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("flightround1.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
        }

        virtual void displayround2(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("flightround1.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
        }

        virtual void rtdhtoshy(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("rt dk shy.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }

        virtual void displayrtCtoSy(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("rt ct to shy.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }

        virtual void displayrtCtodh(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("Round Trip ct to dk.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }
        virtual void rtshytoctg(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("Rt shy to ctg.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }
        virtual void rtshytodh(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("RT shy to dha.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }
        virtual void d_C_S(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("d-c-s.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }
         virtual void d_s_c(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("d-s-c.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }
         virtual void c_d_s(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("c-d-s.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }
        virtual void s_d_c(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("s-d-c.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }
                virtual void s_c_d(){
            cout<<"your departing date is : "<<from_date<<endl<<endl;

            system("cls");

            cout<<"On the date of "<<from_date<<" You have : "<<endl<<endl;
            string str;
            ifstream infile("s-c-d.txt");
            while(infile){
                getline(infile,str);
                cout<<str<<endl;
            }
            Seats::Class();
        }



};

