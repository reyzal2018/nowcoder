//evaluate-reverse-polish-notation
//https://www.nowcoder.com/practice/22f9d7dd89374b6c8289e44237c70447
class Solution {
    public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(auto& token:tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                if(s.size() < 2) return 0;
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                if(token == "+")
                    s.push(val2+val1);
                else if(token == "-")
                    s.push(val2-val1);
                else if(token == "*")
                    s.push(val2*val1);
                else 
                    s.push(val2/val1);
            }else{
                int val = atoi(token.c_str());
                s.push(val);
            }
        }
        return s.empty()? 0 : s.top();
    }
};