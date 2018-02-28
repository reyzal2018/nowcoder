//用两个栈实现队列
//https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6
class Solution
{
public:
    int error_;
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        error_ = 0;
        if(stack2.empty()){
            error_ = 1;
            return 0;
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};