#include<iostream>
#include<sstream>

using namespace std;

string validateInformation(string &email, string &password, fstream &file) {
    string line;
    while (getline(file, line)) {
        if (line.find(":" + email + ":") != string::npos)
            if (line.find(":" + password + ":") != string::npos)
                return line;
    }
    return "Not Found";
}

void showLoginMenu() {
    string email, password;
    fstream file;
    // Print screen
    cout << "===== Login =====" << endl;
    cout << "Please fill in the information: " << endl;
    cout << "Email: " << endl;
    cin >> email;
    cout << "Password: " << endl;
    cin >> password;
    cout << "Validating your information" << endl;

    vector<string> accInfo;

    try {
        // for validating
        file.open("../data/accounts.txt", ios::in);
        string line;

        line = validateInformation(email, password, file); // validate the inputs

        if (line == "Not Found") // if not found
            {throw runtime_error("Wrong email or password");}

        // if found split the information
        istringstream stringStream(line);
        string token;

        while (getline(stringStream, token, ':')) {
            accInfo.push_back(token);
        }

        cout << "Email and password Validated : Welcome " << accInfo[1] << " (" << accInfo[4] << ")" << endl;
        file.close();
        showOptionsMenu(accInfo[4]);
    }
    catch (const runtime_error &e) {
        cout << e.what() << endl;
        showMainMenu();
    }
}