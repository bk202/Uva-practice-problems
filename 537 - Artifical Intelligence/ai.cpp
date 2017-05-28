#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

#define UNKNOWN -0.0061
#define m 0.001
#define k 1000
#define M 1000000

enum state {
	P_enter,
	P_end,
	U_enter,
	U_end,
	I_enter,
	I_end,
	none
};

using namespace std;

double P = UNKNOWN;
double U = UNKNOWN;
double I = UNKNOWN;
double unit_size = 1.0;

int main() {
	int cases;
	cin >> cases;
	for (int current = 0; current < cases; current++) {
		cin.ignore();

		string question;
		getline(cin, question);
		state current_state = none;
		string value = "";
		P = U = I = UNKNOWN;
		unit_size = 1.0;
		for (unsigned int i = 0; i < question.size(); i++) {
			char c = question[i];

			if (c == '=') {
				char unit = question[i - 1];
				if (unit == 'P') {
					current_state = P_enter;
				}
				else if (unit == 'U') {
					current_state = U_enter;
				}
				else if (unit == 'I') {
					current_state = I_enter;
				}
				continue;
			}

			else if (current_state == P_enter) {
				if (c == 'm') {
					unit_size = m;
				}
				else if (c == 'W') {
					current_state = P_end;
				}
				else {
					value += question[i];
				}
			}
			else if (current_state == U_enter) {
				if (c == 'k') {
					unit_size = k;
				}
				else if (c == 'V') {
					current_state = U_end;
				}
				else {
					value += question[i];
				}
			}
			else if (current_state == I_enter) {
				if (c == 'M') {
					unit_size = M;
				}
				else if (c == 'A') {
					current_state = I_end;
				}
				else {
					value += question[i];
				}
			}
			else if (current_state == P_end) {
				P = atof(value.c_str()) * unit_size;
				value = "";
				unit_size = 1.0;
				current_state = none;
			}
			else if (current_state == U_end) {
				U = atof(value.c_str()) * unit_size;
				value = "";
				unit_size = 1.0;
				current_state = none;
			}
			else if (current_state == I_end) {
				I = atof(value.c_str()) * unit_size;
				value = "";
				unit_size = 1.0;
				current_state = none;
			}
		}

		if (P == UNKNOWN) {
			P = U * I;
			cout << "Problem #" << current + 1 << endl;
			cout << fixed;
			cout << setprecision(2);
			cout << "P=" << P << "W" << endl;
			cout << endl;
		}

		else if (U == UNKNOWN) {
			U = P / I;
			cout << "Problem #" << current + 1 << endl;
			cout << fixed;
			cout << setprecision(2);
			cout << "U=" << U << "A" << endl;
		}

		else if (I == UNKNOWN) {
			I = P / U;
			cout << "Problem #" << current + 1 << endl;
			cout << fixed;
			cout << setprecision(2);
			cout << "I=" << I << "V" << endl;
		}
	}
	return 0;
}
