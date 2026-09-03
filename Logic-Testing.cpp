#include <iostream>
using namespace std;
char buffer[7] = {'A', 'N', 'D', ' ', '1', ' ', '0'};
int oprand1, oprand2, varoprator;

char calculatespecial(int d1, int d2, int op) {
    if (op == 0) {
        if (d1 == 1 && d2 == 1) {
            return '0';
        } else {
            return '1';
        }
    } else if (op == 1) {
        if ((d1 == 1 && d2 == 1) || (d1 == 0 && d2 == 0)) {
            return '1';
        } else {
            return '0';
        }
    } else if (op == 2) {
        if (d1 == '1' && d2 == '1') {
            return '1' ;
        } else {
            return '0';
        }
    } else if (op == 3) {
        if ((d1 == 1 && d2 == 0) || (d1 == 0 && d2 == 1)) {
            return '1';
        } else {
            return '0';
        }
    } else if (op == 4) {
        if (d1 == 0 && d2 == 0) {
            return '1';
        } else {
            return '0';
        }
    } else if (op == 5) {
        if (d1 == 0) {
            return '1';
        } else {
            return '0';
        }
    } else {
        return 'x';
    }
}

// nand xnor
void token4digit(){
    oprand1 = buffer[5];
    oprand2 = buffer[7];
    if (buffer[0] == 'N' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'D') {
        varoprator = 0;
    } else if (buffer[0] == 'X' && buffer[1] == 'N' && buffer[2] == 'O' && buffer[3] == 'R') {
        varoprator = 1;
    } else {
        cout << "x" << endl;
    }
    cout<<calculatespecial(oprand1, oprand2, varoprator)<<endl;
}

// and xor nor not
void token3digit(){
    oprand1 = buffer[4];
    oprand2 = buffer[6];
    cout<<"stored digits"<<endl;
    for (int i = 0; i < 3; i++) {
        cout<<buffer[i]<<endl;
    }
    if (buffer[1] == 'O') {
        cout<<"o found" << endl;
        if (buffer[2] == 'T' && buffer[0] == 'N') {
            cout<<"mode 3 digit not" << endl;
            varoprator = 5;
        } else if (buffer[2] == 'R') {
        if (buffer[0] == 'X') {
            cout<<"mode 3 digit xor" << endl;
            varoprator = 3;
        } else if (buffer[0] == 'N') {
            cout<<"mode 3 digit nor" << endl;
            varoprator = 4;
        }
    } else if (buffer[0] == 'A' && buffer[1] == 'N' && buffer[2] == 'D') {
        cout<<"mode 3 digit and" << endl;
        varoprator = 2;
    } else {
        cout << "x" << endl;
    }
    }
    cout<<oprand1<<endl;
    cout<<oprand2<<endl;
    cout<<varoprator<<endl;
    cout<<calculatespecial(oprand1, oprand2, varoprator)<<endl;
}

// + - * /
void token1digit(){
    if (buffer[2] == '+') {
        cout << oprand1 + oprand2 << endl;
    } else if (buffer[2] == '-') {
        cout << oprand1 - oprand2 << endl;
    } else if (buffer[2] == '*') {
        cout << oprand1 * oprand2 << endl;
    } else if (buffer[2] == '/') {
        cout << oprand1 / oprand2 << endl;
    } else {
        cout << "x" << endl;
    }
}

bool checknumber(int index1, int index2) {
    if (buffer[index1] >= '0' && buffer[index1] <= '9') {
        if (buffer[index2] >= '0' && buffer[index2] <= '9') {
            return true;
        }
    }
    return false;
}

bool checkdigit(int index1, int index2) {
    if (buffer[index1] == '0' || buffer[index1] == '1') {
        if (buffer[index2] == '0' || buffer[index2] == '1') {
            return true;
        }
    }
    return false;
}

int main() {

for (int i = 0; i < 5; i++) {
    if (buffer[i] != ' ') {
        continue;
    } else {
        if (i == 1) {
            if (checknumber(0, 4) == true) {
                oprand1 = buffer[0] - '0';
                oprand2 = buffer[4] - '0';
                token1digit();
            } else {
                cout << "x" << endl;
            }       
        } else if (i == 2) { //or
            if (checkdigit(3, 5) == true) {
                oprand1 = buffer[3];
                oprand2 = buffer[5];
            } else {
                cout << "x" << endl;
            }
            if (oprand1 == '0' && oprand2 == '0') {
                cout << "0" << endl;
            } else {
                cout << "1" << endl;
            }
        } else if (i == 3) {
            if (checkdigit(4, 6) == true) {
                cout << "mode 3 digit" << endl;
                token3digit();
            } else {
                cout << "x" << endl;
            }
        } else if (i == 4) {
            if (checkdigit(5, 7) == true) {
                cout << "mode 4 digit" << endl;
                token4digit();
            } else {
                cout << "x" << endl;
            }
        } else {
            cout << "x" << endl;
        }
        break;
    }
}
return 0;
}