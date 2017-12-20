#include<iostream>
using namespace std;
main(){
    int choice, seats[10],i,bClassCount=0, eClassCount=0;
    for(i=0;i<10;i++){
        seats[i] = 0;
    }
    for(i=0;i<20;i++){
        if(bClassCount >= 5 && eClassCount >= 5){
            cout << "All Seats have been filled in. Have a nice day.";
            break;
        }
        cout << "Press 1 for Business Class\nPress 2 for Economy Class: ";
        cin >> choice;
        if(choice == 1){
            if(bClassCount >=5){
                cout << "Business class is full. Will Economy Class be acceptable?\nPress 1 for YES\nPress 2 for NO: ";
                cin >> choice;
                if(choice == 1){
                    if(eClassCount >= 5){
                        cout << "Economy Class is full too.";
                        break;
                    }else{
                        eClassCount++;
                        seats[eClassCount + 4] = 1;
                        cout << "Your seat number is: "<< eClassCount+4 << ". It is Economy Class seat\n";
                    }
                }else{
                    cout << "Next flight leaves in 3 hours\n";
                }
            }else{
                bClassCount++;
                seats[bClassCount-1] = 1;
                cout << "Your seat number is: "<< bClassCount-1 << ". It is Business Class seat\n";

            }
        }else if(choice == 2){
            if(eClassCount >=5){
                cout << "Economy class is full. Will Business Class be acceptable?\nPress 1 for YES\nPress 2 for NO: ";
                cin >> choice;
                if(choice == 1){
                    if(bClassCount >= 5){
                        cout << "Business Class is full too.";
                        break;
                    }else{
                        bClassCount++;
                        seats[bClassCount -1] = 1;
                        cout << "Your seat number is: "<< bClassCount-1 <<". It is Business Class seat\n";
                    }

                }else{
                    cout << "Next flight leaves in 3 hours\n";
                }
            }else{
                eClassCount++;
                seats[eClassCount+4] = 1;
                cout << "Your seat number is: "<< eClassCount+4 <<". It is Economy Class seat\n";

            }
        }

    }


}
