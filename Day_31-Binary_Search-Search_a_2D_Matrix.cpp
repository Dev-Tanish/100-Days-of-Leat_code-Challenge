class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows * cols - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int num = matrix[mid / cols][mid % cols];

            if (num == target) return true;
            else if (num < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};