#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string innick, inpass, line, what, permchange;
int perms, idr;

void regdone() {
    ifstream in("data.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            idr++;
        }
    }
    in.close();
    ofstream out("data.txt", ios::app);
    if (out.is_open()) {
        out << idr + 1 << " " << innick << ":" << inpass << " 0" << endl;
    }
    out.close();
    cout << "Done.";
}

void registration() {
    cout << "[R] Input nickname >> ";
    getline(cin, innick);
    cout << "[R] Input password >> ";
    getline(cin, inpass);
    cout << inpass[inpass.size()];
    if (inpass.size() < 6) {
        cout << "[R] At least 6 digits pass.\n\n";
        registration();
    }
    else {
        regdone();
    }
}

void list() {
    int id = 1;
    ifstream in("data.txt");
    cout << "[ID] username:pass [perms]\n";
    cout << "- --- -- -------- -- --- -\n";
    if (in.is_open()) {
        while (getline(in, line)) {
            line.erase(0, 2);
            cout << "[" << id << "] " << line.erase(line.size() - 2) << " [" << line[line.size() - 1] << "]" << endl;
            cout << "- --- -- -------- -- --- -\n";
            id++;
        }
    }
    cout << "Users: " << id - 1;
    in.close();
}

void search() {
    int id;
    cout << "Input user id >> ";
    cin >> id;
    int i = 0;
    cout << "\n";
    cout << "[ID] username:pass [perms]\n";
    cout << "- --- -- -------- -- --- -\n";
    ifstream in("data.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            i++;
            if (i == id) {
                cout << "[" << id << "] " << line.erase(line.size() - 2) << " [" << line[line.size() - 1] << "]" << endl;
            }
        }
    }
    in.close();
}

void logged_admin() {
    int i = 1;
    string panel;
    cout << "- -- --- [ Admin Panel ] --- -- -\n\n";
    cout << "To see user database enter [list]\n";
    cout << "To search user by ID enter [search]\n\n";
    while (panel != "list" && panel != "search") {
        cout << "[ " << innick << " ] : I want to >> ";
        getline(cin, panel);
    }
    if (panel == "list") {
        list();
    }
    if (panel == "search") {
        search();
    }
}

void logged() {
    int i = 1;
    cout << "[System] Hi, " << innick << "! What shall we do now?\n\n";
}

void login() {
    int l = 0;
    string temp;
    cout << "Input nickname >> ";
    getline(cin, innick);
    cout << "Input password >> ";
    getline(cin, inpass);
    cout << "\n";
    string userinput = innick + ":" + inpass;
    ifstream in("data.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            temp = line;
            temp.erase(temp.size() - 2);
            temp.erase(0, 2);
            if (userinput == temp) {
                if (line[line.size() - 1] == '1') {
                    cout << "[System] Logged as administrator.\n\n";
                    perms = 1;
                    l = 1;
                    break;
                }
                cout << "[System] Login successful!\n\n";
                perms = 0;
                l = 1;
                break;
            }
        }
        if (l == 0) {
            cout << "Wrong nickname or password, try again.\n\n";
            login();
        }
        if (perms == 1) {
            logged_admin();
        }
        if (perms == 0 && l == 1) {
            logged();
        }
    }
    in.close();
}

int main()
{
    cout << "- -- --- [ Hello, Guest! ] --- -- -\n\n";
    cout << "To login enter [login]\n";
    cout << "To register enter [register]\n\n";
    while (what != "register" && what != "login") {
        cout << "[ Guest ] : I want to >> ";
        getline(cin, what);
    }
    if (what == "register") {
        cout << "\n";
        registration();
    }
    if (what == "login") {
        cout << "\n";
        login();
    }
}
