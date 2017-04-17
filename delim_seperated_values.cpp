#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>     // for exit()
#include <cctype>      // for tolower()
#include <algorithm>   // for std::transform()
#include <vector>
#include <iterator>

using namespace std;

// split function for C++
// splits based on char delim value -- from  http://stackoverflow.com/questions/236129/split-a-string-in-c
template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}
std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}



int main(int argc, char *argv[]) {
	char delim;
	if (argc == 2) {
		delim  = argv[1][0];
	} else {
		cout << "supply a delim with the program run\nexiting\n";
		exit(-1);
	}
	string fullinput="";
	string line="";
	while (!cin.eof()) {
		getline(cin,line);
		if (!cin.fail()) {
			fullinput+=line;
		}
	}
	vector<string> delimSizeVec = split(fullinput, delim);
	cout << "Number of " << delim << " = " << delimSizeVec.size()-1 << endl;
	cout << "Number of objects seperated: " << delimSizeVec.size() << endl;
	cout << "objects are: " << endl;
	for (auto &it : delimSizeVec) {
		cout << it << "  ";
	}
	cout << endl;
}
