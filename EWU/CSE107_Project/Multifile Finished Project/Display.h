#include<bits/stdc++.h>

//A display class that will handle the displays
class Display{
    Food *food;
    int arrSize;
    public:
    Display(Food *f1, int n=0){
        food =f1;
        arrSize = n;
    }
    Display(){}
    void display1(int goBack,int goBackPrev){
        // goBack 1 = selectFood
        int i;
        int choice,counter=0;
        float calorie;
        char repeatChoice='y';
        while(repeatChoice != 'n' && repeatChoice != 'N'){
            clearScreen();
            for(i=0;i<arrSize;i++){
                cout << i+1 <<". ";
                food[i].display1();
                cout << endl;
            }
            cout << i+1 << ". " << "Enter manually" << endl;
            i++;
            cout << i+1 << ". " << "Go Back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if(choice <0 || choice > arrSize+2){
                continue;
            }
            if(choice == i){
                cout << "How much calorie did you consume: ";
                cin >> calorie;
                totalCalorie +=calorie;
                cout << "You've gained: " << calorie << endl;
            }else if(choice == i+1){//the go back choice
                repeatChoice = 'n';
                break;
            }else{
                food[choice-1].display2();
                cin >> counter;
                totalCalorie += counter *(food[choice-1].getCalorieCount());
                cout << "You've gained: " << counter * (food[choice-1]).getCalorieCount() << endl;
            }
            cout << "Do you enter more?(y/n): ";
            cin >> repeatChoice;
        }
        if(goBack == 0){
            basicChoices1();
        }else if(goBack == 2){
            this->displayCalorieInOrOut(0);
        }else if(goBack == 3){
            selectFood1(goBackPrev);
        }
    }
    void displayExercise1(int goBack){
        int exChoice;
        char exChoiceMore = 'y';
        int exCounter;
        while(exChoiceMore != 'n' && exChoiceMore != 'N'){
            clearScreen();
            cout << "1. Walking"<< endl;
            cout << "2. Runing" << endl;
            cout << "3. Swimming" << endl;
            cout << "4. Exercising" << endl;
            cout << "5. Enter manually" << endl;
            cout << "6. Go Back" << endl;
            cout << "Enter your choice: ";
            cin >> exChoice;
            if(exChoice < 1 || exChoice > 6){
                continue;
            }else if(exChoice == 1){
                cout << "How long did you walk?(min): ";
                cin >> exCounter;
                totalCalorieUsed += 7 * static_cast<float>(exCounter);
                cout << "You've lost: " << 7 * static_cast<float>(exCounter) << endl;
            }else if(exChoice == 2){
                cout << "How long did you run?(min): ";
                cin >> exCounter;
                totalCalorieUsed += 9.5 * static_cast<float>(exCounter);
                cout << "You've lost: " << 9.5 * static_cast<float>(exCounter) << endl;
            }else if(exChoice == 3){
                cout << "How long did you swim?(min): ";
                cin >> exCounter;
                totalCalorieUsed += 11.5 * static_cast<float>(exCounter);
                cout << "You've lost: " << 11.5 * static_cast<float>(exCounter) << endl;
            }else if(exChoice == 4){
                cout << "How long did you exercise?(min): ";
                cin >> exCounter;
                totalCalorieUsed += 13 * static_cast<float>(exCounter);
                cout << "You've lost: " << 13 * static_cast<float>(exCounter) << endl;
            }else if(exChoice == 5){
                cout << "How much calorie did you lose?: ";
                cin >> exCounter;
                totalCalorieUsed += static_cast<float>(exCounter);
                cout << "You've lost: " << static_cast<float>(exCounter) << endl;
            }else if(exChoice == 6){
                break;
            }
            cout << "Do you want to enter more?(y/n): ";
            cin >> exChoiceMore;
        }
        if(goBack == 0){
            basicChoices1();
        }else if(goBack == 2){
            this->displayCalorieInOrOut(0);
        }
    }
    void displayCalorieInOrOut(int goBack){
        int inoutChoice;
        clearScreen();
        cout << "1. Enter calorie intake" << endl;
        cout << "2. Enter calorie used" << endl;
        cout << "3. Compare" << endl;
        cout << "4. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> inoutChoice;
        if(inoutChoice<1 || inoutChoice>4){
            this->displayCalorieInOrOut(goBack);
        }else if(inoutChoice ==1){
            selectFood1(2);
        }else if(inoutChoice == 2){
            this->displayExercise1(2);
        }else if(inoutChoice == 3){
            p1->setCalorieTake(totalCalorie);
            p1->setCalorieUsed(totalCalorieUsed);
            p1->display();
            cout << endl;
            changeConsoleColor(colorContinue);
            cout << continueString << endl;
            pauseScreen();
            basicChoices1();

        }else if(inoutChoice == 4){
            if(goBack == 0){
                basicChoices1();
            }
        }
    }
    void selectFood1(int);
    void selectedNewUser(int);
    void selectedCurrentUser();
    void selectedAdvice();
    void clearScreen();
    void basicChoices1();
    void selectedLoadData();
    void selectedSaveData();
    void selectedExit();
    void pauseScreen();
    int checkPersonExists();
    int isPersonFemale();
    int isPersonMale();
    void selectedDisplay();
    void changeConsoleColor(int);
};
//Global Display classes
Display displayBreakfast,displayLunch,displayFruit, displaySnack,displayDrinks;
Display basic;

