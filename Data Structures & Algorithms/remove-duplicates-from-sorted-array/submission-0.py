class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        currUniqueIndex = 0
        numUniques = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[currUniqueIndex]:
                nums[currUniqueIndex + 1] = nums[i]
                currUniqueIndex += 1
                numUniques += 1
        return numUniques
