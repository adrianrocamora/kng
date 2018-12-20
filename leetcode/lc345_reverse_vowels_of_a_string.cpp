class Solution {
    bool isVowel(char a) {
        if (a == 'A' || a == 'a' ||
            a == 'E' || a == 'e' ||
            a == 'I' || a == 'i' ||
            a == 'O' || a == 'o' ||
            a == 'U' || a == 'u') {
            return true;
        }
        else {
            return false;
        }
    }
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (!isVowel(s[l])) {
                l++;
            } else if (!isVowel(s[r])) {
                r--;
        } else {
            swap(s[l], s[r]);
            l++; r--;
            }
        }
        return s;
    }
};
