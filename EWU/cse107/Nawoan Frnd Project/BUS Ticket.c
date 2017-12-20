#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

#define dash 80

FILE *f1;
char dis;
char name;
char seats[300], seat2;
char line;
char ch;
char taken[60][3];
int x;
int s1, i;
char seat_cond;
char dis;
int counter;
int i;
int busRent = 0;
int sit_num = 0;
void welcome();
int bus_in;
char seatBookedSuccessful[300];// = "";
int from, to;
//char taken[60];
char seat_choice[50];

int main()
{
    printf("\n\n\t\tWELCOME to Automation Of Transportation System \n\n");

    division();

    return 0;
}

void division()
{
    for(i=0; i<dash; i++)
    {
        printf("_");
    }
    printf("\nDeparture:\n");
    //cout << endl << "Departure:" << endl;
    printf("\n(1) for Dhaka\n(2) for Chittagong\n(3) for Sylhet\n\nEnter your choice: ");
    //cout << endl << "(1) for Dhaka" << endl << "(2) for Chittagong"
    // << endl << "(3) for Sylhet" << endl << endl << "Enter your choice: ";
    scanf("%d", &from);
    //cin >> from;
    for(i=0; i<dash; i++)
        printf("_");
    //cout << "_";




    if(from==1)
    {
        printf("\nDestination: \n\n(1) for Sylhet\n(2) for Chittagong\n");
        //cout << endl << "Destination: ";
        //cout << endl << endl << "(1) for Sylhet" << endl << "(2) for Chittagong" << endl;
    }
    else if(from==2)
    {
        printf("\nDestination: \n\n(1) for Dhaka\n");
        //cout << endl << "Destination: ";
        //cout << endl << endl << "(1) for Dhaka" << endl;
    }
    else if(from==3)
    {
        printf("\nDestination: \n\n(1) for Dhaka\n");
        //cout << endl << "Destination: ";
        //cout << endl << endl << "(1) for Dhaka" << endl;
    }
    else
    {

        printf("\n\nNot available, Input again\n\n");
        //cout << endl << endl << "Not available, Input again" << endl << endl;
        division();
    }


    printf("\n\nEnter your choice: ");
    //cout << endl << "Enter your choice: " ;
    scanf("%d", &to);
    //cin >> to;



    if (from==1 && to==1)
    {
        c_bus();
    }
    else if(from==1 && to==2)
    {
        c_bus();
    }
    else if(from==2 && to==1)
    {
        c_bus();
    }
    else if(from==3 && to==1)
    {
        c_bus();
    }
    else
    {

        printf("\n\nNot available, Input agian.\n");
        //cout << endl << endl << "Not available, Input agian." << endl;
        division();
    }
}

