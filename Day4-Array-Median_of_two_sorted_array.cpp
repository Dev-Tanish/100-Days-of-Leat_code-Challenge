class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        
        if (total % 2 == 1) {
            return findKth(nums1, 0, m, nums2, 0, n, total / 2 + 1);
        } else {
            return (findKth(nums1, 0, m, nums2, 0, n, total / 2) + findKth(nums1, 0, m, nums2, 0, n, total / 2 + 1)) / 2.0;
        }
    }
    double findKth(vector<int>& nums1, int start1, int m, vector<int>& nums2, int start2, int n, int k) {
        if (m > n) {
            return findKth(nums2, start2, n, nums1, start1, m, k);
        }
        if (m == 0) {
            return nums2[start2 + k - 1];
        }
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        
        int part1 = min(k / 2, m);
        int part2 = k - part1;
        
        if (nums1[start1 + part1 - 1] < nums2[start2 + part2 - 1]) {
            return findKth(nums1, start1 + part1, m - part1, nums2, start2, n, k - part1);
        } else {
            return findKth(nums1, start1, m, nums2, start2 + part2, n - part2, k - part2);
        }
    }
};