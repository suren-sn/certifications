#python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #for i in range(len(nums)-1):
        #    for j in range(i+1,len(nums)):
        #        if (nums[i] + nums[j]) == target: return [i,j]

        hashmap = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in hashmap:
                return(hashmap[diff],i)
            hashmap[nums[i]] = i
