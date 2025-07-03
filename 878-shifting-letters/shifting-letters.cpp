class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        string ans = "";
        int X = 0;

        for (int shift : shifts)
            X = (X + shift) % 26;

        for (int i = 0; i < S.size(); ++i) {
            int index = S[i] - 'a';
            ans += (char)((index + X) % 26 + 'a');
            X = (X - shifts[i]) % 26;
            if (X < 0) X += 26; 
        }

        return ans;
    }
};
