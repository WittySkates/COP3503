// Lexer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "WordInfo.h"
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // TODO: Load words_to_ignore.txt, store those in a vector of strings to pass to your class objects


    cout << "1-4: Which file to open?" << endl;
    int option;
    cin >> option;
    if (option == 1){
        WordInfo section;
        section.ReadWordsFromFile("file1.txt");
        section.DisplayStats(2);
    }
    else if(option == 2){
        WordInfo section;
        section.ReadWordsFromFile("file2.txt");
        section.DisplayStats(3);

    }
    else if(option == 3){
        WordInfo section;
        section.ReadWordsFromFile("file3.txt");
        section.DisplayStats(4);

    }
    else if(option == 4){
        WordInfo section;
        section.ReadWordsFromFile("file4.txt");
        section.DisplayStats(5);

    }
    else if(option == 0){
        WordInfo section;
        section.ReadWordsFromFile("testfile.txt");
        section.DisplayStats(1);

    }
    else {
        cout << "Invalid input!"<<endl;
    }
    // TODO: Create a WordInfo object and set the list of words to ignore


    // Read the words from the file
    // Show the stats
    // Show the most frequent words, NOT using the ignore list (lots of "a" "of" "the" entries here)
    // Show the most frequent words, using the ignore list (to ignore the universally common words)

    // (Show a number of common words based on the selected file + 1. First file shows 2 common words, second shows 3, 4th shows 5, etc)

    // Get and then show the longest words

    // Get input for a word, and do an exact match search for that word. (Convert input to lowercase first!)
   /* cout << "Enter a word for an exact search: ";

    cout << '\'' << searchTerm << "' was found " << count << " times in the list.\n";

    // Ditto for partial search...
    cout << "Enter a word for a partial search: ";

    if (no matches found)
    cout << "\nNo entries match '" << searchTerm << '\'' << endl;
    else
    {
        cout << "\nWords containing '" << thesearchterm << '\'' << endl;

        // print list o' matches
    }
*/
    return 0;
}

