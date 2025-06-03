class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();

        int maxArea = 0;

        for (int top = 0; top < rows; ++top) {
            vector<int> colCount(cols, 1);
            for (int bottom = top; bottom < rows; ++bottom) {
                for (int c = 0; c < cols; ++c) {
                    if (matrix[bottom][c] == '0')
                        colCount[c] = 0;  
                }

                 int width = 0;
                for (int c = 0; c < cols; ++c) {
                    if (colCount[c] == 1) {
                        width++;
                        int height = bottom - top + 1;
                        maxArea = max(maxArea, width * height);
                    } else {
                        width = 0;
                    }
                }
            }
        }
        return maxArea;
    }
};
