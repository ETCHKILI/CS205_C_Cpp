#include <iostream>
#include <vector>
#include <algorithm>

const std::vector<char> vowel = {'a','e','i','o','u'};

int main(){
    using namespace std;

    string word;
    int nVowel = 0;
    int nConsonant = 0;
    int nOther = 0;

    cout << "enter your word and enter a single q to end" << endl;

    while (cin >> word){
        if (word == "q")
            break;

        if (isalpha(word.at(0))){
            if (count(vowel.begin(), vowel.end(), word.at(0))){
                ++nVowel;
            }else{
                ++nConsonant;
            }
        }else {
            ++nOther;
        }
    }



    cout << "Vowels: " << nVowel << '\n';
    cout << "Consonant: " << nConsonant << '\n';
    cout << "Other: " << nOther << '\n';


}