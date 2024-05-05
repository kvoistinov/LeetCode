// 14.04.2024
class Solution {
public:
    int maximalRectangle(const std::vector<std::vector<char>>& matrix) 
    {
        int N = matrix.size();
        int M = matrix[0].size();
        std::vector<
            std::vector<
                std::pair<int, int>>> mat_pairs(N, std::vector<std::pair<int, int>>(M));
        int ones_cnt = 0;

        for (int j = M - 1; j >= 0; --j)
        {
            int curr_cell = matrix[0][j];

            if (curr_cell == '1') {
                ones_cnt++;
            }
            else {
                ones_cnt = 0;
            }
            mat_pairs[0][j] = { (curr_cell - '0'), ones_cnt };
        }

        for (int i = 1; i < N; ++i)
        {
            ones_cnt = 0;

            for (int j = M - 1; j >= 0; --j)
            {
                int curr_cell = matrix[i][j];

                if (curr_cell == '1') {
                    ones_cnt++;
                }
                else {
                    ones_cnt = 0;
                }
                mat_pairs[i][j] = { mat_pairs[i - 1][j].first + (curr_cell - '0'), ones_cnt };
            }
        }
        int max_rectangle = 0;

        for (int i = 0; i < N; ++i)
        {
            int curr_rectangle = 0;

            for (int j = 0; j < M; ++j)
            {
                int ones_in_row = mat_pairs[i][j].second;

                if (ones_in_row > 0) {
                    int ones_in_col   = mat_pairs[i][j].first;
                    int curr_row_ones = ones_in_row;
                    
                    for (int k = 0; k < ones_in_col; ++k)
                    {
                        curr_row_ones  = std::min(curr_row_ones, mat_pairs[i - k][j].second);
                        curr_rectangle = std::max(curr_rectangle, (k + 1) * curr_row_ones);

                        if (max_rectangle < curr_rectangle) {
                            max_rectangle = curr_rectangle;
                        }
                    }
                }
            }
        }
        return max_rectangle;
    }
};
