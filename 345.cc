/*
 * 注意大小写..
 */
class Solution {
private:
    bool is_vowel(char c) {
        char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < 10; ++i) {
            if (vowels[i] == c) return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (is_vowel(s[i]) && is_vowel(s[j])) {
                swap(s[i], s[j]);
                ++i, --j;
            } 
            else {
                if (!is_vowel(s[i])) ++i;
                if (!is_vowel(s[j])) --j;
            }
        }
        return s;
    }
};