void c_bus()
{
    for(i=0; i<dash; i++)
        printf("_");
    //cout << "_";


    printf("\n\nChoose the bus you want to travel in:\n");
    //cout << endl << endl << "Choose the bus you want to travel in:" << endl;


    if(from==3 && to==1)
    {
        printf("\n(1) for Shohag Ac bus(500 tk/sit)\n(2) for Shohag Non-Ac bus (400 tk/sit)\n");
        printf("(3) for Hanif Ac bus (500 tk/sit) \n(4) for Hanif Non-Ac bus (400 tk/sit) \n");
        printf("(5) for Green Line bus (600 tk/sit\n");
        /*cout << endl << "(1) for Shohag Ac bus(500 tk/sit)" << endl
             << "(2) for Shohag Non-Ac bus (400 tk/sit) " << endl << "(3) for Hanif Ac bus (500 tk/sit)"
             << endl << "(4) for Hanif Non-Ac bus (400 tk/sit)" << endl
             << "(5) for Green Line bus (600 tk/sit)" << endl;*/
    }
    else if(from==1 && to==1)
    {
        printf("\n(1) for Shohag Ac bus(500 tk/sit)\n");
        printf("(2) for Shohag Non-Ac bus (400 tk/sit) \n(3) for Hanif Ac bus (500 tk/sit)");
        printf("\n(4) for Hanif Non-Ac bus (400 tk/sit) \n(5) for Green Line bus (600 tk/sit) \n");
        /*cout << endl << "(1) for Shohag Ac bus(500 tk/sit)" << endl
             << "(2) for Shohag Non-Ac bus (400 tk/sit) " << endl << "(3) for Hanif Ac bus (500 tk/sit)"
             << endl << "(4) for Hanif Non-Ac bus (400 tk/sit)" << endl
             << "(5) for Green Line bus (600 tk/sit)" << endl;*/
    }
    else if(from==1 && to==2)
    {
        printf("\n(1) for Shohag Ac bus(600 tk/sit) \n(2) for Shohag Non-Ac bus (500 tk/sit) \n");
        printf("(3) for Hanif Ac bus (600 tk/sit) \n(4) for Hanif Non-Ac bus (500 tk/sit) \n");
        printf("(5) for Green Line bus (700 tk/sit) \n");
        /* cout << endl << "(1) for Shohag Ac bus(600 tk/sit)" << endl
              << "(2) for Shohag Non-Ac bus (500 tk/sit) " << endl << "(3) for Hanif Ac bus (600 tk/sit)"
              << endl << "(4) for Hanif Non-Ac bus (500 tk/sit)" << endl
              << "(5) for Green Line bus (700 tk/sit)" << endl;*/
    }
    else if(from==2 && to==1)
    {
        printf("\n(1) for Shohag Ac bus(600 tk/sit) \n(2) for Shohag Non-Ac bus (500 tk/sit) \n");
        printf("(3) for Hanif Ac bus (600 tk/sit) \n(4) for Hanif Non-Ac bus (500 tk/sit) \n");
        printf("(5) for Green Line bus (700 tk/sit) \n");
        /*cout << endl << "(1) for Shohag Ac bus(600 tk/sit)" << endl
             << "(2) for Shohag Non-Ac bus (500 tk/sit) " << endl << "(3) for Hanif Ac bus (600 tk/sit)"
             << endl << "(4) for Hanif Non-Ac bus (500 tk/sit)" << endl
             << "(5) for Green Line bus (700 tk/sit)" << endl;*/
    }

    printf("\nEnter your choice: ");
    //cout << endl << "Enter your choice: ";
    scanf("%d", &bus_in);
    //cin >> bus_in;

    if (bus_in==1 || bus_in==3 || bus_in==5)
    {
        display_ac();
    }
    else if(bus_in==2 || bus_in==4)
    {
        display_non_ac();
    }
    else
    {
        printf("\n\nNot available, Input again \n");
        //cout << endl << endl << "Not available, Input again" << endl;
        c_bus();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Eikhan thk start kr
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display_ac()
{
    f1 = fopen("sit ac.txt","r");
    while(seat2!=EOF)
    {
        seat2 = getc(f1);
        putchar(seat2);
    }
    fclose(f1);
    /*ifstream myfile ("sit ac.txt");
    myfile.is_open();
    while ( getline (myfile,line) )
    {
        cout << line << endl;
    }
    myfile.close();*/


    printf("\nBooked sits are: ");
    if (from==1 && to==1 && bus_in==1)
    {
        f1 = fopen("booked_sit_s_ac_d2s.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_s_ac_d2s.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/

    }
    else if( from==1 && to==1 && bus_in==3)
    {
        f1 = fopen("booked_sit_h_ac_d2s.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;

        myfile.open("booked_sit_h_ac_d2s.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if ( from==1 && to==1 && bus_in==5)
    {
        f1 = fopen("booked_sit_gl_d2s.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_gl_d2s.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if ( from==1 && to==2 && bus_in==1)
    {
        f1 = fopen("booked_sit_s_ac_d2c.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_s_ac_d2c.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==1 && to==2 && bus_in==3)
    {
        f1 = fopen("booked_sit_h_ac_d2c.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_h_ac_d2c.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/

    }
    else if ( from==1 && to==2 && bus_in==5)
    {
        f1 = fopen("booked_sit_gl_d2c.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*        ifstream myfile;
                myfile.open("booked_sit_gl_d2c.txt");
                cout << "Booked sits are: ";
                getline(myfile, seats);
                myfile.close();*/
    }
    else if ( from==2 && to==1 && bus_in==1)
    {
        f1 = fopen("booked_sit_s_ac_s2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_s_ac_s2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==2 && to==1 && bus_in==3)
    {
        f1 = fopen("booked_sit_h_ac_s2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_h_ac_s2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if ( from==2 && to==1 && bus_in==5)
    {
        f1 = fopen("booked_sit_gl_s2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_gl_s2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if ( from==3 && to==1 && bus_in==1)
    {
        f1 = fopen("booked_sit_s_ac_c2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_s_ac_c2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==3 && to==1 && bus_in==3)
    {
        f1 = fopen("booked_sit_h_ac_c2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_h_ac_c2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if ( from==3 && to==1 && bus_in==5)
    {
        f1 = fopen("booked_sit_gl_c2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_gl_c2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    printf("\n\n");
    select();
}


void display_non_ac()
{
    f1 = fopen("sit non ac.txt","r");
    while(seat2!=EOF)
    {
        seat2 = getc(f1);
        putchar(seat2);
    }
    fclose(f1);

    /*ifstream myfile ("sit non ac.txt");
    myfile.is_open();
    while ( getline (myfile,line) )
    {
        cout << line << endl;
    }
    myfile.close();*/

    printf("\nBooked sits are: ");
    if( from==1 && to==1 && bus_in==2)
    {
        f1 = fopen("booked_sit_s_non_ac_d2s.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_s_non_ac_d2s.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/

    }
    else if( from==1 && to==1 && bus_in==4)
    {
        f1 = fopen("booked_sit_h_non_ac_d2s.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_h_non_ac_d2s.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==1 && to==2 && bus_in==2)
    {
        f1 = fopen("booked_sit_s_non_ac_d2c.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_s_non_ac_d2c.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==1 && to==2 && bus_in==4)
    {
        f1 = fopen("booked_sit_h_non_ac_d2c.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_h_non_ac_d2c.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==2 && to==1 && bus_in==2)
    {
        f1 = fopen("booked_sit_s_non_ac_s2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_s_non_ac_s2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==2 && to==1 && bus_in==4)
    {
        f1 = fopen("booked_sit_h_non_ac_s2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_h_non_ac_s2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==3 && to==1 && bus_in==2)
    {
        f1 = fopen("booked_sit_s_non_ac_c2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_s_non_ac_c2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    else if( from==3 && to==1 && bus_in==4)
    {
        f1 = fopen("booked_sit_h_non_ac_c2d.txt","r");
        fgets(seats,300,f1);
        printf("%s", seats);
        fclose(f1);
        /*ifstream myfile;
        myfile.open("booked_sit_h_non_ac_c2d.txt");
        cout << "Booked sits are: ";
        getline(myfile, seats);
        myfile.close();*/
    }
    printf("\n\n");
    //cout << seats << endl;


    select();
}


void select()
{

    counter = 0;
    for(i=0; i<60; i++)
    {
        taken[i][0]='0';
        taken[i][1]='0';
    }

    for(i=0; seats[i]; i+=3)
    {
        taken[counter][0]=seats[i];
        taken[counter][1]=seats[i+1];
        taken[counter][2] = '\0';
        counter++;
    }
    //populating ended

    printf("\n\n");
    //cout << endl << endl;
    for(i=0; i<dash; i++)
        printf("_");
    //cout << "_";

    printf("\n\n");
    //cout << endl << endl;

    printf("\n\nEnter the serial of the sit you want: ");
    //cout << endl << endl << "Enter the serial of the sit you want: ";

    //error 1
    //getchar();
    //cin.ignore();
    //error 2
    //gets(seat_choice);
    //minhaz
    scanf("%s", &seat_choice);
    //getline(cin, seat_choice);

    //for(i = 0; i < sizeof(seat_choice); i++)
    //{
    //Minhaz1
    char newSeat[3] = {toupper(seat_choice[0]), toupper(seat_choice[1])};
    newSeat[2] = '\0';
    printf("%s", newSeat);
    //}



    // check seat taken here
    int flag  = 1; // if flag = 1 then seat is not taken, if 0 then seat is taken
    for(i=0; i<counter; i++)
    {   //minhaz2
        if(strcmp(taken[i], newSeat) == 0)
        {
            flag = 0;
            break;
        }
    }


    //checking if the seat_choice input is valid or not
    if(sizeof(newSeat) > 3)
    {
        flag = 3;
    }
    else
    {
        int first_key = newSeat[0], second_key = newSeat[1];
        //first key can be A-J(ascii 64-74) second key can be 1-4(ascii 49 - 52) depending on buses
        if( !(first_key >= 65 && first_key <=74) )
        {
            flag = 3;
        }
        else
        {
            if(bus_in==1 || bus_in==3 || bus_in==5)
            {
                if( !(second_key >=49 && second_key <= 51 ) )
                {
                    flag = 3;
                }
            }
            else if(bus_in == 2 || bus_in == 4)
            {
                if( !(second_key >= 49 && second_key <= 52 ) )
                {
                    flag = 3;
                }
            }
        }
    }

    if(flag == 0)
    {
        printf("\n\nSorry the seat is already been booked.\n");
        //cout << endl << endl << "Sorry the seat is already been booked." << endl;
    }
    else if(flag ==3)
    {
        printf("\n\nSorry the input is invalid. Enter valid seats.\n");
        //cout << endl << endl << "Sorry the input is invalid. Enter valid seats." << endl;
    }
    else if(flag == 1)
    {
        printf("\n\nThe seat is not booked.\n");
        //cout << endl << endl << "The seat is not booked." << endl;
        sit_num++;
        if ( from==1 && to==1 && bus_in==1)
        {
            f1 = fopen("booked_sit_s_ac_d2s.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_s_ac_d2s.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if( from==1 && to==1 && bus_in==2)
        {
            f1 = fopen("booked_sit_s_non_ac_d2s.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_s_non_ac_d2s.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if( from==1 && to==1 && bus_in==3)
        {
            f1 = fopen("booked_sit_h_ac_d2s.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_h_ac_d2s.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/

        }
        else if( from==1 && to==1 && bus_in==4)
        {
            f1 = fopen("booked_sit_h_non_ac_d2s.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_h_non_ac_d2s.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if ( from==1 && to==1 && bus_in==5)
        {
            f1 = fopen("booked_sit_gl_d2s.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_gl_d2s.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if ( from==1 && to==2 && bus_in==1)
        {
            f1 = fopen("booked_sit_s_ac_d2c.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_s_ac_d2c.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if( from==1 && to==2 && bus_in==2)
        {
            f1 = fopen("booked_sit_s_non_ac_d2c.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_s_non_ac_d2c.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }

        else if( from==1 && to==2 && bus_in==3)
        {
            f1 = fopen("booked_sit_h_ac_d2c.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_h_ac_d2c.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/

        }
        else if( from==1 && to==2 && bus_in==4)
        {
            f1 = fopen("booked_sit_h_non_ac_d2c.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_h_non_ac_d2c.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if ( from==1 && to==2 && bus_in==5)
        {
            f1 = fopen("booked_sit_gl_d2c.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_gl_d2c.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if ( from==2 && to==1 && bus_in==1)
        {
            f1 = fopen("booked_sit_s_ac_s2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_s_ac_s2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if( from==2 && to==1 && bus_in==2)
        {
            f1 = fopen("booked_sit_s_non_ac_s2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_s_non_ac_s2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }

        else if( from==2 && to==1 && bus_in==3)
        {
            f1 = fopen("booked_sit_h_ac_s2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_h_ac_s2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if( from==2 && to==1 && bus_in==4)
        {
            f1 = fopen("booked_sit_h_non_ac_s2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_h_non_ac_s2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if ( from==2 && to==1 && bus_in==5)
        {
            f1 = fopen("booked_sit_gl_s2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_gl_s2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if ( from==3 && to==1 && bus_in==1)
        {
            f1 = fopen("booked_sit_s_ac_c2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_s_ac_c2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if( from==3 && to==1 && bus_in==2)
        {
            f1 = fopen("booked_sit_s_non_ac_c2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_s_non_ac_c2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }

        else if( from==3 && to==1 && bus_in==3)
        {
            f1 = fopen("booked_sit_h_ac_c2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_h_ac_c2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/

        }
        else if( from==3 && to==1 && bus_in==4)
        {
             f1 = fopen("booked_sit_h_non_ac_c2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);
            /*ofstream myfile;
            myfile.open("booked_sit_h_non_ac_c2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        else if ( from==3 && to==1 && bus_in==5)
        {
            f1 = fopen("booked_sit_gl_c2d.txt","a");
            fprintf(f1, "%s ", newSeat);
            fclose(f1);

           /* ofstream myfile;
            myfile.open("booked_sit_gl_c2d.txt", ios::app);
            myfile << seat_choice << " " ;
            myfile.close();*/
        }
        printf("\n\nYour seat has been booked at: %s \n", newSeat);
        //cout << endl << endl <<"Your seat has been booked at: " << seat_choice << endl;
        // add seat booked for later use
        strcat(seatBookedSuccessful, newSeat);
        strcat(seatBookedSuccessful, " ");


//        seatBookedSuccessful.append(1, seat_choice[0]);
    //    seatBookedSuccessful.append(1, seat_choice[1]);
      //  seatBookedSuccessful.append(1, ' ');

}    }


/*    cout << endl << endl << "Do you want to enter more?(Y/N): ";
    cin >> dis;

    if(dis == 'Y' || dis == 'y')
    {
        select();
    }
    else
    {
        cout << endl;
        for(int i=0; i<dash; i++)
            cout << "_";
        cout << endl << "Quantity of seats = " << sit_num <<endl;
ticket:
        calculation();
    }
}


void calculation()
{
    cout << endl << endl;
    if(from==1 && to==1 && bus_in==2)
    {
        busRent = sit_num*400;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==1 && bus_in==4)
    {
        busRent = sit_num*400;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==3 && to==1 && bus_in==3)
    {
        busRent = sit_num*400;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==3 && to==1 && bus_in==4)
    {
        busRent = sit_num*400;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==1 && bus_in==1)
    {
        busRent = sit_num*500;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==1 && bus_in==3)
    {
        busRent = sit_num*500;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==2 && bus_in==2)
    {
        busRent = sit_num*500;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==2 && bus_in==4)
    {
        busRent = sit_num*500;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==3 && to==1 && bus_in==2)
    {
        busRent = sit_num*500;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==3 && to==1 && bus_in==3)
    {
        busRent = sit_num*500;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==2 && to==1 && bus_in==2)
    {
        busRent = sit_num*500;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==2 && to==1 && bus_in==4)
    {
        busRent = sit_num*500;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==1 && bus_in==5)
    {
        busRent = sit_num*600;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==2 && bus_in==1)
    {
        busRent = sit_num*600;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==2 && bus_in==3)
    {
        busRent = sit_num*600;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==3 && to==1 && bus_in==5)
    {
        busRent = sit_num*600;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==2 && to==1 && bus_in==1)
    {
        busRent = sit_num*600;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==2 && to==1 && bus_in==3)
    {
        busRent = sit_num*600;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==1 && to==2 && bus_in==5)
    {
        busRent = sit_num*700;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else if(from==2 && to==1 && bus_in==5)
    {
        busRent = sit_num*700;
        cout << endl << "Total ticket price is: " << busRent << endl;
    }
    else
    {
        cout << "invalid!!";
    }

    cout << endl << endl << "Do you want to buy the tickets(Y/N): ";
    cin>>dis;

    cout << endl << endl;
    for(int i=0; i<dash; i++)
        cout << "_";

    if(dis=='y' || dis=='Y')
    {
        cout << endl << endl << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << endl << endl;
        for(int i=0; i<dash; i++)
            cout << "_";

        cout << endl << endl << "Name: " << name << endl << "Booked seats: " << seatBookedSuccessful;

        cout << endl << endl << "\t\t\t THANK YOU" << endl << endl;
        exit (0);
    }
    else
    {
        printf("\n\n\t\t\t THANK YOU \n\n");
        exit(0);
    }*/
//}
