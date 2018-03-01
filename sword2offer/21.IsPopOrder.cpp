//栈的压入、弹出序列
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int pushIndex = 0;
        int popIndex = 0;
        while(pushIndex < pushV.size()){
            if(s.empty() || s.top() != popV[popIndex]){
                s.push(pushV[pushIndex]);
            }
            if(s.top() == popV[popIndex]){
                s.pop();
                popIndex++;
            }
            pushIndex++;
        }
        while(!s.empty() && s.top() == popV[popIndex]){
            popIndex++;
            s.pop();
        }
        return s.empty();
    }
};