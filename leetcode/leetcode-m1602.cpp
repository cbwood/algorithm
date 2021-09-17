//
// Created by cb on 2021/9/17.
//

#include "vector"
#include "string"
#include "map"
using namespace std;

class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        for(auto &x: book) ma[x]++;
    }

    int get(string word) {
        return ma[word];
    }

private:
    map<string, int> ma;
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */