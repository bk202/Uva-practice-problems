#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector <int> tokenize(string input) {
	vector <int> output;
	string value = "";
	for (unsigned int i = 0; i <= input.size(); i++) {
		if (input[i] == ' ' || i == input.size()) {
			int tmp;
			stringstream(value) >> tmp;
			value = "";
			output.push_back(tmp);
		}
		else {
			value += input[i];
		}
	}

	sort(output.begin(), output.end());

	vector <int> final_output;
	final_output.push_back(output.at(0)); //elminate duplicated numbers

	for (unsigned int i = 1; i < output.size(); i++) {
		if (output.at(i) != output.at(i - 1)) {
			final_output.push_back(output.at(i));
		}
	}
	return final_output;
}

vector <int> intersection(vector<int> setA, vector<int> setB) {
	vector <int> intersection;
	unsigned int i, j;
	for (i = 0, j = 0; i < setA.size() && j < setB.size();) {
		if (setA.at(i) < setB.at(j)) {
			i++;
		}
		else if (setA.at(i) > setB.at(j)) {
			j++;
		}
		else if (setA.at(i) == setB.at(j)) {
			intersection.push_back(setA.at(i));
			i++; j++;
		}
	}

	return intersection;
}

bool is_subset(vector<int> setA, vector<int> setB) {
	vector <int> intersect = intersection(setA, setB);
	if (intersect == setB) {
		return true;
	}

	return false;
}

bool is_equal(vector<int> setA, vector<int> setB) {
	return (setA == setB);
}

bool is_disjoint(vector<int> setA, vector<int> setB) {
	vector <int> intersect = intersection(setA, setB);

	if (intersect.size() == 0) {
		return true;
	}

	return false;
}

int main() {
	string l1, l2;
	while (getline(cin, l1)) {
		getline(cin, l2);

		vector <int> SetA;
		vector <int> SetB;

		SetA = tokenize(l1);
		SetB = tokenize(l2);

		if (is_disjoint(SetA, SetB)) {
			cout << "A and B are disjoint" << endl;
			continue;
		}

		else if (is_equal(SetA, SetB)) {
			cout << "A equals B" << endl;
		}

		else if (is_subset(SetA, SetB)) {
			cout << "B is a proper subset of A" << endl;
		}

		else if (is_subset(SetB, SetA)) {
			cout << "A is a proper subset of B" << endl;
		}
		else {
			cout << "I'm confused!" << endl;
		}
	}

	return 0;
}
