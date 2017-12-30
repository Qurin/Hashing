//powered by Qurin

#include <iostream>
#include <string>
#include "Hash.h"

using namespace hash;

int main() {
	//variables inicializing
	Hash hash;
	string str;
	int len;

	//output
	cin >> str >> len;
	cout << hash.getHash(str, len) << endl;


	system("PAUSE");
	return 0;
}
