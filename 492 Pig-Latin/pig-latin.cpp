#include <iostream>
#include <string>

using namespace std;

string pig_latin(string input) {
	if(input == " " || input == ""){
		return input;
	}
	string output = "";
	bool flag = false;
	if (input[input.size() - 1] == '.') {
		flag = true;
		input = input.substr(0, input.length() - 1);
	}

	char head = input[0];
	head = toupper(head);

	if (head == 'A' || head == 'E' || head == 'I' || head == 'O' || head == 'U') {
		input += "ay";
	}

	else if(head >= 'A' && head <= 'Z'){
		input += input[0];
		input.erase(0, 1);
		input += "ay";
	}

	if (flag) {
		input += ".";
	}

	output = input;

	return output;
}

int main() {
	string input;
	string output = "";

	while (getline(cin, input)) {
		output = "";
		string word = "";
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ' ' || i == input.size() - 1) {
				if(i == input.size() - 1){
					word += input[i];
				}
				output += pig_latin(word);
				if (i < input.size() - 1) {
					output += " ";
				}
				word = "";
			}
			else {
				word += input[i];
			}
		}

		cout << output << endl;
	}
	return 0;
}
