#include <iostream>
#include <windows.h>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <cstdlib>
#include <random>
using namespace std;


class VendingMachine{ //VendingMachine class initializing variables
    public:
    int incaDrink;
    int pepsiDrink;
    int fantaDrink;
    int resDrink;
    int soupCans;
    int dietDrink;
    int budDrink;
    bool ticketDispense;
    int waterDrink;
    double money;


    VendingMachine(){ //VendingMachine object defines variables
        incaDrink = 10;
        pepsiDrink = 10;
        fantaDrink = 10;
        resDrink = 10;
        soupCans = 5;
        dietDrink = 10;
        budDrink = 10;
        ticketDispense = false;
        waterDrink = 20;
        money = 0;
    }    

    void incaKola(){ //Inca Kola creator
        string confirm;
        double moneySol;
        double solCost = 13.67;
        double cost = 3.59;
        string SolOrDol;
        while (confirm != "N"){
            cout << "Inca Kola is a popular Peruvian soda with a refreshing lemon taste.\n";
            cout << "Of course, it's not Coca Cola. Hopefully you knew this already?\n";
            cout << "Inca Kola costs " << solCost << " Sol, or $" << cost << ", and there are " << incaDrink << " drinks remaining.\n";
            if(money != 0){
                cout << "You currently have $" << money << " in this machine.\n";
            }
            cout << "Would you like to purchase 1 Inca Kola? [Y/N] ";
            cin >> confirm;
            cout << "\n";
            while (confirm == "Y" || confirm == "y"){
                if (money >= cost){
                    cout << "Dispensing 1 Inca Kola.\n";
                    incaDrink -= 1;
                    money -= cost;
                    cout << "Drinks remaining: " << incaDrink;
                    cout << "\nYou have $" << money << " remaining.";
                }
                else{
                    cout << "Are you paying with Sol or USD? "; //Currency chooser
                    cin >> SolOrDol;
                    if (SolOrDol == "Sol"){ //Takes Peruvian Sol -- 0.26 USD per 1 Sol
                        cout << "Please insert your money into the slot: ";
                        cin >> moneySol;
                        while (moneySol < solCost){
                            double cash; 
                            cout << "\nPlease insert more money into the slot: ";
                            cin >> cash;
                            moneySol += cash;
                        }
                        if (moneySol >= solCost){
                            cout << "Dispensing 1 Inca Kola.\n";
                            incaDrink -= 1;
                            moneySol -= solCost;
                            money = moneySol*0.2626;
                            cout << "Drinks remaining: " << incaDrink;
                            cout << "\nYou have $" << money << ", or " << moneySol << " Sol  remaining.";
                        }
                    } else if (SolOrDol == "USD"){ //Takes USD -- 3.81 Sol per 1 USD
                        cout << "Please insert your money into the slot: $";
                        cin >> money;
                        while (money < cost){
                            double cash; 
                            cout << "\nPlease insert more money into the slot: $";
                            cin >> cash;
                            money += cash;
                        }
                        if (money >= cost){
                            cout << "Dispensing 1 Inca Kola.\n";
                            incaDrink -= 1;
                            money -= cost;
                            cout << "Drinks remaining: " << incaDrink;
                            moneySol = money/0.2626;
                            cout << "\nYou have $" << money << ", or " << moneySol << " Sol  remaining.";
                        }
                    }
                }
                cout << "\nWould you like to purchase another Inca Kola? [Y/N] "; //Make it again
                cin >> confirm;
                if (incaDrink == 0){
                    cout << "This machine is out of Inca Kola.\n";
                    cout << "Please see a manager to restock.\n";
                    confirm = "N";
                }
            }
        }
    }

