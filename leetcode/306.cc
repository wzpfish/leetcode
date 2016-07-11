/*
 * Easy problem, just check or possible candidates.
 * Special notes to the value beigin with zero! I wrong two times without considering zero..
 */

class Solution {
public:
    string BigAdd(string s1, string s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string result;
        int i = 0, carry = 0;
        while (i < s1.size() && i < s2.size()) {
            int sum = s1[i] - '0' + s2[i] - '0' + carry;
            result += (sum % 10 + '0');
            carry = sum / 10;
            ++i;
        }
        while (i < s1.size()) {
            int sum = s1[i] - '0' + carry;
            result += (sum % 10 + '0');
            carry = sum / 10;
            ++i;
        }
        while (i < s2.size()) {
            int sum = s2[i] - '0' + carry;
            result += (sum % 10 + '0');
            carry = sum / 10;
            ++i;
        }
        if (carry) {
            result += (carry + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool check(const string& s1, const string& s2,
               const string& num, int idx) {
        if (idx == num.size()) return true;
        string sum = BigAdd(s1, s2);
        //cout << s1 << " " << s2 << " " << sum << endl;
        if (sum == num.substr(idx, sum.size())) {
            //cout << idx << " " <<sum.size() << endl;
            return check(s2, sum, num, idx + sum.size());
        }
        else return false;
    }
    
    bool isAdditiveNumber(string num) {
        for (int len1 = 1; len1 < num.size(); ++len1) {
            for (int len2 = 1; len1 + len2 + max(len1, len2) <= num.size(); ++len2) {
                string s1 = num.substr(0, len1);
                string s2 = num.substr(len1, len2);
                if ((len1 > 1 && s1[0] == '0') || 
                    (len2 > 1 && s2[0] == '0')) {
                    continue;
                }
                if (check(s1, s2, num, len1 + len2)) {
                    return true;
                }
            }
        }
        return false;
    }
};
