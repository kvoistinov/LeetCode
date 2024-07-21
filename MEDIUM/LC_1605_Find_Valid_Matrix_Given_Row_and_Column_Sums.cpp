class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(
        const std::vector<int>& rowSum, 
        const std::vector<int>& colSum
    ) 
    {
        std::size_t rows = rowSum.size();
        std::size_t cols = colSum.size();

        std::vector<int> curRowSum(rows, 0);
        std::vector<int> curColSum(cols, 0);

        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                matrix[i][j] = std::min(rowSum[i] - curRowSum[i], colSum[j] - curColSum[j]);
                curRowSum[i] += matrix[i][j];
                curColSum[j] += matrix[i][j];
            }
        }
        return matrix;        
    }
};


/*
6 0 0
6 9 0
0 6 18

min(6 - 0, 12 - 0) -> 6
min(6 - 6, 15 - 6) -> 0
min(6 - 6, 18 - 6) -> 0

min(15 - 0, 12 - 6) -> 6
min(15 - 6, 15 - 0) -> 9
min(15 - 15, 18 - 0) -> 0

min(24 - 0, 12 - 12) -> 0
min(24 - 0, 15 - 9) -> 6
min(24 - 6, 18 - 0) -> 18

6
15
24

12 15 18

*/
