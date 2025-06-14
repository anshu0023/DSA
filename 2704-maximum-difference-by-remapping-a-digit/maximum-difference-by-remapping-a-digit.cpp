class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        
       string max_s = s;
        char replace_max = ' ';
        for (char c : s) {
            if (c != '9') {
                replace_max = c;
                break;
            }
        }
        if (replace_max != ' ') {
            for (char& c : max_s) {
                if (c == replace_max) c = '9';
            }
        }
        
        string min_s = s;
        char replace_min = ' ';
        for (char c : s) {
            if (c != '0') {
                replace_min = c;
                break;
            }
        }
        if (replace_min != ' ') {
            for (char& c : min_s) {
                if (c == replace_min) c = '0';
            }
        }

        int maximum = stoi(max_s);
        int minimum = stoi(min_s);
        return maximum - minimum;
    }
};
