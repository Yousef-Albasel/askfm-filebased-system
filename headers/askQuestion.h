#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

void askQuestion(const string &sender) {
    string receiver, question;
    cout << "Input receiver ID: " << endl;
    cin >> receiver;
    if (receiver == sender) {
        cerr << "Error: You Can't ask yourself!" << endl;
        showOptionsMenu(sender);
    }
    cout << "Ask a question: " << endl;
    cin.ignore();
    getline(cin, question);

    ifstream feedCounter("../data/feedCounter.txt");
    string counterForQuestions;
    if (feedCounter.is_open()) {
        feedCounter >> counterForQuestions;
        feedCounter.close();
    } else {
        cerr << "Failed to open file." << endl;
        return;
    }

    int counter = stoi(counterForQuestions);
    counter++;

    ofstream counterFile("../data/feedCounter.txt");
    if (counterFile.is_open()) {
        counterFile << counter; // Write back the incremented counter
        counterFile.close();
    } else {
        cerr << "Failed to open counter file." << endl;
        return;
    }

    string fileName = "../data/" + receiver + "/" + counterForQuestions + "-" + receiver + "-" + sender + ".txt";
    ofstream questionFile(fileName);
    if (questionFile.is_open()) {
        questionFile << "Question ID (" << counterForQuestions << ") from user (" << sender << ")" << " to (" << receiver<< "): \n" << question << endl;
        questionFile.close();
        cout << "Question saved successfully." << endl;

        // Create a copy of the question file in feed
        string feedDirectory = "../data/feed/";
        string feedFileName = feedDirectory + counterForQuestions + "-" + receiver + "-" + sender + ".txt";
        filesystem::copy(fileName, feedFileName, filesystem::copy_options::overwrite_existing);
        showOptionsMenu(sender);
    } else {
        cerr << "Failed to create question file." << endl;
        showOptionsMenu(sender);
    }
}

