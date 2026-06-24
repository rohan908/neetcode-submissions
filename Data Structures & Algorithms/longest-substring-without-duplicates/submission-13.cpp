class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == ("")) return 0;
        int longest = 1;
        //asdffds
        //asdfds
        //key is the character val, val is index
        std::unordered_map<char, int> occ;
        int lIdx = 0;
        int rIdx = 0;
        for (; rIdx < s.size(); ++rIdx ) {
            char thisChar = s[rIdx];
            if (occ.contains(thisChar)) {
                if (rIdx - lIdx > longest) {
                    longest = rIdx - lIdx;
                }
                for (; lIdx < occ[thisChar] + 1; ++lIdx) {
                    occ.erase(s[lIdx]);
                }
                occ[thisChar] = rIdx;
            }
            else {
                occ[thisChar] = rIdx;
            }
        }
        if (rIdx - lIdx > longest) return rIdx - lIdx;
        std::cout << "returned at longest \n" << std::endl;
        return longest;
    }
};
