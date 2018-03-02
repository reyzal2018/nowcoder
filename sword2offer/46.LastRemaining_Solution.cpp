//孩子们的游戏(圆圈中最后剩下的数)
//https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0 || m == 0) return -1;
        list<int> l;
        for(int i = 0;i<n;i++){
            l.push_back(i);
        }
        auto it = l.begin();
        while(l.size() > 1){
            for(int i = 0;i<m-1;i++){
                it++;
                if(it == l.end()){
                    it = l.begin();
                }
            }
            it = l.erase(it);
            if(it == l.end())
                it = l.begin();
        }
        return l.front();
    }
};