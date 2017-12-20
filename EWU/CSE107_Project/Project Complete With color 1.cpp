#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
using namespace std;
#define check(a) cout<<a<< endl;
//prototyping
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
//class prototypes
class Display; //for the friend access modifier
//global variables
float totalCalorie = 0;
float totalCalorieUsed = 0;
int fileNameMax = 1000;
int colorDefault = 15;
int colorContinue = 11;
int colorError = 12;
int colorWarning = 14;
int colorGood = 10;
string continueString = "Press anything to continue.....";

// a class that will handling the input for different food types
class Food{
private:
    string name;
    int calorieShow;
    float calorieCount;
    string quantity[3];
    // quantity[0] = many/much
    // quantity[1] = cup/PCS/100gram
public:
    Food(string n="", int cs = 0, float cc=0, string q1 = "", string q2 = "", string q3=""){
        name = n;
        calorieShow = cs;
        calorieCount = cc;
        quantity[0] = q1;
        quantity[1] = q2;
        quantity[2] = q3;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    int getCalorieShow(){
        return calorieShow;
    }
    void setCalorieShow(int cs){
        calorieShow = cs;
    }
    float getCalorieCount(){
        return calorieCount;
    }
    void setCalorieCount(float cc){
        calorieCount = cc;
    }
    string getQuantity1(){
        return quantity[0];
    }
    void setQuantity1(string q1){
        quantity[0] = q1;
    }
    string getQuantity2(){
        return quantity[1];
    }
    void setQuantity2(string q2){
        quantity[1] = q2;
    }
    string getQuantity3(){
        return quantity[2];
    }
    void setQuantity3(string q3){
        quantity[2] = q3;
    }
    void display1(){
        cout << name << " " << calorieShow << "calorie/" << quantity[2] << quantity[1];
    }
    void display2(){
        cout << "How " << quantity[0] << " " << name << " did you eat(" << quantity[1] << "): ";
    }
    friend class Display;
};
//Global Food classes
Food f[39];
Food breakfast[8];
Food lunch[10];
Food fruit[7];
Food snack[9];
Food drinks[5];
class Calorie{
private:
    float calorieTake;
    float calorieUsed;
    float calculatedCalorie;
public:
    Calorie(float ct=0, float cu=0, float c1=0):calorieTake(ct), calorieUsed(cu),calculatedCalorie(c1){}
    float getCalorieTake(){
        return calorieTake;
    }
    void setCalorieTake(float ct){
        calorieTake = ct;
    }
    float getCalorieUsed(){
        return calorieUsed;
    }
    void setCalorieUsed(float cu){
        calorieUsed = cu;
    }
    float getCalculatedCalorie(){
        return calculatedCalorie;
    }
    void setCalculatedCalorie(float c1){
        calculatedCalorie = c1;
    }
    void calculateCalorie(int bmr){
        calculatedCalorie = getCalorieTake() - bmr - getCalorieUsed();
    }
    void displayCalorie(){
        if(calculatedCalorie >= 0){
            cout << "You've gained " << calculatedCalorie << " calorie.";
        }else if(calculatedCalorie<0){
            cout << "You've lost " << calculatedCalorie*-1 << " calorie.";
        }
    }
};


class Height{
private:
    int foot, inches;
public:
    Height(int f, int i){
        foot = f;
        inches = i;
        this->roundNumbers();
    }
    int getFoot(){
        return foot;
    }
    int getInches(){
        return inches;
    }
    void setFoot(int f){
        foot = f;
    }
    void setInches(int i){
        inches = i;
    }
    void takeFoot(){
        cout << "Enter your height(feet): ";
        cin >> foot;
    }
    void takeInches(){
        cout << "Enter your height (inches): ";
        cin >> inches;
    }
    float convertToCm(){
        float cm = 2.54 * (foot * 12 + inches);
        return cm;
    }
    void takeHeight(int a=0){
        if(a==0){//get height in a single line
            cout << "Enter your height(feet inches): ";
            cin >> foot >> inches;
        }else if(a==1){//get height in 2 line
            this->takeFoot();
            this->takeInches();
        }
    }
    void roundNumbers(){
        if(inches >= 12){
            foot = foot + (inches/12);
            inches = inches %12;
        }
    }
    void display(){
        cout << foot << "`" << inches << "``" << endl;
    }
};
class Person: public Height{
private:
    string name;
    int age;
    int weight;
public:
    Person(string n="", int a=0,int w=0, int f=0, int i=0):Height(f, i){
        name = n;
        age = a;
        weight = w;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    void takeName(){
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin , name);
    }
    int getAge(){
        return age;
    }
    void setAge(int a){
        age = a;
    }
    void takeAge(){
        cout << "Enter your age: ";
        cin >> age;
    }
    int getWeight(){
        return weight;
    }
    void setWeight(int w){
        weight = w;
    }
    void takeWeight(){
        cout << "Enter your weight: ";
        cin >> weight;
    }
    void takePerson(){
        this->takeName();
        this->takeAge();
        this->takeWeight();
        this->takeHeight();
    }
    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
        cout << "Height: ";
        Height::display();
    }
    virtual void calculateBmr(){};

