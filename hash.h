#if !defined(HASH)
#define HASH

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace hash
{
	class Hash
	{
		string hash;
		int receivingExistCodes(int x);
		int getControlSum(string str);

	public:
		string getHash(string userString, unsigned int lengthHash);
	};

	int Hash::receivingExistCodes(int x) {
		x += 256;
		while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) {
			if (x < 48) { x += 24; }
			else { x -= 47; }
		}
		return x;
	}

	int Hash::getControlSum(string str) {
		unsigned int sault = 0, strlen = 0;
		for (; strlen < str.size(); strlen++)
			sault += int(str[strlen]);
		return sault;
	}

	string Hash::getHash(string userString, unsigned int lengthHash) {
		if (lengthHash > 3) {

			unsigned int minLen = 2;
			unsigned int realMLen = 0;
			unsigned int originalSault = this->getControlSum(userString);
			unsigned int originalLenghtStr = (userString.size());

			while (minLen <= lengthHash)
				realMLen = (minLen *= 2);

			while (minLen < originalLenghtStr)
				minLen *= 2;

			if ((minLen - originalLenghtStr) < minLen)
				minLen *= 2;

			int addCount = minLen - originalLenghtStr;

			for (int i = 0; i < addCount; i++)
				userString += this->receivingExistCodes(userString[i] + userString[i + 1]);

			int maxSault = this->getControlSum(userString);
			int maxLenghtStr = (userString.size());

			while (userString.size() != realMLen)
			{
				for (int i = 0, center = userString.size() / 2; i < center; i++)
					this->hash += this->receivingExistCodes(userString[center - i] + userString[center + i]);

				userString = this->hash;
				this->hash.clear();
			}

			unsigned int rem = realMLen - lengthHash;

			for (unsigned int i = 0, countCompress = realMLen / rem; this->hash.size() < (lengthHash - 4); i++)
			{
				if (i % countCompress == 0)
					this->hash += this->receivingExistCodes(userString[i] + userString[++i]);
				else
					this->hash += userString[i];
			}

			this->hash += receivingExistCodes(originalSault);
			this->hash += receivingExistCodes(originalLenghtStr);
			this->hash += receivingExistCodes(maxSault);
			this->hash += receivingExistCodes(maxLenghtStr);

			return this->hash;
		}
		return "";
	}
}
#endif
