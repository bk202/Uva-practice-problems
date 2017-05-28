#include <iostream>
#include <string>
#include <vector>

enum state {
	consonant_state,
	vowel_state
};

using namespace std;

/*
5 / 7 / 5
*/

vector <vector <string> > tokenize(string haiku) {
	vector <vector <string> > HV;
	string word = "";
	vector <string> line;
	for (unsigned int i = 0; i <= haiku.size(); i++) {
		if (haiku[i] == ' ') {
			line.push_back(word);
			word = "";
		}
		else if (haiku[i] == '/' || i == haiku.size()) {
			line.push_back(word);
			HV.push_back(line);
			line.clear();
			word = "";
		}
		else {
			word += haiku[i];
		}
	}

	//for (unsigned int i = 0; i<HV.size(); i++) {
	//	for (unsigned int j = 0; j<HV.at(i).size(); j++) {
	//		cout << HV.at(i).at(j) << " ";
	//	}
	//	cout << endl;
	//}

	return HV;
}

int count_syllables(vector <string> input) {
	int syllables = 0;
	for (unsigned int i = 0; i < input.size(); i++) {
		string word = input.at(i);
		state current_state = consonant_state;
		for (unsigned int j = 0; j < word.size(); j++) {
			char c = word[j];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
				current_state = vowel_state;
				if (j == word.size() - 1) {
					syllables++;
				}
			}

			else if (current_state == vowel_state) {
				if (c != 'a' || c != 'e' || c != 'i' || c != 'o' || c != 'u' || c != 'y') {
					current_state = consonant_state;
					syllables++;
				}
			}
		}
	}

	return syllables;
}

int main() {
	string haiku;
	while (1) {
		getline(cin, haiku);
		if (haiku == "e/o/i") {
			break;
		}
		vector <vector <string> > haikus = tokenize(haiku);
		int syllables[3];
		for (unsigned int i = 0; i < haikus.size(); i++) {
			syllables[i] = count_syllables(haikus.at(i));
		}

		if (syllables[0] != 5) {
			cout << "1" << endl;
		}
		else if (syllables[1] != 7) {
			cout << "2" << endl;
		}
		else if (syllables[2] != 5) {
			cout << "3" << endl;
		}
		else {
			cout << "Y" << endl;
		}
	}
	return 0;
}
