#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class file {
public:
	string file_name;
	vector <file> children;
	file() {};
	~file() {};

	bool operator > (const file& F) const {
		return (this->file_name > F.file_name);
	}

	bool operator < (const file& F) const {
		return !(*this > F);
	}
};

vector <file> directories;

vector <string> tokenize(string input) {
	vector <string> output;
	string file_name = "";
	for (unsigned int i = 0; i <= input.size(); i++) {
		char c = input[i];
		if (c == '\\' || i == input.size()) {
			output.push_back(file_name);
			file_name = "";
		}
		else {
			file_name += input[i];
		}
	}

	return output;
}



void print_directory(file F, int level) {
	for (unsigned int i = 0; i < level; i++) {
		cout << " ";
	}
	cout << F.file_name << endl;
	sort(F.children.begin(), F.children.end());
	for (auto i : F.children) {
		print_directory(i, level+1);
	}
	return;
}

void insert_directory(file F) {
	for (unsigned int i = 0; i < directories.size(); i++) {
		if (F.file_name == directories.at(i).file_name) {
			file* dir_ptr_file = &directories.at(i);
			file* F_ptr_file = &F;
			while (1) {
				if (dir_ptr_file->children.size() == 0) break;
				if (F_ptr_file->children.size() == 0) break;
				if (dir_ptr_file->children.at(0).file_name != F_ptr_file->children.at(0).file_name) break;
				dir_ptr_file = &dir_ptr_file->children.at(0);
				F_ptr_file = &F_ptr_file->children.at(0);
			}

			dir_ptr_file->children.push_back(F_ptr_file->children.at(0));
			return;
		}
	}

	directories.push_back(F);
}

void build(vector <string> path) {
	file F;
	file* current_file = &F;
	current_file->file_name = path.at(0);
	for (unsigned int i = 1; i < path.size(); i++) {
		file tmp_file;
		tmp_file.file_name = path.at(i);
		current_file->children.push_back(tmp_file);
		current_file = &current_file->children.at(0);
	}

	insert_directory(F);
}

int main() {
	int num;
	while (cin >> num) {
		directories.clear();
		for (int cases = 0; cases < num; cases++) {
			if (cases == 0) {
				cin.ignore();
			}
			string t;
			getline(cin, t);
			vector <string> path = tokenize(t);
			build(path);
		}

		sort(directories.begin(), directories.end());
		for (auto i : directories) {
			print_directory(i, 0);
		}
	}

	return 0;
}