    void pepsi(){ //Pepsi
        string confirm;
        double cost = 1.78;
        while (confirm != "N"){
            cout << "Pepsi Cola is a famous American carbonated soft drink, advertised to relieve dyspepsia.\n";
            cout << "Unfortunately we're out of Coke, but I'm assuming that Pepsi is ok.\n";
            cout << "Pepsi costs $" << cost << " and there are " << pepsiDrink << " drinks remaining.\n";
            if(money != 0){
                cout << "You currently have $" << money << " in this machine.\n";
            }
            cout << "Would you like to purchase 1 Pepsi? [Y/N] ";
            cin >> confirm;
            cout << "\n";
            while (confirm == "Y" || confirm == "y"){
                if (money >= cost){
                    cout << "Dispensing 1 Pepsi.\n";
                    pepsiDrink -= 1;
                    money -= cost;
                    cout << "Drinks remaining: " << pepsiDrink;
                    cout << "\nYou have $" << money << " remaining.";
                }
                else{
                    cout << "Please insert your money into the slot: $";
                    cin >> money;
                    while (money < cost){
                        double cash; 
                        cout << "\nPlease insert more money into the slot: $";
                        cin >> cash;
                        money += cash;
                    }
                    if (money >= cost){
                        cout << "Dispensing 1 Pepsi.\n";
                        pepsiDrink -= 1;
                        money -= cost;
                        cout << "Drinks remaining: " << pepsiDrink;
                        cout << "\nYou have $" << money << " remaining.";
                    }
                }
                cout << "\nWould you like to purchase another Pepsi? [Y/N] ";
                cin >> confirm;
                if (pepsiDrink == 0){
                    cout << "This machine is out of Pepsi.\n";
                    cout << "Please see a manager to restock.\n";
                    confirm = "N";
                }
            }
        }
    }

    void fanta(){
        string confirm;
        double cost = 1.99;
        while (confirm != "N"){
            cout << "Fanta is a German brand of fruit-flavored carbonated soft drinks.\n";
            cout << "Granted, there are over 200 flavors worldwide but here we only have orange.\n";
            cout << "Fanta costs $" << cost << " and there are " << fantaDrink << " drinks remaining.\n";
            if(money != 0){
                cout << "You currently have $" << money << " in this machine.\n";
            }
            cout << "Would you like to purchase 1 Fanta? [Y/N] ";
            cin >> confirm;
            cout << "\n";
            while (confirm == "Y" || confirm == "y"){
                if (money >= cost){
                    cout << "Dispensing 1 Fanta.\n";
                    fantaDrink -= 1;
                    money -= cost;
                    cout << "Drinks remaining: " << fantaDrink;
                    cout << "\nYou have $" << money << " remaining.";
                }
                else{
                    cout << "Please insert your money into the slot: $";
                    cin >> money;
                    while (money < cost){
                        double cash; 
                        cout << "\nPlease insert more money into the slot: $";
                        cin >> cash;
                        money += cash;
                    }
                    if (money >= cost){
                        cout << "Dispensing 1 Fanta.\n";
                        fantaDrink -= 1;
                        money -= cost;
                        cout << "Drinks remaining: " << fantaDrink;
                        cout << "\nYou have $" << money << " remaining.";
                    }
                }
                cout << "\nWould you like to purchase another Fanta? [Y/N] ";
                cin >> confirm;
                if (fantaDrink == 0){
                    cout << "This machine is out of Fanta.\n";
                    cout << "Please see a manager to restock.\n";
                    confirm = "N";
                }
            }
        }
    }

    void residentPepper(){
        string confirm;
        double cost = 2.08;
        while (confirm != "N"){
            cout << "Dr. Pepper is an American carbonated soft drink, called a digestive cure-all.\n";
            cout << "Of course, the road to becoming a doctor is long, so right now Mr. Pepper is still a resident.\n";
            cout << "Resident Pepper costs $" << cost << " and there are " << resDrink << " drinks remaining.\n";
            if(money != 0){
                cout << "You currently have $" << money << " in this machine.\n";
            }
            cout << "Would you like to purchase 1 Resident Pepper? [Y/N] ";
            cin >> confirm;
            cout << "\n";
            while (confirm == "Y" || confirm == "y"){
                if (money >= cost){
                    cout << "Dispensing 1 Resident Pepper.\n";
                    resDrink -= 1;
                    money -= cost;
                    cout << "Drinks remaining: " << resDrink;
                    cout << "\nYou have $" << money << " remaining.";
                }
                else{
                    cout << "Please insert your money into the slot: $";
                    cin >> money;
                    while (money < cost){
                        double cash; 
                        cout << "\nPlease insert more money into the slot: $";
                        cin >> cash;
                        money += cash;
                    }
                    if (money >= cost){
                        cout << "Dispensing 1 Resident Pepper.\n";
                        resDrink -= 1;
                        money -= cost;
                        cout << "Drinks remaining: " << resDrink;
                        cout << "\nYou have $" << money << " remaining.";
                    }
                }
                cout << "\nWould you like to purchase another Resident Pepper? [Y/N] ";
                cin >> confirm;
                if (resDrink == 0){
                    cout << "This machine is out of Resident Pepper.\n";
                    cout << "Please see a manager to restock.\n";
                    confirm = "N";
                }
            }
        }
    }

