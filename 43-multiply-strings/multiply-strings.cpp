class Solution {
public:
    // first problem on github
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int x = num1.size(), y = num2.size();
        vector<int> res(x + y, 0);

        for (int i = x - 1; i >= 0; --i) {
            for (int j = y - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans;
        for (int d : res) {
            if (ans.empty() && d == 0) continue;
            ans += d + '0';
        }
        return ans.empty() ? "0" : ans;
    }
};
