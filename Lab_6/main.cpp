#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

char * heroName;
short heroStr;
short heroInt;
short heroAgi;
int heroHealthCur;
int heroHealthMax;
float heroArmor;
float heroArmorMagic;
char * itemName;
int itemPrice;
float itemWeight;

int charCount;
int nameSize;
int itemNameSize;
int numberItems = 0;


vector<string> nameHero;
vector<short> strHero;
vector<short> intHero;
vector<short> agiHero;
vector<int> curHealthHero;
vector<int> maxHealthHero;
vector<float> armorHero;
vector<float> magicArmorHero;
vector<string> nameItem;
vector<int> priceItem;
vector<float> weightItem;
vector<int> itemNumbers;
vector<vector<string>> nameTotal;
vector<vector<int>> priceTotal;
vector<vector<float>> weightTotal;



void openFile(string name) {
    ifstream file(name, ios_base::binary);
    if(file.is_open()){
        file.read((char* )&charCount, 4);
        for(int i = 0; i < charCount; i++){
            file.read((char*)&nameSize, 4);
            char* heroName = new char[nameSize];
            file.read(heroName, nameSize * sizeof(heroName[0]));
            string nameString = heroName;
            nameHero.push_back(nameString);
            delete [] heroName;

            file.read((char*)&heroStr, 2);
            strHero.push_back(heroStr);

            file.read((char*)&heroInt, 2);
            intHero.push_back(heroInt);

            file.read((char*)&heroAgi, 2);
            agiHero.push_back(heroAgi);

            file.read((char*)&heroHealthCur, 4);
            curHealthHero.push_back(heroHealthCur);

            file.read((char*)&heroHealthMax, 4);
            maxHealthHero.push_back(heroHealthMax);

            file.read((char*)&heroArmor, 4);
            armorHero.push_back(heroArmor*100);

            file.read((char*)&heroArmorMagic, 4);
            magicArmorHero.push_back(heroArmorMagic*100);

            file.read((char*)&numberItems, 4);
            itemNumbers.push_back(numberItems);

            for (int j = 0; j < numberItems; ++j) {
                file.read((char*)&itemNameSize,4);
                char* itemName = new char[itemNameSize];
                file.read(itemName, itemNameSize * sizeof(itemName[0]));
                nameString = itemName;
                nameItem.push_back(nameString);
                delete [] itemName;

                file.read((char*)&itemPrice,4);
                priceItem.push_back(itemPrice);

                file.read((char*)&itemWeight,4);
                weightItem.push_back(itemWeight);
            }
            nameTotal.push_back(nameItem);
            priceTotal.push_back(priceItem);
            weightTotal.push_back(weightItem);
            nameItem.clear();
            priceItem.clear();
            weightItem.clear();

        }

        file.close();
    }

}
void printMe (int i){
    cout << "Name: " << nameHero[i] << endl;
    cout << "Str: " << strHero[i]<< endl;
    cout << "Int: " << intHero[i] << endl;
    cout << "Agi: " << agiHero[i] << endl;
    cout << "HP: " << curHealthHero[i] << " / " << maxHealthHero[i] << endl;
    cout << "Armor: " << armorHero[i] << "%" << endl;
    cout << "Magic armor: " << magicArmorHero[i] << "%" << endl;
    cout << "Inventory: " << endl;
    if(nameTotal[i].size() == 0){
        cout << "Inventory empty." << endl;
        cout << endl;
    }
    else {
        for(unsigned int j = 0; j < nameTotal[i].size(); j++){
            cout << nameTotal[i][j] << ", " << priceTotal[i][j] << ", " << weightTotal[i][j] << endl;
        }
        cout << endl;
    }
}
int main()
{
    cout << "Which file(s) to open?\n";
    cout << "1. fantasyheroes.dat" << endl;
    cout << "2. superheroes.dat" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    if(option == 1){
        openFile("fantasyheroes.dat");
    }
    else if(option == 2){
        openFile("superheroes.dat");
    }
    else if(option == 3){
        openFile("fantasyheroes.dat");
        openFile("superheroes.dat");
    }
    /* Load hero files here */

    cout << "1. Print all heroes" << endl;
    cout << "2. Hero with the most items" << endl;
    cout << "3. Strongest hero" << endl;
    cout << "4. Heroes with greater than 18 intelligence" << endl;
    cout << "5. 2 clumsiest heroes" << endl;
    cout << "6. Hero with the most valuable stuff" << endl << endl;

    cin >> option;

    /* Work your magic here */
    if(option == 1){
        for(unsigned int i = 0; i < nameHero.size(); i++) {
            printMe(i);
        }
    }
    else if(option == 2){
        int index = 0;
        int mostItem = itemNumbers[0];
        for(unsigned int i = 1; i < itemNumbers.size(); i++){
            if(itemNumbers[i] > mostItem){
                index = i;
                mostItem = itemNumbers[i];
            }
        }
        printMe(index);
    }
    else if (option == 3){
        int strongestBoi = strHero[0];
        int index = 0;
        for(unsigned int i = 1; i < strHero.size(); i++){
            if(strHero[i] > strongestBoi){
                index = i;
                strongestBoi = strHero[i];
            }
        }
        printMe(index);
    }
    else if(option == 4){
        for(unsigned int i = 1; i < intHero.size(); i++){
            if(intHero[i] > 18){
                printMe(i);
            }
        }
    }
    else if (option == 5){
        int clumsyOne = agiHero[0];
        int clumsyTwo = agiHero[1];
        int indexOne = 0;
        int indexTwo = 1;

        if(clumsyOne > clumsyTwo){
            clumsyOne = agiHero[1];
            clumsyTwo = agiHero[2];
            indexOne = 1;
            indexTwo = 2;
        }

        for(unsigned int i = 2; i < agiHero.size(); i++){
            if(agiHero[i] < clumsyOne){
                clumsyTwo = clumsyOne;
                indexTwo = indexOne;
                clumsyOne = agiHero[i];
                indexOne = i;
            }
            else if(agiHero[i] < clumsyTwo){
                clumsyTwo = agiHero[i];
                indexTwo = i;
            }
        }
        cout << "Clumsiest hero:" << endl;
        printMe(indexOne);
        cout << "Second clumsiest hero: " << endl;
        printMe(indexTwo);
    }
    else if(option == 6){
        int currentCost = 0;
        int mostExpensive = 0;
        int index = 0;
        for (unsigned int i = 0; i < nameHero.size(); ++i) {
            currentCost = 0;
            for (unsigned int j = 0; j < nameTotal[i].size(); ++j) {
                currentCost += priceTotal[i][j];
            }
            if (currentCost > mostExpensive){
                mostExpensive = currentCost;
                index = i;
            }
        }
        printMe(index);
    }
    return 0;
}