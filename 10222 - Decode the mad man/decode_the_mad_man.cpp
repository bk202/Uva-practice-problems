#include <iostream>
#include <string>

using namespace std;

char keyboard[47] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 91, 93, 92,
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 59, 39,
	'z', 'x', 'c', 'v', 'b', 'n', 'm', 44, 46, 47,
	'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 45, 61 
};

int search(char c) {
	for (int i = 0; i < 47; i++) {
		if (keyboard[i] == c) {
			return i;
		}
	}
}

int main() {
	string input;
	while (getline(cin, input)) {
		for (unsigned int i = 0; i < input.size(); i++) {
			char c = input[i];
			if (c == ' ') continue;
			c = tolower(c);
			int pos = search(c);

			input[i] = keyboard[pos - 2];
		}
		cout << input << endl;
	}

	return 0;
}