    virtual float getCalorieTake(){};
    virtual void setCalorieTake(float ct){};
    virtual float getCalorieUsed(){};
    virtual void setCalorieUsed(int cu){};
    virtual void compare(){};
    virtual void saveToFile(string) =0;
    virtual void loadFromFile(string) =0;
};
/*
// Basic Metabolic Rate:
// BMR for male: 10*weight + 6.25*height(cm) - 5*age(years) + 5
// BMR for female 10*wight + 6.25*height(cm) - 5*age - 161;
*/
class Male: public Person,public Calorie{
private:
    float malebmr;
public:
    Male(string n="",int a=0, int w=0,int f=0,int i=0,float ct=0, float cu=0):Person(n,a,w,f,i), Calorie(ct, cu){
        malebmr =( 10*w + (6.25 * Height::convertToCm()) - 5*a )+ 5;
    }
    //calculates the male bmr using the bmr calculation for males
    void calculateBmr(){

        malebmr = 10 * getWeight() + 6.25 * Height::convertToCm() - 5*getAge() + 5;
    }
    float getBmr(){
        this->calculateBmr();
        return malebmr;
    }
    float getCalorieTake(){
        return Calorie::getCalorieTake();
    }
    void setCalorieTake(float ct){
        Calorie::setCalorieTake(ct);
    }
    float getCalorieUsed(){
        return Calorie::getCalorieUsed();
    }
    void setCalorieUsed(int cu){
        Calorie::setCalorieUsed(cu);
    }
    void compare(){
        Calorie::calculateCalorie(this->getBmr());
    }
    void display(){
        Person::display();
        cout << "Gender: Male" << endl;
        cout << "Your BMR: " << malebmr << endl;
        cout << "Calorie Used: " << this->getCalorieUsed() << endl;
        cout << "Calorie Taken: " << this->getCalorieTake()<< endl;
        this->compare();
        Calorie::displayCalorie();
        cout << endl;
    }
    void saveToFile(string fileName){
        char saveFile[fileNameMax];
        int i;
        for(i=0;fileName[i];i++){
            saveFile[i] = fileName[i];
        }
        saveFile[i] = '\0';
        ofstream outSaveFile;
        outSaveFile.open(saveFile, ios::binary);
        outSaveFile << getName() << endl;
        outSaveFile << getAge() << endl;
        outSaveFile << getWeight() << endl;
        outSaveFile << getFoot() << endl;
        outSaveFile << getInches() << endl;
        outSaveFile << getCalorieTake() << endl;
        outSaveFile << getCalorieUsed() << endl;
        outSaveFile.close();
    }
    void loadFromFile(string fileName){
        char loadFile[fileNameMax];
        string n;
        int i,a,w,f,inc;
        float ct, cu, cc;
        for(i=0;fileName[i];i++){
            loadFile[i] = fileName[i];
        }
        loadFile[i] = '\0';
        ifstream inLoadFile;
        inLoadFile.open(loadFile, ios::binary);
        inLoadFile >> n;
        setName(n);
        inLoadFile >> a ;
        setAge(a);
        inLoadFile >> w ;
        setWeight(w);
        inLoadFile >> f ;
        setFoot(f);
        inLoadFile >> inc ;
        setInches(inc);
        inLoadFile >> ct ;
        setCalorieTake(ct);
        inLoadFile >> cu ;
        setCalorieUsed(cu);
        inLoadFile.close();
        calculateBmr();
        Calorie::calculateCalorie(getBmr());
    }
};
class Female: public Person,public Calorie{
private:
    float femalebmr;
public:
    Female(string n="",int a=0, int w=0,int f=0,int i=0,float ct=0, float cu=0):Person(n,a,w,f,i), Calorie(ct, cu){
        femalebmr =( 10*w + (6.25 * Height::convertToCm()) - 5*a )-161;
    }
    void calculateBmr(){
        femalebmr = 10 * getWeight() + 6.25 * Height::convertToCm() - 5*getAge() -161;
    }
    float getBmr(){
        this->calculateBmr();
        return femalebmr;
    }
    float getCalorieTake(){
        return Calorie::getCalorieTake();
    }
    void setCalorieTake(float ct){
        Calorie::setCalorieTake(ct);
    }
    float getCalorieUsed(){
        return Calorie::getCalorieUsed();
    }
    void setCalorieUsed(int cu){
        Calorie::setCalorieUsed(cu);
    }
    void compare(){
        Calorie::calculateCalorie(this->getBmr());
    }
    void display(){
        Person::display();
        cout << "Gender: Female" << endl;
        cout << "Your BMR: " << femalebmr << endl;
        cout << "Calorie Used: " << this->getCalorieUsed() << endl;
        cout << "Calorie Taken: " << this->getCalorieTake()<< endl;
        this->compare();
        Calorie::displayCalorie();
        cout << endl;
    }
    void saveToFile(string fileName){
        char saveFile[fileNameMax];
        int i;
        for(i=0;fileName[i];i++){
            saveFile[i] = fileName[i];
        }
        saveFile[i] = '\0';
        ofstream outSaveFile;
        outSaveFile.open(saveFile, ios::binary);
        outSaveFile << getName() << endl;
        outSaveFile << getAge() << endl;
        outSaveFile << getWeight() << endl;
        outSaveFile << getFoot() << endl;
        outSaveFile << getInches() << endl;
        outSaveFile << getCalorieTake() << endl;
        outSaveFile << getCalorieUsed() << endl;
        outSaveFile.close();
    }
    void loadFromFile(string fileName){
        char loadFile[fileNameMax];
        string n;
        int i,a,w,f,inc;
        float ct, cu, cc;
        for(i=0;fileName[i];i++){
            loadFile[i] = fileName[i];
        }
        loadFile[i] = '\0';
        ifstream inLoadFile;
        inLoadFile.open(loadFile, ios::binary);
        inLoadFile >> n;
        setName(n);
        inLoadFile >> a ;
        setAge(a);
        inLoadFile >> w ;
        setWeight(w);
        inLoadFile >> f ;
        setFoot(f);
        inLoadFile >> inc ;
        setInches(inc);
        inLoadFile >> ct ;
        setCalorieTake(ct);
        inLoadFile >> cu ;
        setCalorieUsed(cu);
        inLoadFile.close();
        calculateBmr();
        Calorie::calculateCalorie(getBmr());
    }
};
Person *p1;

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
            }else if(choice == i+1){
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
};
//Global Display classes
Display displayBreakfast,displayLunch,displayFruit, displaySnack,displayDrinks;
Display basic;

