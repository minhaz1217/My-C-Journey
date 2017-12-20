
class MultiCity : public Flight{
    private:
        string toFirstcity_date;
        string toSecondcity_date;
    public:
        char dep_flag, arr_flag, arr_flag2;
        void read(){
            int choice,choice_arrival,choice_arrival2;

            cout<<endl<<endl<<"DEPART FROM : "<<endl;
            cout<<"Press 1 for Dhaka"<<endl;
            cout<<"Press 2 for Chittagong"<<endl;
            cout<<"Press 3 for Sylhet"<<endl;
            cout<<"Press 4 for Jessore"<<endl;
            cout<<endl<<endl<<"Your Choice is :";

            cin>>choice;
            if(choice == 1){
                    dep_flag = 'd';
                cout<<endl<<endl<<"First Arrival CITY : "<<endl;

            cout<<"Press 1 for Chittagong"<<endl;
            cout<<"Press 2 for Sylhet"<<endl;
            cout<<"Press 3 for Jessore"<<endl;
            cout<<endl<<endl<<"Your Choice is :";

            cin>>choice_arrival;
            cin.ignore();

            if(choice_arrival == 1){
                    arr_flag = 'c';
                cout<<"chittagong"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Sylhet"<<endl;
                cout<<"Press 2 for Jessore"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 's';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 'j';
                }

            }
            else if(choice_arrival == 2){
                    arr_flag = 's';
                cout<<"sylhet"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Chittagong"<<endl;
                cout<<"Press 2 for Jessore"<<endl;
                    cin>>choice_arrival2;
                if(choice_arrival2 == 1){
                    arr_flag2 == 'c';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 'j';
                }

            }

            else if(choice_arrival == 3){
                    arr_flag = 'j';
                cout<<"Jessore"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Chittagong"<<endl;
                cout<<"Press 2 for Sylhet"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 'c';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 's';
                }

            }
            else{
                cout<<"invalid Choice"<<endl;
            }
        }
            else if (choice == 2){
                    dep_flag = 'c';
                    cout<<endl<<endl<<"First Arrival CITY : "<<endl;

            cout<<"Press 1 for Dhaka"<<endl;
            cout<<"Press 2 for Sylhet"<<endl;
            cout<<"Press 3 for Jessore"<<endl;
            cout<<endl<<endl<<"Your Choice is :";

            cin>>choice_arrival;
            cin.ignore();
            if(choice_arrival == 1){
                    arr_flag = 'd';
                    cout<<"dhaka"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Sylhet"<<endl;
                cout<<"Press 2 for Jessore"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 's';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 'j';
                }


            }
            else if(choice_arrival == 2){
                    arr_flag = 's';
                cout<<"sylhet"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Dhaka"<<endl;
                cout<<"Press 2 for Jessore"<<endl;

                    cin>>choice_arrival2;


                if(choice_arrival2 == 1){
                    arr_flag2 == 'd';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 'j';
                }

            }
            else if(choice_arrival == 3){
                    arr_flag = 'j';
                cout<<"jessore"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Dhaka"<<endl;
                cout<<"Press 2 for Sylhet"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 'd';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 's';
                }
            }
            else{
                cout<<"invalid Choice"<<endl;
            }

            }
            else if(choice == 3){
                    dep_flag = 's';
                    cout<<endl<<endl<<"First Arrival CITY : "<<endl;

            cout<<"Press 1 for Dhaka"<<endl;
            cout<<"Press 2 for Chittagong"<<endl;
            cout<<"Press 3 for Jessore"<<endl;
            cout<<endl<<endl<<"Your Choice is :";

            cin>>choice_arrival;
            cin.ignore();
            if(choice_arrival == 1){

                    arr_flag = 'd';

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Chittagong"<<endl;
                cout<<"Press 2 for Sylhet"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 'c';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 's';
                }

            }
            else if(choice_arrival == 2){
                    arr_flag = 'c';
                cout<<"chittagong"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Dhaka"<<endl;
                cout<<"Press 2 for Jessore"<<endl;

                if(choice_arrival2 == 1){
                    arr_flag2 == 'd';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 'j';
                }

                }

                else if(choice_arrival == 3){
                    arr_flag = 'j';
                cout<<"jessore"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Dhaka"<<endl;
                cout<<"Press 2 for Chittagong"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 'd';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 'c';
                }

                }

            else{
                cout<<"invalid Choice"<<endl;
            }
            }

            else if(choice == 4){
                    dep_flag = 'j';
                    cout<<endl<<endl<<"First Arrival CITY : "<<endl;

            cout<<"Press 1 for Dhaka"<<endl;
            cout<<"Press 2 for Chittagong"<<endl;
            cout<<"Press 3 for Sylhet"<<endl;
            cout<<endl<<endl<<"Your Choice is :";

            cin>>choice_arrival;
            cin.ignore();
            if(choice_arrival == 1){

                    arr_flag = 'd';

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Chittagong"<<endl;
                cout<<"Press 2 for Sylhet"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 'c';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 's';
                }

            }
            else if(choice_arrival == 2){
                    arr_flag = 'c';
                cout<<"chittagong"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Dhaka"<<endl;
                cout<<"Press 2 for Sylhet"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 'd';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 's';
                }

                }

                else if(choice_arrival == 3){
                    arr_flag = 's';
                cout<<"jessore"<<endl;

                cout<<endl<<endl<<"Second Arrival City"<<endl<<endl;
                cout<<"Press 1 for Dhaka"<<endl;
                cout<<"Press 2 for Chittagong"<<endl;

                cin>>choice_arrival2;

                if(choice_arrival2 == 1){
                    arr_flag2 == 'd';
                    }
                else if(choice_arrival2 == 2){
                    arr_flag2 == 'c';
                }

                }

            else{
                cout<<"invalid Choice"<<endl;
            }
            }
            else{
                cout<<endl<<endl<<"INVALID CHOICEE"<<endl;

        }

         Flight :: read();
         cin.ignore();
         cout<<"Enter your second departing date : ";
         getline(cin,toFirstcity_date);
         cin.ignore();
         cout<<"Enter your last departing date : ";
         cin.ignore();
         getline(cin,toSecondcity_date);


        }
        void display(){

            Flight :: display();

        cout<<"your second departing date is : "<<toFirstcity_date<<endl<<endl;
        cout<<"your last departing date is : "<<toSecondcity_date<<endl<<endl;

        if(dep_flag == 'd' && arr_flag == 'c' && arr_flag2 == 's'){
         Flight :: d_C_S();
        }
        else if(dep_flag == 'd' && arr_flag == 'c' && arr_flag2 == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'd' && arr_flag == 's' && arr_flag2 == 'c'){
            Flight ::d_s_c();
        }
        else if(dep_flag == 'd' && arr_flag == 's' && arr_flag2 == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'd' && arr_flag == 'j' && arr_flag2 == 'c'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'd' && arr_flag == 'j' && arr_flag2 == 's'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'c' && arr_flag == 'd' && arr_flag2 == 's'){
            Flight :: c_d_s();
        }
        else if(dep_flag == 'c' && arr_flag == 'd' && arr_flag2 == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'c' && arr_flag == 's' && arr_flag2 == 'd'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'c' && arr_flag == 's' && arr_flag2 == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'c' && arr_flag == 'j' && arr_flag2 == 'd'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'c' && arr_flag == 'j' && arr_flag2 == 's'){
            Flight :: displayround1();
        }
        else if(dep_flag == 's' && arr_flag == 'd' && arr_flag2 == 'c'){
            Flight :: s_d_c();
        }
        else if(dep_flag == 's' && arr_flag == 'd' && arr_flag2 == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 's' && arr_flag == 'c' && arr_flag2 == 'd'){
            Flight ::  s_c_d();
        }
        else if(dep_flag == 's' && arr_flag == 'c' && arr_flag2 == 'j'){
            Flight :: displayround1();
        }
        else if(dep_flag == 's' && arr_flag == 'j' && arr_flag2 == 'd'){
            Flight :: displayround1();
        }
        else if(dep_flag == 's' && arr_flag == 'j' && arr_flag2 == 'c'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 'd' && arr_flag2 == 'c'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 'd' && arr_flag2 == 's'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 'c' && arr_flag2 == 'd'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 'c' && arr_flag2 == 's'){
            Flight :: displayround1();
        }
        else if(dep_flag == 'j' && arr_flag == 's' && arr_flag2 == 'd'){
            Flight :: displayround1();
        }else if(dep_flag == 'j' && arr_flag == 's' && arr_flag2 == 'c'){
            Flight :: displayround1();
        }

        }

        };

