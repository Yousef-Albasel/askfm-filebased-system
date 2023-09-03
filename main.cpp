/*
 * بسم الله الرحمن الرحيم *
 * AskFM Clone By Yousef Albasel
 * Started working 3/6/2023
 * Student at Faculty of Computers and Artificial Intelligence - Cairo University
 */
#include <iostream>
#include <string>
#include "headers/IDGeneration.h"
#include "headers/ShowMenu.h"
#include "headers/AccountHandling.h"
#include "headers/LoginHandling.h"
#include "headers/askQuestion.h"
#include "headers/answerQuestion.h"
using namespace std;


int main() {
    cout << "Current working directory: " << filesystem::current_path() << endl;

    ifstream feedCounter;
    feedCounter.open("../data/feedCounter.txt");
    string counterForQuestions;
    if (feedCounter.is_open()) {
        while (feedCounter >> counterForQuestions) {
        }
        feedCounter.close();
    } else {
        cerr << "Failed to open file." << std::endl;
    }

// Printing Main menu
    showMainMenu();
    return 0;

}