void selectFood1(int goBack){
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
void basicChoices1(){
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
void selectedAdvice(){

    if( checkPersonExists() == 0 ){
        selectedNewUser(1);
    }
    basic.displayCalorieInOrOut(0);
}

//If the user selects NEW USER
void selectedNewUser(int goBack){
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
        }// if else then go back
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
    // give choice to edit any data
    if(goBack == 0){
        basicChoices1();
    }else if(goBack == 1){
        selectedAdvice();
    }
}


//if the user selects LOAD
void selectedLoadData(){
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
void selectedSaveData(){
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
void selectedDisplay(){
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
void selectedExit(){
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
int checkPersonExists(){
    Male *mp1;
    Female *fp1;
    if( !( (mp1 = dynamic_cast<Male*>(p1) ) || (fp1 = dynamic_cast<Female*>(p1)) ) ){
        return 0;
    }else{
        return 1;
    }
}
// checks if the person is male
int isPersonMale(){
    Male *mp1;
    if(mp1 = dynamic_cast<Male*>(p1)){
        return 1;
    }else{
        return 0;
    }
}
// checks if the person is female
int isPersonFemale(){
    Female *fp1;
    if(fp1 = dynamic_cast<Female*>(p1)){
        return 1;
    }else{
        return 0;
    }
}

//clear screen
void clearScreen(){
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
void pauseScreen(){
    char tempgetch = getch();
}
//change the color of the console
void changeConsoleColor(int color){
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);
}

int main(){
    int i,j;
    // TODO: out put the foods array in a file and read from there
    //Breakfast
    f[0]= Food("Roti",60, 60, "many", "PCS", "" );
    f[1]= Food("Porota",80, 80, "many", "PCS" ,"");
    f[2]= Food("Bread",20, 20, "many", "PCS" ,"");
    f[3]= Food("Egg(Boiled)",77, 77, "many", "PCS" ,"");
    f[4]= Food("Egg(Omlet)",110, 110, "many", "PCS" ,"");
    f[5]= Food("Egg(Fried)",100, 100, "many", "PCS" ,"");
    f[6]= Food("Halua",125, 1.25, "much", "gram" ,"100");
    f[7]= Food("Sandwich",120, 120, "many", "PCS" ,".5");
    //Lunch:
    f[8]= Food("Rice(Boiled)",250, 2.5, "much", "gram", "100" );
    f[9]= Food("Rice(Fried/Cooked)",280, 2.8, "much", "gram", "100" );
    f[10]= Food("Kichuri",151, 60, "much", "gram", "100" );
    f[11]= Food("Dal",118, 1.18, "much", "gram", "100" );
    f[12]= Food("Fish",80, 80, "many", "PCS", "" );
    f[13]= Food("Meat - Chicken(Cooked)",220, 220, "many", "cup", "" );
    f[14]= Food("Meat - Chicken(Fried)",250, 250, "many", "PCS", "" );
    f[15]= Food("Meat - Beef",400, 400, "many", "cup", "" );
    f[16]= Food("Meat - Mutton",150, 150, "many", "cup", "" );
    f[17]= Food("Vegetable",80, 80, "many", "serving", "" );

    //Fruit:
    f[18]= Food("Apple",56, 56, "many", "PCS", "" );
    f[19]= Food("Banana",95, 95, "many", "PCS", "" );
    f[20]= Food("Mango",70 , 70, "many", "PCS", "" );
    f[21]= Food("Orange",53, 53, "many", "PCS", "" );
    f[22]= Food("Carrot",48, 48, "many", "PCS", "" );
    f[23]= Food("Jackfruit",122,120, "many", "cup", "" );
    f[24]= Food("Lichi",66, 6.6, "much", "gram", "100" );

    //Snack:
    f[25]= Food("Burger",325, 325, "many", "PCS", "" );
    f[26]= Food("Pizza",375, 375, "many", "PCS", "" );
    f[27]= Food("Ice-Cream",164, 164, "many", "scoop", "" );
    f[28]= Food("Samosa",225, 225, "many", "PCS", "" );
    f[29]= Food("French Fries",235, 23.5, "many", "PCS", "10" );
    f[30]= Food("Potato Chips", 800, 8, "much", "gram", "100" );
    f[31]= Food("Sweets",150, 1.5, "much", "gram", "100" );
    f[32]= Food("Noodles",137, 1.37, "much", "gram", "100" );
    f[33]= Food("Soup",150, 150, "many", "cup", "" );

    //Drinks:
    f[34]= Food("Tea",35, 35, "many", "cup", "" );
    f[35]= Food("Cofee",50, 50, "many", "cup", "" );
    f[36]= Food("Milk",100, 100, "many", "cup", "" );
    f[37]= Food("Cold Drinks",95, 95, "many", "bottle", "" );
    f[38]= Food("Apple Juice",95, 95, "many", "glass", "" );
    ofstream outFood;
    outFood.open("outfood.txt");
    for(i=0;i<=38;i++){
        outFood << f[i].getName();
    }


    for(i=0;i<=8;i++){
        breakfast[i] = f[i];
    }

    for(i=0,j=8;i<=9,j<=17;i++,j++){
        lunch[i] = f[j];
    }

    for(i=0,j=18;i<=6,j<=24;i++,j++){
        fruit[i] = f[j];
    }

    for(i=0,j=25;i<=8,j<=33;i++,j++){
        snack[i] = f[j];
    }
    for(i=0,j=34;i<=4,j<=38;i++,j++){
        drinks[i] = f[j];
    }
    displayBreakfast = Display(breakfast, 8);
    displayLunch = Display(lunch, 10);
    displayFruit = Display(fruit, 6);
    displaySnack = Display(snack, 8);
    displayDrinks = Display(drinks, 4);


    basicChoices1();
	return 0;
}