void Display::selectFood1(int goBack){
        clearScreen();
        int foodChoice1;//
        cout << "1. Breakfast" << endl;
        cout << "2. Launch/Dinner" << endl;
        cout << "3. Fruit" << endl;
        cout << "4. Snacks" << endl;
        cout << "5. Drinks" << endl;
        cout << "6. Enter manually" << endl;
        cout << "7. Go back" << endl;
        cout << "Enter your choice: ";
        cin >> foodChoice1;
        float calorieManual=0;
        if(foodChoice1 <0 || foodChoice1 >7){
            selectFood1(goBack);
        }else if(foodChoice1 == 1){
            displayBreakfast.display1(3,goBack);
        }else if(foodChoice1 == 2){
            displayLunch.display1(3,goBack);
        }else if(foodChoice1 == 3){
            displayFruit.display1(3,goBack);
        }else if(foodChoice1 == 4){
            displaySnack.display1(3,goBack);
        }else if(foodChoice1 == 5){
            displayDrinks.display1(3,goBack);
        }else if(foodChoice1 == 6){
            cout << "How much more calorie did you consume: ";
            cin >> calorieManual;
            totalCalorie += calorieManual;
        }else if(foodChoice1 == 7){
            if(goBack == 0){
                basicChoices1();
            }else if(goBack == 2){
                basic.displayCalorieInOrOut(0);
            }
        }
}
//MAIN MENU
void Display::basicChoices1(){
    clearScreen();
    int choice1;
    cout << "1. Advice" << endl;
    cout << "2. New User" << endl;
    cout << "3. Load Data" << endl;
    cout << "4. Save Data" << endl;
    cout << "5. Display" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice1;
    if(choice1 <1 || choice1 > 6){
        basicChoices1();
    }else if(choice1 == 1){
        selectedAdvice();
    }else if(choice1 == 2){
        selectedNewUser(0);
    }else if(choice1 == 3){
        selectedLoadData();
    }else if(choice1 == 4){
        selectedSaveData();
    }else if(choice1 == 5){
        selectedDisplay();
    }else if(choice1 == 6){
        selectedExit();
    }

}
//if the user selects ADVICE
void Display::selectedAdvice(){

    if( checkPersonExists() == 0 ){
        selectedNewUser(1);
    }
    basic.displayCalorieInOrOut(0);
}

//If the user selects NEW USER
void Display::selectedNewUser(int goBack){
    char c1;
    totalCalorie =0;
    totalCalorieUsed =0;
    if(checkPersonExists() == 1){
        changeConsoleColor(colorWarning);
        cout << "User exists! Are you sure you want to enter a new user?(y/n): ";
        cin >> c1;
        if(c1 == 'y' || c1=='Y'){
            cout << "Are you a Male or Female?(m/f): ";
            cin >> c1;
            if(c1 == 'f' || c1=='F'){
                p1 = new Female();
                p1->takePerson();
                p1->calculateBmr();
                p1->display();
            }else{
                p1= new Male();
                p1->takePerson();
                p1->calculateBmr();
                p1->display();
            }
        }
    }else{
        cout << "Are you a Male or Female?(m/f): ";
        cin >> c1;
        if(c1 == 'f' || c1=='F'){
            p1 = new Female();
            p1->takePerson();
            p1->calculateBmr();
            p1->display();
        }else{
            p1= new Male();
            p1->takePerson();
            p1->calculateBmr();
            p1->display();
        }
    }
    if(goBack == 0){
        basicChoices1();
    }else if(goBack == 1){
        selectedAdvice();
    }
}


