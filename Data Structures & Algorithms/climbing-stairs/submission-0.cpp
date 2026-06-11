class Solution {
public:
// want to make a tree
// each recursive branch: two options -> 1 or 2 step climb
    int climbStairs(int n) {
        if (n <= 0) return 0;

        if (n == 1) return 1;

        if (n == 2) return 2;
        
        return climbStairs(n - 2) + climbStairs(n-1);
    }
};
