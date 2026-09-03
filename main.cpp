#include <iostream>
using namespace std;
char buffer[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int oprand1, oprand2, stop;

char calculatespecial(int d1, int d2, int op) {
    if (op == 0) { //nand
        if (d1 == '1' && d2 == '1') {
            return '0';
        } else {
            return '1';
        }
    } else if (op == 1) { //xnor
        if ((d1 == '1' && d2 == '0') || (d1 == '0' && d2 == '1')) {
            return '1';
        } else {
            return '0';
        }
    } else if (op == 2) { //and
        if (d1 == '1' && d2 == '1') {
            return '1' ;
        } else {
            return '0';
        }
    } else if (op == 3) { //xor
        if ((d1 == '1' && d2 == '0') || (d1 == '0' && d2 == '1')) {
            return '1';
        } else {
            return '0';
        }
    } else if (op == 4) { //nor
        if (d1 == '0' && d2 == '0') {
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
        cout<<calculatespecial(oprand1, oprand2, 0)<<endl;
    } else if (buffer[0] == 'X' && buffer[1] == 'N' && buffer[2] == 'O' && buffer[3] == 'R') {
        cout<<calculatespecial(oprand1, oprand2, 1)<<endl;
    } else {
        cout << "x" << endl;
    }
}

// and xor nor
void token3digit(){
    oprand1 = buffer[4];
    oprand2 = buffer[6];
    if (buffer[0] == 'A' && buffer[1] == 'N' && buffer[2] == 'D') {
        cout<<calculatespecial(oprand1, oprand2, 2)<<endl;
    } else if (buffer[0] == 'X' && buffer[1] == 'O' && buffer[2] == 'R') {
        cout<<calculatespecial(oprand1, oprand2, 3)<<endl;
    } else if (buffer[0] == 'N' && buffer[1] == 'O' && buffer[2] == 'R') {
        cout<<calculatespecial(oprand1, oprand2, 4)<<endl;
    } else {
        cout << "x" << endl;
    } 
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
        if (oprand2 == 0) {
            cout << "x" << endl;
            return;
        }
        float result = static_cast<float>(oprand1) / static_cast<float>(oprand2);
        cout << result << endl;
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

cin.getline(buffer, 9);

for (int i = 0; i < 9; i++) {
    if (buffer[i] == '\0' || buffer[i] == '\n') {
        stop = i;
        break;
    }
    if (buffer[i] == ' ') {
        continue;
    } else if ((buffer[i] >= '0' && buffer[i] <= '9') || (buffer[i] >= 'A' && buffer[i] <= 'Z')) {
        continue;
    } else if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/') {
        continue;
    } else {
        cout << "x" << endl;
        return 0;
    }
}

for (int i = 0; i < 5; i++) {
    if (buffer[i] != ' ') {
        continue;
    } else {
        if (i == 1) {
            if ((checknumber(0, 4) == true) && stop == 5) {
                oprand1 = buffer[0] - '0';
                oprand2 = buffer[4] - '0';
                token1digit();
            } else {
                cout << "x" << endl;
            }       
        } else if (i == 2) { //or
            if ((buffer[0] == 'O' && buffer[1] == 'R') && (checkdigit(3, 5) == true) && stop == 6) {
                oprand1 = buffer[3];
                oprand2 = buffer[5];
                if (oprand1 == '0' && oprand2 == '0') {
                    cout << "0" << endl;
                } else {
                    cout << "1" << endl;
                }
            } else {
                cout << "x" << endl;
            }
        } else if (i == 3) {
            if (buffer[0] == 'N' && buffer[1] == 'O' && buffer[2] == 'T' && stop == 5) { //not
                if (buffer[4] == '0') {
                    cout << "1" << endl;
                } else if (buffer[4] == '1') {
                    cout << "0" << endl;
                } else {
                    cout << "x" << endl;
                }
            } else if (checkdigit(4, 6) == true && stop == 7) {
                token3digit();
            } else {
                cout << "x" << endl;
            }
        } else if (i == 4) {
            if (checkdigit(5, 7) == true && stop == 8) {
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