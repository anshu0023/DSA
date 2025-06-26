class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int count = 0;
        int size = (n + 31) / 32;  // number of 32-bit integers needed
        vector<int> bitset(size, 0);
        
        auto check = [&](int x) {
            return (bitset[x >> 5] & (1 << (x & 31))) != 0;
        };
        
        auto set_bit = [&](int x) {
            bitset[x >> 5] |= (1 << (x & 31));
        };
        
        set_bit(0); // mark 0 as not prime
        set_bit(1); // mark 1 as not prime
        
        for (int i = 2; i * i < n; ++i) {
            if (!check(i)) {
                for (int j = i * i; j < n; j += i) {
                    set_bit(j);
                }
            }
        }
        
        for (int i = 2; i < n; ++i) {
            if (!check(i)) count++;
        }
        
        return count;
    }
};
