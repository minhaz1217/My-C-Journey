#include<iostream>
using namespace std;
int main(){
    int len,arrCounter = 0;
    string phone,act,arr[10000];
    for(;;){
        getline(cin, phone);
        if(cin.eof()){
            break;
        }
        act = phone;
        for(len=0;phone[len];len++){
            if(phone[len] == 'A' ||phone[len] == 'B' ||phone[len] == 'C'){
                act[len] = '2';
            }else if(phone[len] == 'D' ||phone[len] == 'E' ||phone[len] == 'F'){
                act[len] = '3';
            }else if(phone[len] == 'G' ||phone[len] == 'H' ||phone[len] == 'I'){
                act[len] = '4';
            }else if(phone[len] == 'J' ||phone[len] == 'K' ||phone[len] == 'L'){
                act[len] = '5';
            }else if(phone[len] == 'M' ||phone[len] == 'N' ||phone[len] == 'O'){
                act[len] = '6';
            }else if(phone[len] == 'P' ||phone[len] == 'Q' ||phone[len] == 'R' || phone[len] == 'S'){
                act[len] = '7';
            }else if(phone[len] == 'T' ||phone[len] == 'U' ||phone[len] == 'V'){
                act[len] = '8';
            }else if(phone[len] == 'W' ||phone[len] == 'X' ||phone[len] == 'Y' || phone[len] == 'Z'){
                act[len] = '9';
            }
        }
    arr[arrCounter] = act;
    arrCounter++;
    }
    for(len=0;len<arrCounter;len++){
        cout << arr[len] << endl;
    }
	return 0;
}