    void soup(){
        string confirm;
        double cost = 4.78;
        while (confirm != "N"){
            cout << "Chicken Noodle Soup has garnered a reputation for being a natural medicine for colds.\n";
            cout << "Why there is soup in a drink vending machine is a story for another day.\n";
            cout << "Soup costs $" << cost << " and there are " << soupCans << " cans remaining.\n";
            if(money != 0){
                cout << "You currently have $" << money << " in this machine.\n";
            }
            cout << "Would you like to purchase 1 can of soup? [Y/N] ";
            cin >> confirm;
            cout << "\n";
            while (confirm == "Y" || confirm == "y"){
                if (money >= cost){
                    cout << "Dispensing 1 can of soup.\n";
                    soupCans -= 1;
                    money -= cost;
                    cout << "Cans remaining: " << soupCans;
                    cout << "\nYou have $" << money << " remaining.";
                }
                else{
                    cout << "Please insert your money into the slot: $";
                    cin >> money;
                    while (money < cost){
                        double cash; 
                        cout << "\nPlease insert more money into the slot: $";
                        cin >> cash;
                        money += cash;
                    }
                    if (money >= cost){
                        cout << "Dispensing 1 Pepsi.\n";
                        soupCans -= 1;
                        money -= cost;
                        cout << "Cans remaining: " << soupCans;
                        cout << "\nYou have $" << money << " remaining.";
                    }
                }
                cout << "\nWould you like to purchase another can of soup? [Y/N] ";
                cin >> confirm;
                if (soupCans == 0){
                    cout << "This machine is out of soup.\n";
                    cout << "Please see a manager to restock.\n";
                    confirm = "N";
                }
            }
        }
    }

    void ambrosia(){ //Is not supposed to work
        cout << "Ambrosia is the food and drink of the gods on Mount Olympus.\n";
        cout << "Why would we ever have something like that in this vending machine??\n";
        cout << "Please return to the menu.\n\n";
    }

    void dietCoke(){
        string confirm;
        double cost = 2.59;
        while (confirm != "N"){
            cout << "Diet Coke is a sugar-free and low-calorie soft drink marketed by the Coca-Cola Company.\n";
            cout << "It's so healthy with all those artificial sweeteners that cause absolutely no harm whatsoever.\n";
            cout << "Diet Coke costs $" << cost << " and there are " << dietDrink << " drinks remaining.\n";
            if(money != 0){
                cout << "You currently have $" << money << " in this machine.\n";
            }
            cout << "Would you like to purchase 1 Diet Coke? [Y/N] ";
            cin >> confirm;
            cout << "\n";
            while (confirm == "Y" || confirm == "y"){
                if (money >= cost){
                    cout << "Dispensing 1 Diet Coke.\n";
                    dietDrink -= 1;
                    money -= cost;
                    cout << "Drinks remaining: " << dietDrink;
                    cout << "\nYou have $" << money << " remaining.";
                }
                else{
                    cout << "Please insert your money into the slot: $";
                    cin >> money;
                    while (money < cost){
                        double cash; 
                        cout << "\nPlease insert more money into the slot: $";
                        cin >> cash;
                        money += cash;
                    }
                    if (money >= cost){
                        cout << "Dispensing 1 Diet Coke.\n";
                        dietDrink -= 1;
                        money -= cost;
                        cout << "Drinks remaining: " << dietDrink;
                        cout << "\nYou have $" << money << " remaining.";
                    }
                }
                cout << "\nWould you like to purchase another Diet Coke? [Y/N] ";
                cin >> confirm;
                if (dietDrink == 0){
                    cout << "This machine is out of Diet Coke.\n";
                    cout << "Please see a manager to restock.\n";
                    confirm = "N";
                }
            }
        }
    }


