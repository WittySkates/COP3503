#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

mt19937 random_mt;

class data {
    public:
        string name;
        int cIncome;
        int population;
        int mIncome;
        int households;

        data();
    };

    data::data() {}

int Random(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides){
    map<int, int> rolls;
    for(int i = 1; i <= numberOfSides; i++){
        rolls.insert(pair<int,int> (i,0));
    }

    for(int i = 0; i < numberOfRolls; i++){
        int randomNumber = Random(1, numberOfSides);

        auto found = rolls.find(randomNumber);
        if(found != rolls.end()){
            found->second += 1;
        }
    }
    map<int, int>::iterator itr;
    for (itr = rolls.begin(); itr != rolls.end(); ++itr) {
        cout << itr->first << ": " << itr->second << '\n';
    }
    cout << endl;
}

int main()
{
    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;

    if (option == 1)
    {
        int numberRoll;
        int sidesRoll;
        int randomSeed;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);


        cout << "Number of times to roll the die: ";
        cin >> numberRoll;
        // user input

        cout << "Number of sides on this die: ";
        cin >> sidesRoll;
        // user input

        RollDice(numberRoll, sidesRoll);
    }
    else if (option == 2) {
        map<string, data> states;

        ifstream file("states.csv");
        bool first = true;
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stringstream parse(line);
                if (!first) {
                    data readData;
                    for (int i = 0; i < 5; i++) {
                        if (i == 0) {
                            getline(parse, line, ',');
                            readData.name = line;
                        }
                        else if (i == 1) {
                            getline(parse, line, ',');
                            readData.cIncome = stoi(line);
                        }
                        else if (i == 2) {
                            getline(parse, line, ',');
                            readData.population = stoi(line);
                        }
                        else if (i == 3) {
                            getline(parse, line, ',');
                            readData.mIncome = stoi(line);
                        }
                        else if (i == 4) {
                            getline(parse, line, '\n');
                            readData.households = stoi(line);
                        }
                    }
                    states.insert(pair<string, data> (readData.name,readData));
                }
                first = false;
            }
        }

        cout << "1. Print all states\n";
        cout << "2. Search for a state\n";

        int option2;
        cin >> option2;

        if(option2 == 1){
            map<string, data>::iterator itr;
            for (itr = states.begin(); itr != states.end(); ++itr) {
                cout << itr->first << endl;
                cout << "Population: " << itr->second.population << endl;
                cout << "Per Capita Income: " << itr->second.cIncome << endl;
                cout << "Median Household Income: " << itr->second.mIncome << endl;
                cout << "Number of Households: " << itr->second.households << endl;
                cout << endl;

            }
            cout << endl;
        }

        else if(option2 == 2){
            string userSearch;
            cin >> userSearch;

            auto found = states.find(userSearch);
            if(found != states.end()){
                cout << found->first << endl;
                cout << "Population: " << found->second.population << endl;
                cout << "Per Capita Income: " << found->second.cIncome << endl;
                cout << "Median Household Income: " << found->second.mIncome << endl;
                cout << "Number of Households: " << found->second.households << endl;
                cout << endl;
            }
            else{
                cout << "No match found for " << userSearch;
            }

        }
    }

    return 0;
}

