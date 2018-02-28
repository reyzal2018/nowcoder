//顺时针打印矩阵
//https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a
class Solution
{
public:
    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        vector<int> result;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 0 || cols == 0) return result;
        int loop_times = (min(rows, cols) + 1) / 2;
        for (int i = 0; i < loop_times; i++)
        {
            //左到右
            for (int j = i; j < cols - i; j++)
            {
                result.push_back(matrix[i][j]);
            }
            //上到下
            for (int j = i + 1; j < rows - i; j++)
            {
                result.push_back(matrix[j][cols - i - 1]);
            }
            //右到左(考虑单行的情况)
            for (int j = cols - i - 2; i + 1 < rows - i && j >= i; j--)
            {
                result.push_back(matrix[rows - i - 1][j]);
            }
            //下到上(考虑单列的情况)
            for (int j = rows - i - 2; cols - i - 2 >=i && j > i; j--)
            {
                result.push_back(matrix[j][i]);
            }
        }
        return result;
    }
};