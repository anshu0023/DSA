class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> canOpen(n, false);
        vector<bool> opened(n, false);
        vector<bool> hasKey(n, false);

        for (int box : initialBoxes)
            hasBox[box] = true;

        int totalCandies = 0;
        bool changed = true;

        while (changed) {
            changed = false;
            for (int i = 0; i < n; ++i) {
                if (hasBox[i] && !opened[i] && (status[i] == 1 || hasKey[i])) {
                    opened[i] = true;
                    totalCandies += candies[i];

                    for (int k : keys[i]) {
                        if (!hasKey[k]) {
                            hasKey[k] = true;
                            changed = true;
                        }
                    }

                    for (int b : containedBoxes[i]) {
                        if (!hasBox[b]) {
                            hasBox[b] = true;
                            changed = true;
                        }
                    }
                    changed = true;
                }
            }
        }

        return totalCandies;
    }
};
