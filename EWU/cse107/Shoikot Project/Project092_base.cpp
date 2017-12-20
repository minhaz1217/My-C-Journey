#include<iostream>
using namespace std;

int main()
{
    cout<<"Welcome to Saikat's Online Shopping"<<endl;
    cout<<"Please Select"<<endl;
    cout<<"Press"<<endl;
    cout<< "1 : Cloths"<<endl<< "2 : Sports"<<endl<< "3 : Electronices"<<endl<<"4 : Exit"<<endl;
    int choice=0;
    cin>>choice;
    if(choice==1)
    {
        cout<<"press 1 for male cloths"<<endl;
        cout<<"press 2 for female cloths"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"male cloths available"<<endl;
            cout<<"press"<<endl;
            cout<< "1 : Panjabi"<<endl<< "2 : Shirt"<<endl<< "3 : Pant"<<endl;
            cin>>choice;

            if(choice==1)
            {
                cout<<"Price=1000"<<endl;
                cout<<"How many Panjabi do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*1000;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==2)
            {
                cout<<"Price=1500"<<endl;
                cout<<"How many Shirt do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*1500;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==3)
            {
                cout<<"Price=800"<<endl;
                cout<<"How many Pant do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*800;
                cout<<"total bill " <<price<<endl;

            }
            else
            {
                cout<<"Invalid Input"<<endl;
            }
        }
        else if(choice==2)
        {
            cout<<"female cloths available"<<endl;
            cout<<"press"<<endl;
            cout<< "1 : Shari"<<endl<< "2 : Borka"<<endl<< "3 : Kamij"<<endl;
            cin>>choice;

            if(choice==1)
            {
                cout<<"Price=1000"<<endl;
                cout<<"How many Shari do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*1000;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==2)
            {
                cout<<"Price=1500"<<endl;
                cout<<"How many Borka do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*1500;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==3)
            {
                cout<<"Price=800"<<endl;
                cout<<"How many Kamij do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*800;
                cout<<"total bill " <<price<<endl;
            }
            else
            {
                cout<<"Invalid Input"<<endl;
            }
        }
    }
    else if(choice==2)
    {

        cout<<"press 1 for Cricket"<<endl;
        cout<<"press 2 for Football"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Cricket Instruments are available"<<endl;
            cout<<"press"<<endl;
            cout<< "1 : Bat"<<endl<< "2 : Ball"<<endl<< "3 : Stamp"<<endl;
            cin>>choice;

            if(choice==1)
            {
                cout<<"Price=2500"<<endl;
                cout<<"How many Bat do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*2500;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==2)
            {
                cout<<"Price=500"<<endl;
                cout<<"How many Ball do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*500;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==3)
            {
                cout<<"Price=400"<<endl;
                cout<<"How many Stamp do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*400;
                cout<<"total bill " <<price<<endl;

            }
            else
            {
                cout<<"Invalid Input"<<endl;
            }
        }
        else if(choice==2)
        {
            cout<<"Football Instruments are available"<<endl;
            cout<<"press"<<endl;
            cout<< "1 : Football"<<endl<< "2 : Jerssy"<<endl<< "3 : Boot"<<endl;
            cin>>choice;

            if(choice==1)
            {
                cout<<"Price=5000"<<endl;
                cout<<"How many Football do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*5000;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==2)
            {
                cout<<"Price=2000"<<endl;
                cout<<"How many Jerssy do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*2000;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==3)
            {
                cout<<"Price=1200"<<endl;
                cout<<"How many Boot do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*1200;
                cout<<"total bill " <<price<<endl;
            }
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
    }

    else if(choice==3)
    {

        cout<<"press 1 for Smart Phone"<<endl;
        cout<<"press 2 for Daily Necessaries"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Smart Phones are available"<<endl;
            cout<<"press"<<endl;
            cout<< "1 : hTC"<<endl<< "2 : iPhone"<<endl<< "3 : Walton"<<endl;
            cin>>choice;

            if(choice==1)
            {
                cout<<"Price=35000"<<endl;
                cout<<"How many hTC do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*35000;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==2)
            {
                cout<<"Price=60000"<<endl;
                cout<<"How many iPhone do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*60000;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==3)
            {
                cout<<"Price=25000"<<endl;
                cout<<"How many Walton do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*25000;
                cout<<"total bill " <<price<<endl;

            }
            else
            {
                cout<<"Invalid Input"<<endl;
            }
        }
        else if(choice==2)
        {
            cout<<"Daily Necessaries are available"<<endl;
            cout<<"press"<<endl;
            cout<< "1 : Television"<<endl<< "2 : Air Conditioner"<<endl<< "3 : Oven"<<endl;
            cin>>choice;

            if(choice==1)
            {
                cout<<"Price=50000"<<endl;
                cout<<"How many Television do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*50000;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==2)
            {
                cout<<"Price=100000"<<endl;
                cout<<"How many Air Conditioners do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*100000;
                cout<<"total bill " <<price<<endl;

            }
            else if(choice==3)
            {
                cout<<"Price=5000"<<endl;
                cout<<"How many Oven do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                int price = Quantity*5000;
                cout<<"total bill " <<price<<endl;
            }
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
    }
        else if (choice==4)
        {
            cout<<"Thank You"<<endl;
            return 0;
        }
        else
        {
            cout<<"invalid input!"<<endl;
        }


    }
