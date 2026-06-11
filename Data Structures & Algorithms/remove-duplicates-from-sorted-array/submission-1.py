class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #currUniqueIndex = 0
        #numUniques = 1
        #for i in range(1, len(nums)):
        #    if nums[i] != nums[currUniqueIndex]:
        ##        nums[currUniqueIndex + 1] = nums[i]
        #        currUniqueIndex += 1
        #        numUniques += 1
        #return numUniques

        l = 1
        for r in range(1, len(nums)):
            if nums[r] != nums[r-1]:
                nums[l] = nums[r]
                l += 1
        return l
