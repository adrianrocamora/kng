#include <iostream>
#include <stdio.h>

using namespace std;

int main() 
{
	int numEntries = 0;
	scanf("%d\n", &numEntries);
	cout << numEntries << endl;

	char word[1000];
	char wordTemp[1000];
	char mode[4][100] = {"none", "anagram", "palindrome", "both"};
	string modeStr[2] = {"is a palindrome", "isn't a palindrome"};
	for (int i = 0; i < numEntries; i++) {
		scanf("%s\n", word);
		string tempWord(word);
		int isPalindrome = 0;

		//isAnagram
		int wordLen = tempWord.size();
		int halfLen = (wordLen % 2 == 0) ? wordLen/2 : (wordLen+1)/2;

		for (int j = 0; j < halfLen;j++) {
			if (tempWord[j] != tempWord[wordLen -1 - j]) {
				isPalindrome = 1;
			}
		}

		cout << "Case " << i << ": " << modeStr[isPalindrome] << endl;
	}

	return 0;
}
