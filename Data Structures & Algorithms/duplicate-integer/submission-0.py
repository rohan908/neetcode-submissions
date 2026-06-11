class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        listOfUniques = []
        d = False
        for i in nums:
            for k in listOfUniques:
                if i == k:
                    d = True
            if not d:
                listOfUniques.append(i)
        return d