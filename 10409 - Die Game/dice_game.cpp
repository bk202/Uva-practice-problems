#include <iostream>
#include <string>

using namespace std;

/*

n
w   e
s

*/

struct die {
	int top = 1;
	int north = 2;
	int west = 3;
};

int main() {
	int num;
	while (1) {
		cin >> num;
		if (num == 0) break;
		die D;
		string t;
		for (int i = 0; i<num; i++) {
			cin >> t;
			if (t == "north") {
				int top = 7 - D.north;
				int north = D.top;

				D.top = top;
				D.north = north;
			}

			else if (t == "south") {
				int top = D.north;
				int north = 7 - D.top;

				D.top = top;
				D.north = north;
			}

			else if (t == "west") {
				int top = 7 - D.west;
				int west = D.top;

				D.top = top;
				D.west = west;
			}

			else if (t == "east") {
				int top = D.west;
				int west = 7 - D.top;

				D.west = west;
				D.top = top;
			}
		}
		cout << D.top << endl;
	}
	return 0;
}
