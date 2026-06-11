class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # have two pointers. Left is the number of instances != val AND is the index of the last unique value != val
        # right pointer searches the array for new values != val
        l = 0
        for r in nums:
            if r != val:
                nums[l] = r
                l += 1
        print(l)
        return l