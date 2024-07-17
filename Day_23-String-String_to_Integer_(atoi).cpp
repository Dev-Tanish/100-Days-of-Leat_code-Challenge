class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int result = 0;
        int i = 0;

        // Handle whitespace
        while (i < str.size() && str[i] == ' ') {
            i++;
        }

        // Handle sign
        if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
            sign = (str[i++] == '-') ? -1 : 1;
        }

        // Handle digits
        while (i < str.size() && isdigit(str[i])) {
            int digit = str[i++] - '0';

            // Handle overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
        }

        return sign * result;
    }
};