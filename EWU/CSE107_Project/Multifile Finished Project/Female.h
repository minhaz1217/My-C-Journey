#include<bits/stdc++.h>
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
