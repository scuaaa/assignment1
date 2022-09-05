#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string filename = "dataset.txt";


class city_management_array {
public:
	static vector<string> dataset[3];
	void read_data(string file);
	void intsert(string arg[]);
	int search_by_name(string arg);
	int search_by_coordinate(string arg[]);
	int delete_by_name(string arg);
	int delete_by_coordinate(string arg[]);
private:
	int dz = 0;
};

vector<string> city_management_array::dataset[3];


void city_management_array::read_data(string file) {

	ifstream infile;
	infile.open(file.data());
	cout << file.data();
	assert(infile.is_open());

	char dot = '.';
	char nagative = '-';
	string s;


	while (getline(infile, s)) {
		cout << s << endl;
		string data_element;
		int iteration = 0;
		int iteration_element = 0;
		for (auto c : s)
		{
			iteration += 1;
			if ((ispunct(c)) && !(c == dot) && !(c == nagative) || (iteration == size(s))) {
				cout << data_element << endl;
				dataset[iteration_element].push_back(data_element);
				data_element = "";
				iteration_element += 1;
			}
			else if (isspace(c)) {}
			else
			{
				data_element += c;
			}

		}

	}
	infile.close();

	dz = size(dataset[0]);

	for (int i = 0; i < dz-1; i++) {
		dataset[0][i] = dataset[0][i + 1];
	}

	dataset[0].pop_back();
	dz = size(dataset[0]);
};

void city_management_array::intsert(string arg[]) {
	dataset[0].push_back(arg[0]);
	dataset[1].push_back(arg[1]);
	dataset[2].push_back(arg[2]);
	dz += 1;
	cout << "successful insert the data\n";
	cout << dataset[0][dz-1] << endl;
	cout << dataset[1][dz-1] << endl;
	cout << dataset[2][dz-1] << endl;
}


int city_management_array::search_by_name(string arg) {
	
	for (int i = 0; i < dz; i++) {
		if (arg == dataset[0][i]) {
			cout << "find the record:\n" << dataset[0][i] + " " << dataset[1][i] + " " << dataset[2][i] + "" << endl;
			return (i+1);
		}
	}	
	return 0;
}

int city_management_array::search_by_coordinate(string arg[]) {
	for (int i = 0; i < dz; i++) {
		if ((arg[0] == dataset[1][i]) && (arg[1] == dataset[2][i])) {
			cout << "find the record:\n" << dataset[0][i] + " " << dataset[1][i] + " " << dataset[2][i] + "" << endl;
			return (i+1);
		}
	}
	return 0;
}

int city_management_array::delete_by_name(string arg) {
	int result = this->search_by_name(arg);
	if (!(result)) {
		cout << "no search result for delete" << endl;
		return 0;
	}
	else {
		if (result == dz) {
			for (int i = 0; i < 3; i++) {
				dataset[i].pop_back();
				cout << "successful delete the record: " + arg << endl;
			}
			dz -= 1;
			return 1;
		}
		else {
			for (int i = 0; i < 3; i++) {
				string mid_value = dataset[i][result - 1];
				dataset[i][result - 1] = dataset[i][dz - 1];
				dataset[i][dz - 1] = mid_value;
				// swap:(*(begin(dataset[i]) + result - 1), *(end(dataset[i]) - 1)); not work.
				dataset[i].pop_back();
				cout << "successful delete the record: " + arg << endl;				
			}
			dz -= 1;
			return 1;
		}
	}
}

int city_management_array::delete_by_coordinate(string arg[]) {
	int result = this->search_by_coordinate(arg);
	if (!(result)) {
		cout << "no search result for delete" << endl;
		return 0;
	}
	else {
		if (result == dz) {
			for (int i = 0; i < 3; i++) {
				dataset[i].pop_back();
				cout << "successful delete the record: " << arg << endl;
			}
			dz -= 1;
			return 1;
		}
		else {
			for (int i = 0; i < 3; i++) {
				string mid_value = dataset[i][result - 1];
				dataset[i][result - 1] = dataset[i][dz - 1];
				dataset[i][dz - 1] = mid_value;
				// swap:(*(begin(dataset[i]) + result - 1), *(end(dataset[i]) - 1)); not work.
				dataset[i].pop_back();
				cout << "successful delete the record: " << arg << endl;
			}
			dz -= 1;
			return 1;
		}
	}
}


int main(int abc) {

	city_management_array manage1;
	manage1.read_data(filename);

	string asd[] = { "s", "as", "123" };
	manage1.intsert(asd);
	int asc = manage1.search_by_name("Akron");
	cout << "asd:" << asc << endl;

	string sd[] = { "as","123" };
	int isd = manage1.search_by_coordinate(sd);
	cout << "isd: " << isd << endl;
	manage1.delete_by_name("Akron");
	asc = manage1.search_by_name("Akron");
	cout << "asc:" << asc << endl;

	int sdd = manage1.delete_by_coordinate(sd);
	return 0;

}

