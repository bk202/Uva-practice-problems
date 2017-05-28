#include <iostream>

using namespace std;

/*
(Z * L + I) mod M
*/

int main() {
	int Z, I, M, L;
	int current_case = 1;
	while (1) {
		cin >> Z >> I >> M >> L;
		if (Z == 0 && I == 0 && M == 0 && L == 0) {
			break;
		}

		int *generated_numbers = new int[M];
		for (int i = 0; i < M; i++) {
			generated_numbers[i] = 0;
		}

		int ran_num = (Z * L + I) % M;
		int cycles = 1;
		generated_numbers[ran_num] = 1;
		while (1) {
			ran_num = (Z * ran_num + I) % M;
			if (generated_numbers[ran_num] == 1) {
				break;
			}
			else {
				generated_numbers[ran_num] = 1;
				cycles++;
			}
		}
		cout << "Case " << current_case << ": " << cycles << endl;
		current_case++;
	}
	return 0;
}
