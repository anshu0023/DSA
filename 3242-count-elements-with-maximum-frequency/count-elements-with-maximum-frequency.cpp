class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        for (int x : nums) {
            freq[x]++;
            maxFreq = max(maxFreq, freq[x]);
        }

        int total = 0;
        for (auto& [val, count] : freq) {
            if (count == maxFreq)
                total += count;
        }

        return total;
    }
};