//if the user selects LOAD
void Display::selectedLoadData(){
    // load gives error if we try to load just after the file
    clearScreen();
    string loadDataName;
    char genderChoice;
    cout << "Enter you name: ";
    cin.ignore();
    getline(cin, loadDataName);
    cout << "Enter the gender(m/f): ";
    cin >> genderChoice;
    string loadFileName = "saveof_" + loadDataName + ".dat";
    char loadFile[fileNameMax];
    ifstream inLoadFile;
    int i;
    for(i=0;loadFileName[i];i++){
            loadFile[i] = loadFileName[i];
    }
    loadFile[i] = '\0';
    inLoadFile.open(loadFile, ios::binary);
    if(!inLoadFile){
        changeConsoleColor(colorError);
        cout << "Sorry, The file couldn't be found." << endl;
        changeConsoleColor(colorContinue);
        cout << continueString << endl;
        inLoadFile.close();
        pauseScreen();
        basicChoices1();
    }else{
        inLoadFile.close();
        if(genderChoice == 'm' || genderChoice=='M'){
            p1 = new Male();
        }else if(genderChoice == 'f' || genderChoice == 'F'){
            p1 = new Female();
        }
        p1->loadFromFile(loadFileName);
        p1->display();
        changeConsoleColor(colorGood);
        cout << "File Loaded Successfully." << endl;
        changeConsoleColor(colorContinue);
        cout << continueString << endl;
        pauseScreen();
        basicChoices1();
    }
}
//if the user selects SAVE
void Display::selectedSaveData(){
    if(checkPersonExists() == 1){
        string saveFileName = "saveof_" + p1->getName() + ".dat";
        p1->saveToFile(saveFileName);
        cout << "File Saved For: " << p1->getName();
        if(isPersonMale() == 1){
            cout << " Gender: Male" << endl;
        }else if(isPersonFemale() == 1){
            cout << " Gender: Female" << endl;
        }
        p1->display();
        changeConsoleColor(colorContinue);
        cout << continueString << endl;
        pauseScreen();
        basicChoices1();
    }else{
        changeConsoleColor(colorContinue);
        cout << "You need to have some data to save...." << endl;
        pauseScreen();
        basicChoices1();
    }
}
//if the user selects DISPLAY
void Display::selectedDisplay(){
    if(checkPersonExists() == 1){
        p1->display();
        changeConsoleColor(colorContinue);
        cout << continueString << endl;
        pauseScreen();
        basicChoices1();
    }else{

        changeConsoleColor(colorError);
        cout << "You need to have some data to view. Try new user or advice." << endl;
        changeConsoleColor(colorContinue);
        cout << continueString << endl;
        pauseScreen();
        basicChoices1();
    }
}
// if the user selects EXIT
void Display::selectedExit(){
    char exitChoice;
    if(checkPersonExists() == 1){
        cout << "Do you want to save the entered data?(y/n): ";
        cin >> exitChoice;
        if(exitChoice == 'y' || exitChoice == 'Y'){
            string saveFileName = "saveof_" + p1->getName() + ".dat";
            p1->saveToFile(saveFileName);
            cout << "File Saved For: " << p1->getName();
            if(isPersonMale() == 1){
                cout << " Gender: Male" << endl;
            }else if(isPersonFemale() == 1){
                cout << " Gender: Female" << endl;
            }
            p1->display();
            changeConsoleColor(colorGood);
            cout << "Thank you for using Healthy Life. Have a nice day." << endl;
            changeConsoleColor(colorContinue);
            cout << "Press anything to Exit" << endl;
            pauseScreen();
        }else{
        }

    }else{
        changeConsoleColor(colorGood);
        cout << "Thank you for using Healthy Life. Have a nice day." << endl;
        changeConsoleColor(colorContinue);
        cout << "Press anything to exit....."<<endl;
        pauseScreen();
    }
}
//Small helpful functions
//checks if the person pointer is filled or not
int Display::checkPersonExists(){
    Male *mp1;
    Female *fp1;
    if( !( (mp1 = dynamic_cast<Male*>(p1) ) || (fp1 = dynamic_cast<Female*>(p1)) ) ){
        return 0;
    }else{
        return 1;
    }
}
// checks if the person is male
int Display::isPersonMale(){
    Male *mp1;
    if(mp1 = dynamic_cast<Male*>(p1)){
        return 1;
    }else{
        return 0;
    }
}
// checks if the person is female
int Display::isPersonFemale(){
    Female *fp1;
    if(fp1 = dynamic_cast<Female*>(p1)){
        return 1;
    }else{
        return 0;
    }
}

//clears screen and sets default layout
void Display::clearScreen(){
    system("cls");
    SetConsoleTitle("Healthy Life");
    changeConsoleColor(27);
    cout <<setw(40) << "" << endl;
    cout << "\t     HEALTHY LIFE\t\t" << endl;
    cout <<setw(40) << "" << endl;
    cout << endl;
    changeConsoleColor(colorDefault);
}
//pause the screen
void Display::pauseScreen(){
    char tempgetch = getch();
}
//change the color of the console
void Display::changeConsoleColor(int color){
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);
}
