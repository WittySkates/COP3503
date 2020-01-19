#include "WordInfo.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cctype>
#include <algorithm>

WordInfo::WordInfo() {}

void WordInfo::ReadWordsFromFile(const char *filename) {
    string name = filename;
    ifstream file(name);
    string word;

    while(file >> word){
        allWords.push_back(word);
    }
    for(unsigned int i = 0; i < allWords.size(); i++){
        word = allWords[i];
        for(unsigned int j = 0; j < word.length(); j++){
            if(word.at(j) >= 65 && word.at(j) <= 90){
                word.at(j) = tolower(word.at(j));
            }
            if(word.length() == 2 && word.at(j) == 45){
                totalWords++;
            }
            else if(word.at(j) == 45){
                if(j == 0 || j == word.length() - 1){
                    word.at(j) = '^';
                }

            }
            else if(word.at(j) == 39){
                if(j == 0 || j == word.length() - 1){
                    word.at(j) = '^';
                }
            }

            else if(word.at(j) >= 97 && word.at(j) <= 122){
            }
            else if(word.at(j) <= 64){
                word.at(j) = '^';
            }
        }
        for(unsigned int k = 0; k < word.length(); k++){
            word.erase(remove(word.begin(), word.end(),  '^'), word.end());
        }
        allWords[i] = word;
    }
    int totalWordLength = 0;
    longestIndex = 0;
    for(unsigned int i = 0; i < allWords.size(); i++){
        totalWordLength += allWords[i].length();
        if(allWords[i].length() > allWords[longestIndex].length()){
            longestIndex = i;
        }
        wordMap.emplace(allWords[i], 0);
        auto found = wordMap.find(allWords[i]);
        if (found != wordMap.end()) {
            found->second += 1;
        }
    }
    for(unsigned int i = 0; i < allWords.size(); i++){
        if(allWords[i].length() >= allWords[longestIndex].length()){
            longestIndex = i;
            longestWords.push_back(allWords[i]);
        }
    }
    mostCommon = 0;
    unordered_map<string, int>::iterator itr;
    for(itr = wordMap.begin(); itr != wordMap.end(); itr++){
            frequentWords.push_back(itr->second);

        //cout << itr->first;
        //cout << "\t" << itr->second << endl;
    }
    sort(frequentWords.rbegin(), frequentWords.rend());

    unordered_map<string, int>::iterator it;
    int tracker = 0;
    while(tracker < frequentWords.size()) {
        for (it = wordMap.begin(); it != wordMap.end(); it++) {
            if (it->second == frequentWords[tracker]) {
                frequentWordsSorted.push_back(it->first);
                tracker++;
            }
        }
    }
    averageLength = totalWordLength/allWords.size();
    file.close();

    ifstream ignoredWords("words_to_ignore.txt");
    string ignored;
    while(ignoredWords >> ignored){
        unwantedSouls.push_back(ignored);
    }
}

void WordInfo::DisplayStats(int count) const {
    cout << "Total number of words: " << allWords.size() - (totalWords/2) << endl;
    cout <<"Number of unique words: " << wordMap.size() << endl;
    cout <<"Average word length: " << averageLength << endl;
    cout <<"Longest word: " << longestWords[0] << endl;
    MostCommonWords(count, true);
    MostCommonWords(count, false);
    cout << "Longest words:" << endl;
    for(unsigned int i = 0; i < longestWords.size(); i++) {
         cout << "\t" << longestWords[i] << endl;
    }
}

void WordInfo::MostCommonWords(int count, bool ignoreCommonFile) const {
    if(ignoreCommonFile == true) {
        cout << count << " most frequent words: " << endl;
        for (int i = 0; i < count; i++) {
            cout << "\t" << frequentWordsSorted[i] << endl;
        }
    }
    else if (ignoreCommonFile == false){
        cout << count << " most frequent words wihtout: " << endl;
        for(int i = 0; i < count; i++){
            cout << "\t" << frequentWordsSorted[i] << endl;
        }
    }
}

/*
void WordInfo::LongestWords(vector<string> &words) const {
    for(int i = 0; i < longestWords.size(); i++){
        words.push_back(longestWords[i]);
    }
}

void WordInfo::SetIgnoreWords(vector<string> &ignore) {}
int WordInfo::SearchForWords(const char &word) const {
    return 0;
}*/