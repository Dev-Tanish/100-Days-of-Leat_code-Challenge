class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = nums.size() - 1;
        int l = 0;
        while (l < r) {
            while (nums[l] == val && l < r) swap(nums[l], nums[r--]);
            if (nums[l] != val) l++;
            else break;
        }
        while (l < nums.size() && nums[l] != val) l++;
        return l;
    }
};