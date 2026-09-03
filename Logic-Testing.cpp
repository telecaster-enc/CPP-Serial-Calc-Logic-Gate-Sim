#include <iostream>
using namespace std;
char buffer[7] = {'A', 'N', 'D', ' ', '1', ' ', '0'};
int oprand1, oprand2, varoprator;

int sv = 0;

// nand xnor
void token4digit(){
    oprand1 = buffer[5];
    oprand2 = buffer[7];
    if (buffer[0] == 'N' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'D') {
        varoprator = 0;
        calculatespecial(oprand1, oprand2, varoprator);
    } else if (buffer[0] == 'X' && buffer[1] == 'N' && buffer[2] == 'O' && buffer[3] == 'R') {
        varoprator = 1;
        calculatespecial(oprand1, oprand2, varoprator);
    } else {
        cout << "invalid" << endl;
    }
}

// and xor nor not
void token3digit(){
    oprand1 = buffer[4];
    oprand2 = buffer[6];
    if (buffer[1] == 'O') {
        if (buffer[2] == 'T' && buffer[0] == 'N') {
            varoprator = 5;
            calculatespecial(oprand1, oprand2, varoprator);
        } else if (buffer[2] == 'R') {
        if (buffer[0] == 'X') {
            varoprator = 3;
            calculatespecial(oprand1, oprand2, varoprator);
        } else if (buffer[0] == 'N') {
            varoprator = 4;
            calculatespecial(oprand1, oprand2, varoprator);
        }
    } else if (buffer[0] == 'A' && buffer[1] == 'N' && buffer[2] == 'D') {
        varoprator = 2;
        calculatespecial(oprand1, oprand2, varoprator);
    } else {
        cout << "invalid" << endl;
    }
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
        cout << oprand1 / oprand2 << endl;
    } else {
        cout << "invalid" << endl;
    }
}

int calculatespecial(int d1, int d2, int op) {
    if (op == 1) {
        return d1 + d2;
    } else if (op == 2) {
        return d1 - d2;
    } else if (op == 3) {
        return d1 * d2;
    } else if (op == 4) {
        return d1 / d2;
    } else {
        cout << "invalid" << endl;
        return -1;
    }

}

int main() {

for (int i = 0; i < 7; i++) {
    if (buffer[i] != ' ') {
        continue;
    } else {
        cout << "detected space" << endl;
        if (i == 1) {
            oprand1 = buffer[0];
            oprand2 = buffer[4];
            token1digit();           
        } else if (i == 2) { //or
            cout << buffer[3] || buffer[5] << endl;
        } else if (i == 3) {
            token3digit();
        } else if (i == 4) {
            token4digit();
        } else {
            cout << "invalid" << endl;
            break;
        }
    }
}

return 0;
}