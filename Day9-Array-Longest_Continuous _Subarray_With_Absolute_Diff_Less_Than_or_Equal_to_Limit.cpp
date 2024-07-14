const static auto fast = []
{ 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> dec, inc;
        int n = nums.size();
        int left = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!dec.empty() && nums[i] > dec.back()) dec.pop_back();
            while(!inc.empty() && nums[i] < inc.back()) inc.pop_back();
            dec.push_back(nums[i]);
            inc.push_back(nums[i]);
            if(dec.front() - inc.front() > limit){
                if(nums[left] == dec.front()) dec.pop_front();
                if(nums[left] == inc.front()) inc.pop_front();
                left++;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};