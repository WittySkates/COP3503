#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;

int setCount = 0;
int vecCount = 0;

void openFile(string name);
vector<int> setNumber;
vector<string> setTheme;
vector<string> setName;
vector<int> setMinifigs;
vector<int> setPieces;
vector<float> setPrice;

void openFile(string name) {
    bool first = true;
    ifstream file(name);
    if(file.is_open()){
        string line;
        while(getline(file, line)) {
            stringstream parse(line);
            if (!first) {
                for(int i = 0; i < 6; i++){
                    if(i == 0) {
                        getline(parse, line, ',');
                        setNumber.push_back(stoi(line));
                    }
                    else if(i == 1){
                        getline(parse, line, ',');
                        setTheme.push_back(line);

                    }
                    else if(i == 2){
                        getline(parse, line, ',');
                        setName.push_back(line);
                    }
                    else if(i == 3){
                        getline(parse, line, ',');
                        if(line == ""){
                            setMinifigs.push_back(stoi("0"));
                        }
                        else{
                            setMinifigs.push_back(stoi(line));
                        }

                    }
                    else if(i == 4){
                        getline(parse, line, ',');
                        if(line == ""){
                            setPieces.push_back(stoi("0"));
                        }
                        else{
                            setPieces.push_back(stoi(line));

                        }
                    }
                    else if (i == 5){
                        getline(parse, line, '\n');
                        if(line == "\r"){
                            setPrice.push_back(stof("0.0"));
                        }
                        else{
                            setPrice.push_back(stof(line));
                        }
                        setCount++;
                    }
                }
            }
            first = false;
        }
    }
    file.close();
}
int main()
{
    cout << std::fixed << setprecision(2);
    cout << "Which file(s) to open?\n";
    cout << "1. lego1.csv" << endl;
    cout << "2. lego2.csv" << endl;
    cout << "3. lego3.csv" << endl;
    cout << "4. All 3 files" << endl;
    int option;
    cin >> option;

    /*======= Load data from file(s) =======*/
    if (option == 1){
        openFile("lego1.csv");
        cout << "Total number of sets: " << setCount << "\n" << endl;

    }
    else if(option == 2){
        openFile("lego2.csv");
        cout << "Total number of sets: " << setCount << "\n" << endl;
    }
    else if(option == 3){
        openFile("lego3.csv");
        cout << "Total number of sets: " << setCount << "\n" << endl;
    }
    else if(option == 4){
        openFile("lego1.csv");
        openFile("lego2.csv");
        openFile("lego3.csv");
        cout << "Total number of sets: " << setCount << "\n" << endl;
    }
    else {
        cout << "Invalid input!"<<endl;
    }

    /*======= Print out how many sets were loaded =======

    cout << "1. Most Expensive set" << endl;
    cout << "2. Largest piece count" << endl;
    cout << "3. Search for set name containing..." << endl;
    cout << "4. Search themes..." << endl;
    cout << "5. Part count information" << endl;
    cout << "6. Price information" << endl;
    cout << "7. Minifigure information" << endl;
    cout << "8. If you bought one of everything..." << endl;
    cout << "0. Exit" << endl;*/

    int choice;
    cin >> choice;
    cin.get();  // Clear newline character for any later input

    /*======= Based on the choice, execute the appropriate task and show the results =======*/

    if(choice == 1){
        float Max = 0;
        int setIndex = 0;
        for(unsigned int i = 0; i < setPrice.size(); i++){
            if (setPrice[i] >= Max){
                Max = setPrice[i];
                setIndex = i;
            }
        }
        cout << "The most expensive set is:" <<endl;
        cout << "Name: " << setName[setIndex] << endl;
        cout << "Number: " << setNumber[setIndex] << endl;
        cout << "Theme: " << setTheme[setIndex] << endl;
        cout << "Price: $" << setPrice[setIndex] << endl;
        cout << "Minifigures: " << setMinifigs[setIndex] << endl;
        cout << "Piece count: " << setPieces[setIndex] << "\n" <<endl;

    }
    else if(choice == 2){
        float Max = 0;
        int setIndex = 0;
        for(unsigned int i = 0; i < setPieces.size(); i++){
            if (setPieces[i] >= Max){
                Max = setPieces[i];
                setIndex = i;
            }
        }
        cout << "The set with the highest parts count:" <<endl;
        cout << "Name: " << setName[setIndex] << endl;
        cout << "Number: " << setNumber[setIndex] << endl;
        cout << "Theme: " << setTheme[setIndex] << endl;
        cout << "Price: $" << setPrice[setIndex] << endl;
        cout << "Minifigures: " << setMinifigs[setIndex] << endl;
        cout << "Piece count: " << setPieces[setIndex] << "\n" << endl;
    }
    else if(choice == 3){
        string userSet;
        getline(cin, userSet);
        bool found = false;
        bool print = false;
        for(unsigned int i = 0; i < setName.size(); i++){
            if(setName[i].find(userSet) != string::npos){
                if(setName[i].find(userSet) != string::npos && print == false){
                    cout << "Sets matching " << "\"" << userSet << "\"" << ":" << endl;
                    print = true;
                }
                cout << setNumber[i] << " " << setName[i] << " $" << setPrice[i] << " " << endl;
                found = true;
            }
            else if (i == setName.size()-1 && !found){
                cout << "No sets found matching that search term" << endl;
            }
        }
        if (found){
            cout << "\n";
        }
    }
    else if(choice == 4){
        string userSet;
        getline(cin,userSet);
        bool found = false;
        bool print = false;
        for(unsigned int i = 0; i < setTheme.size(); i++){
            if(setTheme[i].find(userSet) != string::npos){
                if(setTheme[i].find(userSet) != string::npos && print == false){
                    cout << "Sets matching " << "\"" << userSet << "\"" << ":" << endl;
                    print = true;
                }
                cout << setNumber[i] << " " << setName[i] << " $" << setPrice[i] << " " << endl;
                found = true;
            }
            else if (i == setTheme.size()-1 && !found){
                cout << "No sets found matching that search term" << endl;
            }
        }
        if (found){
            cout << "\n";
        }
    }
    else if(choice == 5){
        int Max = 0;
        int Min = 10000;
        int Average = 0;
        int Total = 0;
        int setIndexMax = 0;
        int setIndexMin = 0;
        int setCountNonZero = 0;
        for(unsigned int i = 0; i < setPieces.size(); i++){
            Total = setPieces[i] + Total;
            if(setPieces[i] > 0){
                if (setPieces[i] > Max){
                    Max = setPieces[i];
                    setIndexMax = i;
                }
                if (setPieces[i] < Min){
                    Min = setPieces[i];
                    setIndexMin = i;
                }
                setCountNonZero++;
            }
        }
        Average = (Total/setCountNonZero);
        cout << "Average part count for " << setCountNonZero << " sets: " << Average << "\n" << endl;

        cout << "Set with the smallest part count:" << endl;
        cout << "Name: " << setName[setIndexMin] << endl;
        cout << "Number: " << setNumber[setIndexMin] << endl;
        cout << "Theme: " << setTheme[setIndexMin] << endl;
        cout << "Price: $" << setPrice[setIndexMin] << endl;
        cout << "Minifigures: " << setMinifigs[setIndexMin] << endl;
        cout << "Piece count: " << setPieces[setIndexMin] << "\n" <<endl;

        cout << "Set with the largest part count:" << endl;
        cout << "Name: " << setName[setIndexMax] << endl;
        cout << "Number: " << setNumber[setIndexMax] << endl;
        cout << "Theme: " << setTheme[setIndexMax] << endl;
        cout << "Price: $" << setPrice[setIndexMax] << endl;
        cout << "Minifigures: " << setMinifigs[setIndexMax] << endl;
        cout << "Piece count: " << setPieces[setIndexMax] << "\n" <<endl;

    }
    else if(choice == 6){
        float Max = 0;
        float Min = 10000;
        float Average = 0;
        float Total = 0;
        int setIndexMax = 0;
        int setIndexMin = 0;
        int setCountNonZero = 0;
        for(unsigned int i = 0; i < setPrice.size(); i++){
            Total = setPrice[i] + Total;
            if (setPrice[i] > 0){
                if (setPrice[i] > Max){
                    Max = setPrice[i];
                    setIndexMax = i;
                }
                if (setPrice[i] < Min){
                    Min = setPrice[i];
                    setIndexMin = i;
                }
                setCountNonZero++;
            }
        }
        Average = (Total/setCountNonZero);
        cout << "Average price for " << setCountNonZero << " sets: $" << Average << "\n" << endl;

        cout << "Least expensive set:" << endl;
        cout << "Name: " << setName[setIndexMin] << endl;
        cout << "Number: " << setNumber[setIndexMin] << endl;
        cout << "Theme: " << setTheme[setIndexMin] << endl;
        cout << "Price: $" << setPrice[setIndexMin] << endl;
        cout << "Minifigures: " << setMinifigs[setIndexMin] << endl;
        cout << "Piece count: " << setPieces[setIndexMin] << "\n" <<endl;

        cout << "Most expensive set:" << endl;
        cout << "Name: " << setName[setIndexMax] << endl;
        cout << "Number: " << setNumber[setIndexMax] << endl;
        cout << "Theme: " << setTheme[setIndexMax] << endl;
        cout << "Price: $" << setPrice[setIndexMax] << endl;
        cout << "Minifigures: " << setMinifigs[setIndexMax] << endl;
        cout << "Piece count: " << setPieces[setIndexMax] << "\n" <<endl;

    }
    else if(choice == 7){
        int Max = 0;
        int Min = 10000;
        int Average = 0;
        int Total = 0;
        int setIndexMax = 0;
        int setIndexMin = 0;
        int setCountNonZero = 0;
        for(unsigned int i = 0; i < setMinifigs.size(); i++){
            Total = setMinifigs[i] + Total;
            if (setMinifigs[i] > 0){
                if (setMinifigs[i] > Max){
                    Max = setMinifigs[i];
                    setIndexMax = i;
                }
                if (setMinifigs[i] < Min){
                    Min = setMinifigs[i];
                    setIndexMin = i;
                }
                setCountNonZero++;
            }
        }
        Average = (Total/setCountNonZero);
        cout << "Average number of minifigures: " << Average <<"\n" << endl;

        cout << "Set with the most minifigures:" << endl;
        cout << "Name: " << setName[setIndexMax] << endl;
        cout << "Number: " << setNumber[setIndexMax] << endl;
        cout << "Theme: " << setTheme[setIndexMax] << endl;
        cout << "Price: $" << setPrice[setIndexMax] << endl;
        cout << "Minifigures: " << setMinifigs[setIndexMax] << endl;
        cout << "Piece count: " << setPieces[setIndexMax] << "\n" <<endl;

        cout << "Set with the fewest minifigures:" << endl;
        cout << "Name: " << setName[setIndexMin] << endl;
        cout << "Number: " << setNumber[setIndexMin] << endl;
        cout << "Theme: " << setTheme[setIndexMin] << endl;
        cout << "Price: $" << setPrice[setIndexMin] << endl;
        cout << "Minifigures: " << setMinifigs[setIndexMin] << endl;
        cout << "Piece count: " << setPieces[setIndexMin] << "\n" <<endl;

    }
    else if(choice == 8){
        float totalPrice = 0;
        int totalPieces = 0;
        int totalMinifigs = 0;
        for(unsigned int i = 0; i < setPrice.size(); i++){
            totalPrice = setPrice[i] + totalPrice;
            totalPieces = setPieces[i] + totalPieces;
            totalMinifigs = setMinifigs[i] + totalMinifigs;
        }
        cout << "If you bought one of everything..." << endl;
        cout << "It would cost: $" << totalPrice << endl;
        cout << "You would have " << totalPieces <<" pieces in your collection" << endl;
        cout << "You would have an army of " << totalMinifigs << " minifigures!" << endl;

    }
    else if(choice == 0){
        exit(0);
    }
    else{
        cout << "Invalid input!"<<endl;
    }
    return 0;
}


