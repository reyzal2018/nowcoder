//机器人的运动范围
//https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool* visited = new bool[rows*cols];
        memset(visited,false,sizeof(bool)*rows*cols);
        int count = 0;
        dfs(threshold,rows,cols,0,0,visited,count);
        delete visited;
        return count;
    }
    
    void dfs(int threshold,int rows,int cols,int i,int j,bool* visited,int& count){
        if(i < 0 || i >= rows || j < 0 || j >= cols || visited[i*cols+j]){
            return;
        }
        static int dir[][2] = {
            {0,-1},
            {0,1},
            {-1,0},
            {1,0}
        };
        if(getSum(i) + getSum(j) <= threshold){
            count++;
            visited[i*cols+j] = true;
            for(int k = 0;k<4;k++){
                dfs(threshold,rows,cols,i+dir[k][0],j+dir[k][1],visited,count);
            }
        }
    }
    
    int getSum(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};