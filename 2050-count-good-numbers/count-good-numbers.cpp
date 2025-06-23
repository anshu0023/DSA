class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2; 
        long long oddPositions = n / 2;       

        long long waysEven = modPow(5, evenPositions);
        long long waysOdd = modPow(4, oddPositions);

        return (waysEven * waysOdd) % MOD;
    }
};
