
#include <iostream>
using namespace std;
//#include<unordered_map>
#include<map>

void printmap(multimap<int, int> mymap) {
	for (auto it = mymap.begin(); it != mymap.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}
}

int main()
{
	multimap<int, int> mymap;
	mymap.insert(make_pair(1, 2));
	mymap.insert(make_pair(2, 5));
	mymap.insert(make_pair(1, 3));
	printmap(mymap);
	//cout << mymap[0] << endl;
	return 0;
}

