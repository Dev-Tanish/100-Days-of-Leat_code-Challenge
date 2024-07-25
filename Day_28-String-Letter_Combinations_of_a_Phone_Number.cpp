class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(result, phone, digits, 0, "");
        return result;
    }

    void backtrack(vector<string>& result, vector<string>& phone, string digits, int index, string current)
    {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        for (char c : phone[digits[index] - '0']) {
            backtrack(result, phone, digits, index + 1, current + c);
        }
    }
};