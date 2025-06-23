class Solution {
public:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string res = "";
        while (num > 0) {
            res += char('0' + (num % k));
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void generatePalindromes(int len, vector<long long>& palins, bool oddLenOnly = false) {
        int start = (len == 1 ? 1 : pow(10, (len - 1) / 2));
        int end = pow(10, (len + 1) / 2);
        for (int i = start; i < end; ++i) {
            string firstHalf = to_string(i);
            string secondHalf = firstHalf;
            reverse(secondHalf.begin(), secondHalf.end());
            if (len % 2 == 1) secondHalf.erase(0, 1); // Remove middle digit duplicate
            string full = firstHalf + secondHalf;
            palins.push_back(stoll(full));
        }
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        int len = 1;

        while (count < n) {
            vector<long long> palindromes;
            generatePalindromes(len, palindromes);
            for (auto num : palindromes) {
                string baseK = toBaseK(num, k);
                if (isPalindrome(baseK)) {
                    sum += num;
                    count++;
                    if (count == n) break;
                }
            }
            len++;
        }
        return sum;
    }
};
