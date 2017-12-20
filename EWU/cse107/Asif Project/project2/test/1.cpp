#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char choice;
    string seat[60];
    int i=0, counter=0, flag=0;
    for(i=0;i<60;i++){
        seat[i]= "00";
    }
    string seatChoice;
    string seatTaken;
    ifstream infile("test.txt");
    getline(infile, seatTaken);
    infile.close();
    cout << seatTaken << endl;
    for(i=0;seatTaken[i];i+= 3){
        seat[counter][0] = seatTaken[i];
        seat[counter][1] = seatTaken[i+1];
        counter++;
    }
    ofstream outfile("test.txt", ios::app);
    while(choice != 'n'){
        cout << "Enter what seat you want to take: ";
        cin >> seatChoice;
        flag = 1;
        for(i=0;i<counter-1;i++){
            if(seat[i] == seatChoice){
                cout << "Sorry Seat Booked, Please choose another." << endl;
                flag = 0;
                break;
            }
        }
        if(flag != 0){
            cout << "Seat has been booked at: " << seatChoice << endl;
            outfile << seatChoice << " ";
        }
        cout << "Do you want to enter more?: ";
        cin >> choice;
        if(choice != 'y'){
            break;
        }
    }
    outfile.close();

 return 0;
}
