/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = ((unsigned int)low + (unsigned int)high) >> 1;
            int guess_result = guess(mid);
            if (guess_result == 0) return mid;
            if (guess_result == -1) high = mid - 1;
            if (guess_result == 1) low = mid + 1;
        }
        return low;

    }
};