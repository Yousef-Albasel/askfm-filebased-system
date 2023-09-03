#include <iostream>

using namespace std;
void showSignMenu(); //Function Prototype
void showLoginMenu(); //Function Prototype
void askQuestion(const string& sender);
void showMainMenu() {
    cout << "===== AskFM Clone =====" << endl;
    cout << "Menu: " << endl;
    cout << "   1 - Login " << endl;
    cout << "   2 - Sign Up " << endl;
    cout << "   3 - Exit " << endl;
    int choice;
    while (true) {
        cout << "Enter a number [1, 2]: "<<'\n';
        cin >> choice;

        switch (choice) {
            case 1:
                showLoginMenu();
                break;
            case 2:
                showSignMenu();
                break;
            case 3:
                cout << "We will miss you !" << endl;
                break;
            default:
                cout << "Invalid input. Please enter a valid number [1, 2].\n";
                continue;
        }
        break;
    }
}

void showOptionsMenu(const string& id) {
    cout << "===== AskFM Clone =====" << endl;
    cout << "Logged in as "<< id << " : " << endl;
    cout << "Options: " << endl;
    cout << "   1 - Ask Questions " << endl;
    cout << "   2 - Answer Questions " << endl;
    cout << "   3 - Show Feed " << endl;
    cout << "   4 - Show Users " << endl;
    cout << "   5 - Log out " << endl;
    int choice;
    while (true) {
        cout << "Enter a number [1, 2]: "<<'\n';
        cin >> choice;

        switch (choice) {
            case 1:
                askQuestion(id);
                break;
            case 2:
                break;
            case 5:
                showMainMenu();
                break;
            default:
                cout << "Invalid input. Please enter a valid number [1, 2].\n";
                continue;
        }
        break;
    }
}
