//gas-station
//https://www.nowcoder.com/practice/3b1abd8ba2e54452b6e18b31780b3635
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int s = n-1;
        int remain = gas[s]-cost[s];
        int e = 0;
        //从最后面走到最前面
        while( s > e){
            if(remain < 0){
                //当前油小于0，起点退一步
                s--;
                remain = remain + gas[s]-cost[s];
            }else{
                //大于0 走下一步
                remain = remain + gas[e]-cost[e];
                e++;
            }
        }
        return remain >= 0? s : -1;
    }
};