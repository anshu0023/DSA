class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n > 10) n = 10; // only 10 digits available (0–9)

        int ans = 10, prod = 9;
        for (int i = 2; i <= n; ++i) {
            prod *= (11 - i); // (9 × 9 × 8 × 7 × ...)
            ans += prod;
        }
        return ans;
    }
};
