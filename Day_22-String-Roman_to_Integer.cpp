class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanNumeralValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && romanNumeralValues[s[i]] > romanNumeralValues[s[i - 1]]) {
                result += romanNumeralValues[s[i]] - 2 * romanNumeralValues[s[i - 1]];
            } else {
                result += romanNumeralValues[s[i]];
            }
        }

        return result;
    }
};