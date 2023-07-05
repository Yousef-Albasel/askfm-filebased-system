#include <iostream>
#include <set>
#include <fstream>

using namespace std;

bool checkAvailability(const string &input, ifstream &file) {
    string line;
    while (getline(file, line)) {
        if (line.find(','+input+',') != string::npos) {
            return false;
        }
    }
    return true;
}


void showSignMenu() {
    ofstream accounts;
    accounts.open("../data/accounts.txt", ios::app);
    string username, email, password;
    cout << "===== SignUp =====" << endl;
    cout << "Please fill in the information: " << endl;

    // User Name Handling ======================
    cout << "Username: " << endl;
    char specialCharacters[] = {'@', '#', ';', ' ', '&', '^', '*', '$', '%', '(', ')'};
    while (true) {
        try {
            getline(cin, username);

            // Size test
            if (username.size() < 3) {
                throw runtime_error("Invalid Username: Size must be greater or equal to 3");
            }
            // invalid chars test
            for (auto i: specialCharacters) {
                if (username.find(i) != std::string::npos) {
                    if (i != ' ') {
                        throw runtime_error("Invalid Username: Username contains a special character");
                    } else {
                        throw runtime_error("Invalid Username: Username can't contain spaces ");
                    }
                }
            }

            // Check if username is available
            ifstream file("../data/accounts.txt", ios::in);
            if (!checkAvailability(username, file))
                throw runtime_error("Username is already used. Please pick another username.");
            file.close();
            break;
        } catch (const runtime_error &e) {
            cout << e.what() << endl;

        }
    }

    // Email Handling ======================

    cout << "Email: " << endl;
    string domains[] = {"@gmail.com", "@yahoo.com", "@outlook.com"};
    while (true) {
        bool noSpaces = true;
        try {
            getline(cin, email);
            // Size test
            if (email.size() < 10) {
                throw runtime_error("Invalid Email");
            }
            // invalid chars test
            if (email.find(' ') != string::npos)
                noSpaces = false;

            bool validDomain = false;
            for ( auto & domain : domains) {
                if (email.find(domain) != string::npos && noSpaces) {
                    validDomain = true;
                    break;
                }
            }
            if (!validDomain) {
                throw runtime_error("Invalid Email: Domain doesn't exist");
            }

            // Check if email is available
            ifstream file("../data/accounts.txt", ios::in);
            if (!checkAvailability(email, file)) {
                throw runtime_error("Email is already used. Please pick another email.");
            }
            file.close();
            break;
        }
        catch (const runtime_error &e) {
            cout << e.what() << endl;
        }
    }

    // Password Handling ======================
    cout << "Password:  " << endl;
    while (true) {
        try {
            getline(cin, password);
            // Size test
            if (password.size() < 6)
                throw runtime_error("Password Invalid: Password size must be greater than 6 letters");
            // invalid chars test
            if (password.find(' ') != string::npos)
                throw runtime_error("Password Invalid: Password cannot contain spaces.");
            break;
        }
        catch (const runtime_error &e) {
            cout << e.what() << endl;
        }
    }

    // Generate a unique id
    string id = IDGeneration();
    accounts << username << ',' << email << ',' << password << ',' << id << '\n';
    accounts.close();
    cout << "Account Created Successfully. Your id is: \"" << id << "\".\n";
    showMainMenu();
}