    void airBudweiser(){
        string confirm;
        double cost = 2.99;
        while (confirm != "N"){
            cout << "Budweiser is an American-style pale lager, while Air Bud is a 90s sports movie about a ballin' dog.\n";
            cout << "Air Budweiser is a promotional drink, where you might win a ticket to see Air Bud in theaters from one of these beers!\n";
            cout << "Air Budweiser costs $" << cost << " and there are " << budDrink << " drinks remaining.\n";
            if(money != 0){
                cout << "You currently have $" << money << " in this machine.\n";
            }
            cout << "Would you like to purchase 1 Air Budweiser? [Y/N] ";
            cin >> confirm;
            cout << "\n";
            while (confirm == "Y" || confirm == "y"){
                if (money >= cost){
                    cout << "Dispensing 1 Air Budweiser.\n";
                    budDrink -= 1;
                    money -= cost;
                    if (budDrink == 2){
                        cout << "Congratulations! You've won a ticket to go see Air Bud in theaters! Enjoy!\n";
                        ticketDispense = true;
                    }
                    cout << "Drinks remaining: " << budDrink;
                    cout << "\nYou have $" << money << " remaining.";
                }
                else{
                    cout << "Please insert your money into the slot: $";
                    cin >> money;
                    while (money < cost){
                        double cash; 
                        cout << "\nPlease insert more money into the slot: $";
                        cin >> cash;
                        money += cash;
                    }
                    if (money >= cost){
                        cout << "Dispensing 1 Air Budweiser.\n";
                        budDrink -= 1;
                        money -= cost;
                        if (budDrink == 2){
                            cout << "Congratulations! You've won a ticket to go see Air Bud in theaters! Enjoy!\n";
                            ticketDispense = true;
                        }
                        cout << "Drinks remaining: " << budDrink;
                        cout << "\nYou have $" << money << " remaining.";
                    }
                }
                cout << "\nWould you like to purchase another Air Budweiser? [Y/N] ";
                cin >> confirm;
                if (budDrink == 0){
                    cout << "This machine is out of Air Budweiser.\n";
                    cout << "Please see a manager to restock.\n";
                    confirm = "N";
                }
            }
        }
    }

    void water(){
        string confirm;
        double cost = 0.99;
        while (confirm != "N"){
            cout << "Water.\n";
            cout << "Please don't make me explain what a bottle of water is.\n";
            cout << "Water costs $" << cost << " and there are " << waterDrink << " bottles remaining.\n";
            if(money != 0){
                cout << "You currently have $" << money << " in this machine.\n";
            }
            cout << "Would you like to purchase 1 bottle of water? [Y/N] ";
            cin >> confirm;
            cout << "\n";
            while (confirm == "Y" || confirm == "y"){
                if (money >= cost){
                    cout << "Dispensing 1 bottle of water.\n";
                    waterDrink -= 1;
                    money -= cost;
                    cout << "Bottles remaining: " << waterDrink;
                    cout << "\nYou have $" << money << " remaining.";
                }
                else{
                    cout << "Please insert your money into the slot: $";
                    cin >> money;
                    while (money < cost){
                        double cash; 
                        cout << "\nPlease insert more money into the slot: $";
                        cin >> cash;
                        money += cash;
                    }
                    if (money >= cost){
                        cout << "Dispensing 1 bottle of water.\n";
                        waterDrink -= 1;
                        money -= cost;
                        cout << "Bottles remaining: " << waterDrink;
                        cout << "\nYou have $" << money << " remaining.";
                    }
                }
                cout << "\nWould you like to purchase another bottle of water? [Y/N] ";
                cin >> confirm;
                if (waterDrink == 0){
                    cout << "This machine is out of water.\n";
                    cout << "Please see a manager to restock.\n";
                    confirm = "N";
                }
            }
        }
    }

