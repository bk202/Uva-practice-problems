#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

vector <string> tokenize(string input) {
	vector <string> output;
	string word = "";
	for (unsigned int i = 0; i <= input.size(); i++) {
		char c = input[i];
		if (c == ' ' || i == input.size()) {
			output.push_back(word);
			word = "";
		}
		else {
			word += c;
		}
	}

	return output;
}

int main() {
	int test_cases;
	cin >> test_cases;

	for (int cases = 0; cases < test_cases; cases++) {
		string l1, l2, l3;

		if (cases == 0) { // A pretty stupid bug in C++11
			cin.ignore();
		}

		getline(cin, l1);
		getline(cin, l2);
		getline(cin, l3);

		vector <string> case_1 = tokenize(l1);
		vector <string> case_2 = tokenize(l2);
		vector <string> case_3 = tokenize(l3);

		vector <vector <string> > total_cases;
		total_cases.push_back(case_1);
		total_cases.push_back(case_2);
		total_cases.push_back(case_3);

		set <char> real_coins;
		set <char> light_coins;
		set <char> heavy_coins;

		for (unsigned int i = 0; i < total_cases.size(); i++) {
			string out_come = total_cases.at(i).at(2);
			string left = total_cases.at(i).at(0);
			string right = total_cases.at(i).at(1);

			if (out_come == "even") {
				for (unsigned int i = 0; i < left.size(); i++) {
					real_coins.insert(left[i]);
				}
				for (unsigned int i = 0; i < right.size(); i++) {
					real_coins.insert(right[i]);
				}
			}
			else if (out_come == "up") {
				for (unsigned int i = 0; i < left.size(); i++) {
					heavy_coins.insert(left[i]);
				}
				for (unsigned int i = 0; i < right.size(); i++) {
					light_coins.insert(right[i]);
				}
			}
			else if (out_come == "down") {
				for (unsigned int i = 0; i < left.size(); i++) {
					light_coins.insert(left[i]);
				}
				for (unsigned int i = 0; i < right.size(); i++) {
					heavy_coins.insert(right[i]);
				}
			}
		}

		//Find the coins that have participated in an unbalanced event only, excluding those that have participated in an balanced event
		set <char> light_coins2;
		set_difference(light_coins.begin(), light_coins.end(), real_coins.begin(), real_coins.end(), inserter(light_coins2, light_coins2.begin()));

		set <char> heavy_coins2;
		set_difference(heavy_coins.begin(), heavy_coins.end(), real_coins.begin(), real_coins.end(), inserter(heavy_coins2, heavy_coins2.begin()));

		//Exclude the coins that have participated in both the heavy and the light side of the event
		light_coins.clear();
		heavy_coins.clear();
		set_difference(light_coins2.begin(), light_coins2.end(), heavy_coins2.begin(), heavy_coins2.end(), inserter(light_coins, light_coins.begin()));
		set_difference(heavy_coins2.begin(), heavy_coins2.end(), light_coins2.begin(), light_coins2.end(), inserter(heavy_coins, heavy_coins.begin()));

		//Find the coins that have participated in all the unbalanced events
		set <char> light_intersect = light_coins;
		set <char> heavy_intersect = heavy_coins;
		for (unsigned int i = 0; i < total_cases.size(); i++) {
			string out_come = total_cases.at(i).at(2);
			string left = total_cases.at(i).at(0);
			string right = total_cases.at(i).at(1);
			if (out_come == "up" || out_come == "down") {
				set <char> tmp;
				for (unsigned int i = 0; i < left.size(); i++) {
					tmp.insert(left[i]);
				}
				for (unsigned int i = 0; i < right.size(); i++) {
					tmp.insert(right[i]);
				}
				set <char> tmp_light;
				set <char> tmp_heavy;
				set_intersection(tmp.begin(), tmp.end(), light_intersect.begin(), light_intersect.end(), inserter(tmp_light, tmp_light.begin()));
				set_intersection(tmp.begin(), tmp.end(), heavy_intersect.begin(), heavy_intersect.end(), inserter(tmp_heavy, tmp_heavy.begin()));

				light_intersect = tmp_light;
				heavy_intersect = tmp_heavy;
			}
		}

		if (light_intersect.size() != 0) {
			cout << *light_intersect.begin() << " is the counterfeit coin and it is light." << endl;
		}
		if (heavy_intersect.size() != 0) {
			cout << *heavy_intersect.begin() << " is the counterfeit coin and it is heavy." << endl;
		}

	}
	return 0;
}
