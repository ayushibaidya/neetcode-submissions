class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        vector<int> results;

        while (left <= right && top <= bottom) {

            // left -> right
            for (int j = left; j <= right; j++)
                results.push_back(matrix[top][j]);
            top++;

            // top -> bottom
            for (int i = top; i <= bottom; i++)
                results.push_back(matrix[i][right]);
            right--;

            // right -> left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    results.push_back(matrix[bottom][j]);
                bottom--;
            }

            // bottom -> top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    results.push_back(matrix[i][left]);
                left++;
            }
        }

        return results;
    }
};