// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        recursiveMerger(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void recursiveMerger(vector<Pair>& pairs, int s, int e) {
        if (e - s + 1 <= 1) {
            return;
        }

        int m = (e + s) / 2;

        // left branch sort
        recursiveMerger(pairs, s, m);

        // right branch sort
        recursiveMerger(pairs, m+1, e);

        mergeVectors(pairs, s, m, e);
    }

    void mergeVectors(vector<Pair>& pairs, int s, int m, int e) {
        vector<Pair> L(pairs.begin() + s, pairs.begin() + m + 1);
        vector<Pair> R(pairs.begin() + m + 1, pairs.begin() + e + 1);

        int li = 0;
        int ri = 0;
        int k = s; //for full arr

        while (li < L.size() && ri < R.size()) {
            if (L[li].key <= R[ri].key) {
                pairs[k] = L[li];
                li++;
            }
            else {
                pairs[k] = R[ri];
                ri++;
            }
            k++;
        }

        while (li < L.size()) {
            pairs[k] = L[li];
            li++;
            k++;
        }

        while (ri < R.size()) {
            pairs[k] = R[ri];
            ri++;
            k++;
        }
    }
};
