
class RoundTrip : public Flight{
    private:
        string return_date;

    public:
        char dep_flag,arr_flag;
        void read(){
            int choice,choice_arrival;

            cout<<endl<<endl<<"DEPART FROM : "<<endl;
            cout<<"Press 1 for Dhaka"<<endl;
            cout<<"Press 2 for Chittagong"<<endl;
            cout<<"Press 3 for Sylhet"<<endl;
            cout<<"Press 4 for Rangpur"<<endl;
            cout<<"Press 5 for Jessore"<<endl;
            cout<<endl<<endl<<"Your Choice is :";

            cin>>choice;

            if(choice == 1){
                    dep_flag = 'd';
                cout<<endl<<endl<<"Arrival CITY : "<<endl;

            cout<<"Press 1 for Chittagong"<<endl;
            cout<<"Press 2 for Sylhet"<<endl;
            cout<<"Press 3 for Rangpur"<<endl;
            cout<<"Press 4 for Jessore"<<endl;
            cout<<endl<<endl<<"Your Choice is :";

            cin>>choice_arrival;
            cin.ignore();

            if(choice_arrival == 1){
                    arr_flag = 'c';
                cout<<"chittagong"<<endl;

            }
            else if(choice_arrival == 2){
                    arr_flag = 's';
                cout<<"sylhet"<<endl;

            }
            else if(choice_arrival == 3){
                arr_flag = 'r';
                cout<<"Rangpur"<<endl;
            }
            else if(choice_arrival == 4){
                arr_flag = 'j';
                cout<<"Jessore"<<endl;
            }
            else{
                cout<<"invalid Choice"<<endl;
            }

        }
            else if (choice == 2){
                    dep_flag = 'c';
                    cout<<endl<<endl<<"Arrival CITY : "<<endl;
                    cout<<"Press 1 for Dhaka"<<endl;
                    cout<<"Press 2 for Sylhet"<<endl;
                    cout<<"Press 3 for Rangpur"<<endl;
                    cout<<"Press 4 for Jessore"<<endl;
                    cout<<endl<<endl<<"Your Choice is :";

            cin>>choice_arrival;
            cin.ignore();
            if(choice_arrival == 1){
                    arr_flag = 'd';
                cout<<"Dhaka"<<endl;

            }
            else if(choice_arrival == 2){
                    arr_flag = 's';
                cout<<"sylhet"<<endl;

            }
            else if(choice_arrival == 3){
                arr_flag = 'r';
                cout<<"Rangpur"<<endl;
            }
            else if(choice_arrival == 4){
                arr_flag = 'j';
                cout<<"Jessore"<<endl;
            }
            else{
                cout<<"invalid Choice"<<endl;
            }

            }
            else if(choice == 3){
                    dep_flag = 's';
                    cout<<endl<<endl<<"Arrival CITY : "<<endl;
                    cout<<"Press 1 for Dhaka"<<endl;
                    cout<<"Press 2 for Chittagong"<<endl;
                    cout<<"Press 3 for Rangpur"<<endl;
                    cout<<"Press 4 for Jessore"<<endl;
                    cout<<endl<<endl<<"Your Choice is :";

            cin>>choice_arrival;
            cin.ignore();
            if(choice_arrival == 1){
                    arr_flag = 'd';
                cout<<"dhaka"<<endl;

            }
            else if(choice_arrival == 2){
                    arr_flag = 'c';
                cout<<"chittagong"<<endl;
                }
            else if(choice_arrival == 3){
                    arr_flag = 'r';
                cout<<"Rangpur"<<endl;
            }
            else if(choice_arrival == 4){
                arr_flag = 'j';
                cout<<"Jessore"<<endl;
            }
            else{
                cout<<"invalid Choice"<<endl;
            }
            }

            else if(choice == 4){
                    dep_flag = 'r';

                cout<<endl<<endl<<"Arrival CITY : "<<endl;

            cout<<"Press 1 for Dhaka"<<endl;
            cout<<"Press 2 for Chittagong"<<endl;
            cout<<"Press 3 for Sylhet"<<endl;
            cout<<"Press 4 for Jessore"<<endl;
            cout<<endl<<endl<<"Your Choice is :";


            cin>>choice_arrival;
            cin.ignore();
            if(choice_arrival == 1){
                    arr_flag = 'd';
                cout<<"dhaka"<<endl;

            }
            else if(choice_arrival == 2){
                    arr_flag = 'c';
                cout<<"chittagong"<<endl;
                }
            else if(choice_arrival == 3){
                    arr_flag = 's';
                cout<<"Sylhet"<<endl;
            }
            else if(choice_arrival == 4){
                arr_flag = 'j';
                cout<<"Jessore"<<endl;
            }
            else{
                cout<<"invalid Choice"<<endl;
            }
            }
            else if(choice == 5){

                    dep_flag = 'j';

                cout<<endl<<endl<<"Arrival CITY : "<<endl;

            cout<<"Press 1 for Dhaka"<<endl;
            cout<<"Press 2 for Chittagong"<<endl;
            cout<<"Press 3 for Sylhet"<<endl;
            cout<<"Press 4 for Rangpur"<<endl;
            cout<<endl<<endl<<"Your Choice is :";


            cin>>choice_arrival;
            cin.ignore();
            if(choice_arrival == 1){
                    arr_flag = 'd';
                cout<<"dhaka"<<endl;

            }
            else if(choice_arrival == 2){
                    arr_flag = 'c';
                cout<<"chittagong"<<endl;
                }
            else if(choice_arrival == 3){
                    arr_flag = 's';
                cout<<"Sylhet"<<endl;
            }
            else if(choice_arrival == 4){
                arr_flag = 'r';
                cout<<"Rangpur"<<endl;
            }
            else{
                cout<<"invalid Choice"<<endl;
            }
            }

            else{
                cout<<endl<<endl<<"INVALID CHOICEE"<<endl;

        }

         Flight :: read();
         cout<<"Enter your returning date : ";
         getline(cin,return_date);

        }
        void display(){

        cout<<"your returning date is : "<<return_date<<endl<<endl;

        if(dep_flag == 'd' && arr_flag == 'c'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'd' && arr_flag == 's'){
            Flight :: rtdhtoshy();
        }
        else if(dep_flag == 'd' && arr_flag == 'r'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'd' && arr_flag == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'c' && arr_flag == 'd'){
            Flight :: displayrtCtodh();
        }
        else if(dep_flag == 'c' && arr_flag == 's'){
            Flight :: displayrtCtoSy();
        }
        else if(dep_flag == 'c' && arr_flag == 'r'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'c' && arr_flag == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 's' && arr_flag == 'd'){
            Flight ::rtshytodh();
        }
        else if(dep_flag == 's' && arr_flag == 'c'){
            Flight :: rtshytoctg();
        }
        else if(dep_flag == 's' && arr_flag == 'r'){
            Flight :: displayround1();
        }
        else if(dep_flag == 's' && arr_flag == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'r' && arr_flag == 'd'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'r' && arr_flag == 'c'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'r' && arr_flag == 's'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'r' && arr_flag == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 'd'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 'c'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 's'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 'r'){
            Flight :: displayround1();
        }
        }

        };
