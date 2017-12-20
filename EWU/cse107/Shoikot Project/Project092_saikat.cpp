#include<iostream>
using namespace std;
class product{
    int price;
public:
    product(){
        price = 0;
    }
    product(int num){
        price = num;
    }
    int get_product_price(){
        return price;
    }
};
class product_details:public product{
    string name;
    int total_products;
    int total_bill;
public:
    product_details(string product_name, int taka):product(taka){
        name = product_name;
        total_products=0;
        total_bill = 0;
    }
    int get_total_bill(int numbers){
        total_products = numbers;
        total_bill = get_product_price() * numbers;
    }
    string get_product_name(){
        return name;
    }
    void view_total_amount(){
        cout << "Your bill for " << total_products << " " << name << " is: " << total_bill << " taka." << endl;
    }
};
int main()
{
    product_details panjabi("Panjabi", 1000) , shirt("Shirt", 1500), pant("Pant", 800);
    product_details shari("Shari", 1000) , borka("Borka", 1500) ,kamij("Kamij", 800);

    product_details bat("Bat", 2500) , ball("Ball", 500), stamp("Stamp", 400);
    product_details football("Football", 5000) , jerssy("Jerssy", 2000), boot("Boot", 1200);

    product_details htc("hTC", 35000) , iphone("iPhone", 60000), walton("Walton", 25000);
    product_details tv("Television", 50000) , ac("Air Conditioner", 100000), oven("Oven", 5000);


    cout<<"Welcome to Saikat's Online Shopping"<<endl;
    buy :
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
                cout<<"How many "<< panjabi.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                panjabi.get_total_bill(Quantity);
                panjabi.view_total_amount(); p:
                cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                 {
                
				
                cout<<"Thank You"<<endl;}
                else{
				
                cout<<"Invalid Input"<<endl;
                goto p;
				}

            }
            else if(choice==2)
            {
                cout<<"Price=1500"<<endl;
                cout<<"How many "<< shirt.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                shirt.get_total_bill(Quantity);
                shirt.view_total_amount(); q:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                {
				
                cout<<"Thank You"<<endl;}
                else{
				
                cout<<"Invalid Input"<<endl;
                goto q;
				}


            }
            else if(choice==3)
            {
                cout<<"Price=800"<<endl;
                cout<<"How many "<< pant.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                pant.get_total_bill(Quantity);
                pant.view_total_amount(); r :
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto r;
            }
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
                cout<<"How many "<< shari.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                shari.get_total_bill(Quantity);
                shari.view_total_amount(); s:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto s;
}
            }
            else if(choice==2)
            {
                cout<<"Price=1500"<<endl;

                cout<<"How many "<< borka.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                borka.get_total_bill(Quantity);
                borka.view_total_amount(); t:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto t;
}
            }
            else if(choice==3)
            {
                cout<<"Price=800"<<endl;

                cout<<"How many "<< kamij.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                kamij.get_total_bill(Quantity);
                kamij.view_total_amount(); u :
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto u;
            }
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

                cout<<"How many "<< bat.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                bat.get_total_bill(Quantity);
                bat.view_total_amount(); a :
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto a;
            }

            }
            else if(choice==2)
            {
                cout<<"Price=500"<<endl;

                cout<<"How many "<< ball.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                ball.get_total_bill(Quantity);
                ball.view_total_amount(); b:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto b;
}
            }
            else if(choice==3)
            {
                cout<<"Price=400"<<endl;

                cout<<"How many "<< stamp.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                stamp.get_total_bill(Quantity);
                stamp.view_total_amount(); c:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto c;
}
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

                cout<<"How many "<< football.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                football.get_total_bill(Quantity);
                football.view_total_amount(); d:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto d;
}
            }
            else if(choice==2)
            {
                cout<<"Price=2000"<<endl;

                cout<<"How many "<< jerssy.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                jerssy.get_total_bill(Quantity);
                jerssy.view_total_amount(); e:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto e;
}
            }
            else if(choice==3)
            {
                cout<<"Price=1200"<<endl;

                cout<<"How many "<< boot.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                boot.get_total_bill(Quantity);
                boot.view_total_amount(); f:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto f;
            }
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
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

                cout<<"How many "<< htc.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                htc.get_total_bill(Quantity);
                htc.view_total_amount(); g:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto g;
}
            }
            else if(choice==2)
            {
                cout<<"Price=60000"<<endl;

                cout<<"How many "<< iphone.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                iphone.get_total_bill(Quantity);
                iphone.view_total_amount(); h:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto h;
}
            }
            else if(choice==3)
            {
                cout<<"Price=25000"<<endl;

                cout<<"How many "<< walton.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                walton.get_total_bill(Quantity);
                walton.view_total_amount(); i:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto i;
}
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

                cout<<"How many "<< tv.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                tv.get_total_bill(Quantity);
                tv.view_total_amount(); j:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto j;
}
            }
            else if(choice==2)
            {
                cout<<"Price=100000"<<endl;

                cout<<"How many "<< ac.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                ac.get_total_bill(Quantity);
                ac.view_total_amount(); k:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto k;
}
            }
            else if(choice==3)
            {
                cout<<"Price=5000"<<endl;

                cout<<"How many "<< oven.get_product_name() <<  " do you want to buy"<<endl;
                int Quantity;
                cin>>Quantity;
                oven.get_total_bill(Quantity);
                oven.view_total_amount(); l:
                 cout<<"Do You Want to Buy More?"<<endl<< "1 : Yes" <<endl<< "2 : No" <<endl;
                cin>>choice;
                if(choice==1)
                goto buy;
                else if(choice==2)
                cout<<"Thank You"<<endl;
                else{
				
                cout<<"Invalid Input"<<endl;
                goto l;
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
            cout<<"invalid input!"<<endl<<"Try Again"<<endl;
        }
        
    }
}



