//包含min函数的栈
//https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49
class Solution {
public:
    void push(int value) {
        stack_data.push(value);
        if(stack_min.empty()){
            stack_min.push(value);
        }else{
            stack_min.push(min(value,stack_min.top()));
        }
    }
    void pop() {
        stack_data.pop()
        stack_min.pop()
    }
    int top() {
        return stack_data.top();
    }
    int min() {
        return stack_min.top();
    }
    
    stack<int> stack_data;
    stack<int> stack_min
};