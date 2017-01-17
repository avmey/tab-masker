//  main.cpp
//  Hangman
//
//  Created avmey on 1/17/17.
//  Copyright © 2017 A Meyer. All rights reserved.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    
    // Declare
    string play, word;
    int count = 0;
    int death = 0;
    
    // Intro
    cout << "Welcome to Hangman, coded by avmey in the winter of 2017." << endl;
    cout << "Ready to play? (yes/no)" << endl;
    cin >> play;
    
    // Check if they said yes
    while(play != "yes" and play != "Yes" and play != "YES") {
        if(play == "no" or play == "No") {
            cout << "Sorry to see you go so soon!" << endl;
            return 0;
        }
        else {
            cout << "Please type yes or no" << endl;
            cin >> play;
        }
    }
    
    cout << "Fetching your word" << endl;
    
    // Open filestream
    ifstream fin("words.txt");
    
    // Check if filestream is open
    if(!fin.is_open()) {
        cout << "You don't have words.txt downloaded in the same file" << endl;
        return 0;
    }
    
    // Get word from words.txt
    srand (int(time (0)));
    int wordNum = rand() % 2247;
    for(int i=0; i<wordNum; i++) {
        fin >> word;
    }
    
    // Close filestream
    fin.close();
    
    int num = int(word.length());
    
    cout << "Your word is " << num << " letters long." << endl;
    
    // Create vector for printed word
    vector<char> wordVec;
    for(int i = 0; i < num; i++){
        char blank = '_';
        wordVec.push_back(blank);
    }
    
    // Print blanks
    for(int i =0; i < int(wordVec.size()); i++) {
        cout << wordVec[i];
    }
    cout << endl;
    
    for(int i=0; i < 1000; i++){
        
        cout << "Please guess a letter." << endl;
        char letter;
        cin >> letter;
        
        for(int i=0; i < int(word.length()); i++) {
            if(letter == word[i]){
                count = count + 1;
                wordVec[i] = letter;
            }
        }
        
        if(count > 0) {
            for(int i =0; i < int(wordVec.size()); i++) {
                cout << wordVec[i];
            }
            cout << endl;
            cout << "There are " << count << " " << letter << "'s" << endl;
            count = 0;
        
            int numUnder = 0;
            for(int i =0; i < int(wordVec.size()); i++) {
                if(wordVec[i] == '_'){
                    numUnder = numUnder + 1;
                }
            }
            
            if(numUnder == 0) {
                cout << "Congrats! You've won the game & saved the man!" << endl;
                return 0;
            }
            
        }
        else {
            cout << "That letter is not in this word!" << endl;
            death = death + 1;
            
            if(death == 1){
                cout << "o" << endl;
            }
            else if (death == 2) {
                cout << "o" << endl;
                cout << "|" << endl;
            }
            else if (death == 3) {
                cout << " o" << endl;
                cout << "-|" << endl;
            }
            else if (death == 4) {
                cout << " o" << endl;
                cout << "-|-" << endl;
            }
            else if (death == 5) {
                cout << " o" << endl;
                cout << "-|-" << endl;
                cout << "/" << endl;
            }
            else if (death == 6) {
                cout << " o" << endl;
                cout << "-|-" << endl;
                cout << " ^ " << endl;
                cout << "You have killed your man! Better luck next time!" << endl;
                return 0;
            }
        }
    }
}
