//矩阵中的路径
//https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc
class Solution
{
public:
	bool dfs(int i,int j,int strindex)
	{
		if (visited[i][j])
		{
			return false;
		}
		static int dir[][2] =
		{
			{ 0, 1 },
			{ 1, 0 },
			{ 0, -1 },
			{ -1, 0 },
		};
		if (matrix_[i*cols_ + j] == str_[strindex])
		{
			if (++strindex == lenstr)
			{
				return true;
			}
		}
		else {
			return false;
		}
		visited[i][j] = true;
		for (int k = 0; k < 4; k++)
		{
			if (i + dir[k][0] < 0 || i + dir[k][0] >= rows_)
				continue;
			if (j + dir[k][1] < 0 || j + dir[k][1] >= cols_)
				continue;
			if (dfs(i + dir[k][0], j + dir[k][1], strindex)) {
				return true;
			}
		}
		visited[i][j] = false;
		return false;
	}
	char* str_;
	int lenstr;
	char* matrix_;
	int rows_;
	int cols_;
	vector<vector<bool>> visited;
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (str == NULL || str[0] == '\0') return true;
        if (cols == 0 || rows == 0) return false;
		this->str_ = str;
		this->matrix_ = matrix;
		this->rows_ = rows;
		this->cols_ = cols;
		lenstr = strlen(str);
		visited.resize(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
				if (dfs(i,j,0))
				{
					return true;
				}
            }
        return false;
    }
};