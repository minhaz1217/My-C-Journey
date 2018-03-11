#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tc,day,caseCounter = 1;
    string str,str2,myStr[] = {"Pohela Falgun","Valentine's Day","International Mother Language Day","International Women's Day","International Color Day","Bangladesh Independence Day","April Fools Day","Pohela Boishakh","May Day","Father's Day","Mandela Day","World Mosquito Day","Halloween","World Toilet Day","Human Rights Day","Victory Day of Bangladesh","Christmas Day"};
    cin>> tc;
    cin.ignore();
    while(tc--)
    {
        cin >> str >> day;
        //cin >> str;
        cout << "Case " << caseCounter++<<": ";
        if((str == "February" && (day <13 ) ) || (str == "December" && day >25) || (str == "January") )
        {
            cout << "Pohela Falgun" << endl;
        }
        else if(str == "February" && day < 14)
        {
            cout << "Valentine's Day" << endl;
        }
        else if(str == "February" && day <21)
        {
            cout << "International Mother Language Day" << endl;
        }
        else if((str == "March" && day <8) || (str == "February" && day >=21))
        {
            cout << "International Women's Day" << endl;
        }
        else if(str == "March" && day <21)
        {
            cout << "International Color Day" << endl;
        }
        else if(str == "March" && day < 26)
        {
            cout << "Bangladesh Independence Day" << endl;
        }
        else if((str == "April" && day < 1) || (str == "March" && day >=26))
        {
            cout << "April Fools Day" << endl;
        }
        else if(str == "April" && day < 14)
        {
            cout << "Pohela Boishakh" << endl;
        }
        else if((str == "May" && day < 1) || (str == "April" && day >=14))
        {
            cout << "May Day" << endl;
        }
        else if((str == "June" && day < 19) || (str == "May" && day >=1))
        {
            cout << "Father's Day" << endl;
        }
        else if((str == "July" && day < 18) || (str == "June" && day >=19))
        {
            cout << "Mandela Day" << endl;
        }
        else if((str == "August" && day < 20) || (str == "July" && day >=18))
        {
            cout << "World Mosquito Day" << endl;
        }
        else if((str == "October" && day < 31) || (str == "August" && day >=20) || (str == "September"))
        {
            cout << "Halloween" << endl;
        }
        else if((str == "November" && day < 19) || (str == "October"))
        {
            cout << "World Toilet Day" << endl;
        }
        else if((str == "December" && day < 10) || (str == "November" && day >=19))
        {
            cout << "Human Rights Day" << endl;
        }
        else if(str == "December" && day < 16)
        {
            cout << "Victory Day of Bangladesh" << endl;
        }
        else if(str == "December" && day < 25)
        {
            cout << "Christmas Day" << endl;
        }


    }
    return 0;
}
