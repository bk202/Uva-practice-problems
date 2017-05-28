#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;
	while (scanf("%d", &num) != EOF) {
		getchar();
		string s[5];
		string c1, c2;
		for (int pair = 0; pair<num; pair++) {
			c1 = c2 = "";
			for(int i=0; i<5; i++){
				s[i] = "";
			}
			char c;
			int i = 0;
			while ((c = getchar()) && c != '\n') {
				if (c == '<' || c == '>') {
					i++;
				}
				else {
					s[i] += c;
				}
			}

			for (int i = 0; i<5; i++) {
				cout << s[i];
			}
			cout<<endl;

			getline(cin, c2);
			c2 = c2.substr(0, c2.length() - 3);
			c2 += (s[3] + s[2] + s[1] + s[4]);
			
			cout<<c2<<endl;
		}
	}
	return 0;
}
