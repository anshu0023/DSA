class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num), a = s, b = s;

     for (char c : s) {
            if (c != '9') {
                for (char &ch : a)
                    if (ch == c) ch = '9';
                break;
            }
        }

       if (s[0] != '1') {
            char target = s[0];
            for (char &ch : b)
                if (ch == target) ch = '1';
        } else {
            for (int i = 1; i < b.size(); ++i) {
                if (b[i] != '0' && b[i] != '1') {
                    char target = b[i];
                    for (char &ch : b)
                        if (ch == target) ch = '0';
                    break;
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};