    void restock(){
        cout << "\n\nCurrent status:\n";
        cout << "Inca Kola: " << incaDrink << " bottles.\n";
        cout << "Pepsi: " << pepsiDrink << " bottles.\n";
        cout << "Fanta: " << fantaDrink << " bottles.\n";
        cout << "Resident Pepper: " << resDrink << " bottles.\n";
        cout << "Soup: " << soupCans << " cans.\n";
        cout << "Ambrosia: 0 portions.\n";
        cout << "Diet Coke: " << dietDrink << " bottles.\n";
        cout << "Air Budweiser: " << budDrink << " bottles.\n";
        if (ticketDispense == false){
            cout << "The machine still has a ticket.\n";
        }else if (ticketDispense == true){
            cout << "There is no ticket in the machine.\n";
        }
        cout << "Water: " << waterDrink << " bottles.\n";
        int input;
        do{
            cout << "What will you restock?\n";
            cout << "1) Inca Kola\n";
            cout << "2) Pepsi\n";
            cout << "3) Fanta\n";
            cout << "4) Resident Pepper\n";
            cout << "5) Soup\n";
            cout << "6) Ambrosia\n";
            cout << "7) Diet Coke\n";
            cout << "8) Air Budweiser\n";
            cout << "9) Water\n";
            cout << "10) Full restock\n";
            cout << "0) Exit\n";
            cin >> input;
            switch(input){
                case 1:
                    incaDrink = 10;
                    cout << "Inca Kola: " << incaDrink << " bottles.\n";
                    break;
                case 2:
                    pepsiDrink = 10;
                    cout << "Pepsi: " << pepsiDrink << " bottles.\n";
                    break;
                case 3:
                    fantaDrink = 10;
                    cout << "Fanta: " << fantaDrink << " bottles.\n";
                    break;
                case 4:
                    resDrink = 10;
                    cout << "Resident Pepper: " << resDrink << " bottles.\n";
                    break;
                case 5:
                    soupCans = 5;
                    cout << "Soup: " << soupCans << " cans.\n";
                    break;
                case 6:
                    cout << "Error -- Ambrosia not found.\n";
                    break;
                case 7:
                    dietDrink = 10;
                    cout << "Diet Coke: " << dietDrink << " bottles.\n";
                    break;
                case 8:
                    budDrink  = 10;
                    cout << "Air Budweiser: " << budDrink << " bottles.\n";
                    if (ticketDispense == true) {
                        ticketDispense = false;
                        cout << "Ticket replaced.\n";
                    }
                    break;
                case 9:
                    waterDrink = 20;
                    cout << "Water: " << waterDrink << " bottles.\n";
                    break;
                case 10:
                    incaDrink = 10;
                    pepsiDrink = 10;
                    fantaDrink = 10;
                    resDrink = 10;
                    soupCans = 5;
                    dietDrink = 10;
                    budDrink  = 10;
                    waterDrink = 20;
                    cout << "All items restocked.\n";
                    if (ticketDispense == true) {
                        ticketDispense = false;
                        cout << "Ticket replaced.\n";
                    }
                    cout << "Errors -- \n";
                    cout << "   Ambrosia not found.\n";
                    break;
            }
        }while (input != 0);

    }

    void GimmeMoneyBackPls(){
        cout << "Returning change: $" << money << " has been returned.\n";
        money = 0;
        
    }
};
    int main () {
        VendingMachine machine;
        int x;
        do{
            cout << "\nWelcome to the Ultimate Vending Machine\n";
            cout << "What drink would you like to purchase?\n";
            cout << "1) Inca Kola\n";
            cout << "2) Pepsi\n";
            cout << "3) Fanta\n";
            cout << "4) Resident Pepper\n";
            cout << "5) Soup\n";
            cout << "6) Ambrosia\n";
            cout << "7) Diet Coke\n";
            cout << "8) Air Budweiser\n";
            cout << "9) Water\n";
            cout << "0) Cancel the order\n";
            cin >> x;
            switch(x){
                case 1:
                    machine.incaKola();
                    break;
                case 2:
                    machine.pepsi();
                    break;
                case 3:
                    machine.fanta();
                    break;
                case 4:
                    machine.residentPepper();
                    break;
                case 5:
                    machine.soup();
                    break;
                case 6:
                    machine.ambrosia();
                    break;
                case 7:
                    machine.dietCoke();
                    break;
                case 8:
                    machine.airBudweiser();
                    break;
                case 9:
                    machine.water();
                    break;
                case 73794152:
                    machine.restock();
                    break;
            }
        }while (x != 0);
        if (x == 0){
            machine.GimmeMoneyBackPls();
        }
    }
