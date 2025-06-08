class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<bool> visited(n, false);
        vector<vector<string>> res;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            set<string> emails(accounts[i].begin() + 1, accounts[i].end());
            visited[i] = true;

            bool merged = true;
            while (merged) {
                merged = false;
                for (int j = 0; j < n; ++j) {
                    if (visited[j]) continue;

                    for (int k = 1; k < accounts[j].size(); ++k) {
                        if (emails.count(accounts[j][k])) {
                            emails.insert(accounts[j].begin() + 1, accounts[j].end());
                            visited[j] = true;
                            merged = true;
                            break;
                        }
                    }
                }
            }

            vector<string> acc(emails.begin(), emails.end());
            sort(acc.begin(), acc.end());
            acc.insert(acc.begin(), accounts[i][0]);
            res.push_back(acc);
        }

        return res;
    }
};
