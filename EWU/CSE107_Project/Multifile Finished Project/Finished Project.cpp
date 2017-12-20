#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
using namespace std;

#include "Global.h"
#include "Food.h"
#include "Calorie.h"
#include "Height.h"
#include "Person.h"
#include "Male.h"
#include "Female.h"
//Global Food classes
Food f[39];
Food breakfast[8];
Food lunch[10];
Food fruit[7];
Food snack[9];
Food drinks[5];
/*
// Basic Metabolic Rate:
// BMR for male: 10*weight + 6.25*height(cm) - 5*age(years) + 5
// BMR for female 10*wight + 6.25*height(cm) - 5*age - 161;
*/
Person *p1;
#include "Display.h"



#define check(a) cout<<a<< endl;
//prototyping
//Food class
//Calorie class
//height
// pperson
//male
//female
//display
//class prototypes


int main(){
    int i,j;
    //Filling the food objects to use them later
    f[0]= Food("",60, 60, "many", "PCS", "" );
    f[0] = "Roti";
    f[1]= Food("",80, 80, "many", "PCS" ,"");
    f[1] = "Porota";
    f[2]= Food("",20, 20, "many", "PCS" ,"");
    f[2] = "Bread";
    f[3]= Food("",77, 77, "many", "PCS" ,"");
    f[3]= "Egg(Boiled)";
    f[4]= Food("",110, 110, "many", "PCS" ,"");
    f[4]= "Egg(Omlet)";
    f[5]= Food("",100, 100, "many", "PCS" ,"");
    f[5]= "Egg(Fried)";
    f[6]= Food("",125, 1.25, "much", "gram" ,"100");
    f[6]= "Halua";
    f[7]= Food("",120, 120, "many", "PCS" ,".5");
    f[7]= "Sandwich";
    //Lunch:
    f[8]= Food("",250, 2.5, "much", "gram", "100" );
    f[8]= "Rice(Boiled)";
    f[9]= Food("",280, 2.8, "much", "gram", "100" );
    f[9]= "Rice(Fried/Cooked)";
    f[10]= Food("",151, 60, "much", "gram", "100" );
    f[10]= "Kichuri";
    f[11]= Food("",118, 1.18, "much", "gram", "100" );
    f[11]= "Dal";
    f[12]= Food("",80, 80, "many", "PCS", "" );
    f[12]= "Fish";
    f[13]= Food("",220, 220, "many", "cup", "" );
    f[13]= "Meat - Chicken(Cooked)";
    f[14]= Food("Meat - Chicken(Fried)",250, 250, "many", "PCS", "" );
    f[14]= "Meat - Chicken(Fried)";
    f[15]= Food("",400, 400, "many", "cup", "" );
    f[15]= "Meat - Beef";
    f[16]= Food("",150, 150, "many", "cup", "" );
    f[16]= "Meat - Mutton";
    f[17]= Food("",80, 80, "many", "serving", "" );
    f[17]= "Vegetable";

    //Fruit:
    f[18]= Food("",56, 56, "many", "PCS", "" );
    f[18]= "Apple";
    f[19]= Food("",95, 95, "many", "PCS", "" );
    f[19]= "Banana";
    f[20]= Food("",70 , 70, "many", "PCS", "" );
    f[20]= "Mango";
    f[21]= Food("",53, 53, "many", "PCS", "" );
    f[21]= "Orange";
    f[22]= Food("",48, 48, "many", "PCS", "" );
    f[22]= "Carrot";
    f[23]= Food("",122,120, "many", "cup", "" );
    f[23]= "Jackfruit";
    f[24]= Food("",66, 6.6, "much", "gram", "100" );
    f[24]= "Lichi";

    //Snack:
    f[25]= Food("",325, 325, "many", "PCS", "" );
    f[25]= "Burger";
    f[26]= Food("",375, 375, "many", "PCS", "" );
    f[26]= "Pizza";
    f[27]= Food("",164, 164, "many", "scoop", "" );
    f[27]= "Ice-Cream";
    f[28]= Food("",225, 225, "many", "PCS", "" );
    f[28]= "Samosa";
    f[29]= Food("",235, 23.5, "many", "PCS", "10" );
    f[29]= "French Fries";
    f[30]= Food("", 800, 8, "much", "gram", "100" );
    f[30]= "Potato Chips";
    f[31]= Food("",150, 1.5, "much", "gram", "100" );
    f[31]= "Sweets";
    f[32]= Food("",137, 1.37, "much", "gram", "100" );
    f[32]= "Noodles";
    f[33]= Food("",150, 150, "many", "cup", "" );
    f[33]= "Soup";

    //Drinks:
    f[34]= Food("",35, 35, "many", "cup", "" );
    f[34]= "Tea";
    f[35]= Food("",50, 50, "many", "cup", "" );
    f[35]= "Cofee";
    f[36]= Food("",100, 100, "many", "cup", "" );
    f[36]= "Milk";
    f[37]= Food("",95, 95, "many", "bottle", "" );
    f[37]= "Cold Drinks";
    f[38]= Food("",95, 95, "many", "glass", "" );
    f[38]= "Apple Juice";

    //setting up the breakfast food object
    for(i=0;i<=8;i++){
        breakfast[i] = f[i];
    }

    //setting up the lunch food object
    for(i=0,j=8;i<=9,j<=17;i++,j++){
        lunch[i] = f[j];
    }

    //setting up the fruit food object
    for(i=0,j=18;i<=6,j<=24;i++,j++){
        fruit[i] = f[j];
    }

    //setting up the snack food object
    for(i=0,j=25;i<=8,j<=33;i++,j++){
        snack[i] = f[j];
    }

    //setting up the drinks food object
    for(i=0,j=34;i<=4,j<=38;i++,j++){
        drinks[i] = f[j];
    }
    displayBreakfast = Display(breakfast, 8);
    displayLunch = Display(lunch, 10);
    displayFruit = Display(fruit, 6);
    displaySnack = Display(snack, 8);
    displayDrinks = Display(drinks, 4);
    basic.basicChoices1();
	return 0;
}
