class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        --k;

        while (k > 0) {
            long long count = 0;
            long long first = curr, last = curr + 1;

            while (first <= n) {
                count += min((long long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }

            if (count <= k) {
                curr++;
                k -= count;
            } else {
                curr *= 10;
                --k;
            }
        }

        return curr;
    }
};
