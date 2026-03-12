#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Lab 11
// TODO: реализуйте решение по заданию в labs/lab11_io/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
int main() {
    ifstream file("data.txt");

    string line;
    vector<string> words;

    while (getline(file, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            words.push_back(word);
        }
    }

    file.close();

    // for (const string& w : words) {
    //     cout << w << endl;
    // }
    int mass[50];
    int ind_long_word = 0;
    int chet = 0;

    for(int i = 0; i < 50; i++){
        mass[i] = 0;
    }


    for (int i = 0; i< words.size(); i++){
        for (int j = 0; j < words.size(); j++){
            if(i!=j && words[i].find(words[j]) != string::npos){
                cout << words[j] << " VHODIT V " << words[i] << endl;
                mass[j] += 1;
                chet += 1;
                if(words[j].length() > words[ind_long_word].length() || chet == 1) {
                    ind_long_word = j;
                }
            }
        }
    }

    int max_mass = mass[0];
    int ind_max = 0;
    for(int i = 0; i < 50; i++){
        if(mass[i] > max_mass){
            max_mass = mass[i];
            ind_max = i;
        }
    }
    cout << endl <<"Longer root " <<words[ind_long_word] <<" Popularite root " << words[ind_max]  <<endl;
    cout << words[ind_long_word] <<" : " ; 

    for(int i = 0; i < words.size(); i++){
        if(words[i].find(words[ind_long_word]) != string::npos && ind_long_word != i){
            cout << words[i] << " " ;
        }
    }

    cout << endl << words[ind_max] <<" : " ;
    for(int i = 0; i < words.size(); i++){
        if(words[i].find(words[ind_max]) != string::npos && ind_max != i){
            cout << words[i] << " " ;
        }
    }

    return 0;
}
