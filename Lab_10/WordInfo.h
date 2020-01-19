#ifndef LAB_10_WORDINFO_H
#define LAB_10_WORDINFO_H

#include <string>
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class WordInfo {
private:
    int totalWords = 0;
    int averageLength;
    int uniqueWords;
    int longestIndex;
    int mostCommon;

public:
    vector<string> longestWords;
    vector<int> frequentWords;
    vector<string> frequentWordsSorted;
    vector<string> unwantedSouls;
    vector<string> allWords;
    unordered_map<string, int> wordMap;

    void ReadWordsFromFile(const char *filename);
    void DisplayStats(int count) const;
    void MostCommonWords(int count, bool ignoreCommonFile = false) const;
    void LongestWords(vector<string> &words) const;
    void SetIgnoreWords(vector<string> &ignore);
    int SearchForWords(const char &word) const;

    WordInfo();
};



#endif //LAB_10_WORDINFO_H
