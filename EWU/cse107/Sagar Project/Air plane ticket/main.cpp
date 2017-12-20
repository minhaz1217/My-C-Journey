#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

#include "Airlines.h"

#include "Seats.h"

#include "Flight.h"

#include "Oneway.h"

#include "RoundTrip.h"

#include "MultiCity.h"



int main(){


int choice_root ;



    for( ; ;){
        cout<<setw(50)<<"WELCOME TO OUR AIRLINES "<<endl<<endl<<endl<<endl<<endl;

        int in = 0;
        for( ; ;){
                cout<<endl<<endl<<endl<<"Press 1 for one way"<<endl;
                cout<<"press 2 for round trip"<<endl;
                cout<<"Press 3 for multi city"<<endl;
                cout<<"Press 0 for exit"<<endl;
                cout<<endl<<endl<<"your choice is : ";
            cin>>choice_root;

            if(choice_root == 1){

                Flight* F1[100];
                F1[in] = new Oneway;

                F1[in] -> read();
                F1[in] -> display();
                in++;
                }
            else if(choice_root == 2){
                Flight* F1[100];
                F1[in] = new RoundTrip;
                F1[in] -> read();
                F1[in] -> display();
                in++;

            }
            else if(choice_root == 3){
                Flight* F1[100];
                F1[in] = new MultiCity;
                F1[in] -> read();
                F1[in] -> display();
                in++;
            }
            else if(choice_root == 0){
                exit(0);
            }
            else{
                cout<<"Invalid choice. Enter Again"<<endl;
                continue;
            }
            }
            }

    return 0;
}

