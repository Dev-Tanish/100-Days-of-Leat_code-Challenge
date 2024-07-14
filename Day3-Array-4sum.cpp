class Solution(object):
    def fourSum(self, nums, target):
        if not nums or len(nums) < 4:
            return []
        s, m = set(), len(nums)
        nums.sort()
        for i in range(m-3):
            
            for j in range(i+1,m-2):
                l, r = j+1, m-1
                
                while l < r:
                    if (nums[i]+nums[j]+nums[l]+nums[r]) == target:
                        s.add((nums[i], nums[j], nums[l], nums[r]))
                        l+=1
                        r-=1
                    elif (nums[i]+nums[j]+nums[l]+nums[r]) < target:
                        l+=1
                    elif (nums[i]+nums[j]+nums[l]+nums[r]) > target:
                        r-=1
               
        return list(s)
        # """
        # :type nums: List[int]
        # :type target: int
        # :rtype: List[List[int]]
        # """
        