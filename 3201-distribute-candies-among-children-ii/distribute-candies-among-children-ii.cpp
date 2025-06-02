class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long count = 0;
        for (int a = 0; a <= min(n, limit); ++a) {
            int remaining = n - a;
            int minB = max(0, remaining - limit);
            int maxB = min(remaining, limit);
            if (minB <= maxB) {
                count += (maxB - minB + 1);
            }
        }
        return count;
    }
};
