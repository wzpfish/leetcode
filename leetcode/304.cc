/*
 * It's easy to come up with this 2-D solution of sum. :) 
 */

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        sum_ = vector<vector<int>> (n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i >= 1 && j >= 1) {
                    sum_[i][j] = sum_[i - 1][j] + sum_[i][j - 1] - sum_[i - 1][j - 1] + matrix[i][j];
                }
                else if (i >= 1) {
                    sum_[i][j] = sum_[i - 1][j] + matrix[i][j];
                }
                else if (j >= 1) {
                    sum_[i][j] = sum_[i][j - 1] + matrix[i][j];
                }
                else {
                    sum_[i][j] = matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        if (row1 >= 1 && col1 >= 1) {
            result = sum_[row2][col2] - sum_[row2][col1 - 1] - sum_[row1 - 1][col2] + sum_[row1 - 1][col1 - 1];
        }
        else if (row1 >= 1) {
            result = sum_[row2][col2] - sum_[row1 - 1][col2];
        }
        else if (col1 >= 1) {
            result = sum_[row2][col2] - sum_[row2][col1 - 1];
        }
        else result = sum_[row2][col2];
        return result;
    }

private:
    vector<vector<int>> sum_;
};
