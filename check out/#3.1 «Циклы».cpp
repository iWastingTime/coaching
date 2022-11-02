#include <iostream>

using namespace std;

int main() {
    for (;;) {
        int k, n, o = 0;
        cout << "Input cycle count >> ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ ERROR ] << Not a number.\n" << endl;
            continue;
        }
        if (k < 0) {
            cout << "\n[ ERROR ] << Must be positive.\n" << endl;
            continue;
        }
        cout << "Input n >> ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ ERROR ] << Not a number.\n" << endl;
            continue;
        }
        cout << "\n- -- --- ---- ---- --- -- -\n";
        for (int i = 1; i <= k; i++) {
            o += n;
            if (i % 2 == 0) {
                o = o * 2;
                cout << " [" << i << "] " << o << " [*] " << endl;
            }
            else {
                cout << " [" << i << "] " << o << endl;
            }
        }
        cout << "- -- --- ---- ---- --- -- -\n\n";
    }
}
