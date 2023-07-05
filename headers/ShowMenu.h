#include <iostream>

using namespace std;
void showSignMenu(); //Function Prototype
void showMainMenu() {
    cout << "===== AskFM Clone =====" << endl;
    cout << "Menu: " << endl;
    cout << "   1 - Login " << endl;
    cout << "   2 - Sign Up " << endl;
    int choice;
    while (true) {
        cout << "Enter a number [1, 2]: "<<'\n';
        cin >> choice;

        switch (choice) {
            case 1:
                break;
            case 2:
                showSignMenu();
                break;
            default:
                cout << "Invalid input. Please enter a valid number [1, 2].\n";
                continue;
        }
        break;
    }
}
