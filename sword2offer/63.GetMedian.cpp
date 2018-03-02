//数据流中的中位数
//https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1
class Solution {
public:
    set<int> smallTop;//存大数
    set<int,greater<int>> bigTop;//存小数
    void Insert(int num)
    {
        if(smallTop.size() <= bigTop.size()){
            bigTop.insert(num);
            smallTop.insert(*bigTop.begin());
            bigTop.erase(bigTop.begin());
        }else{
            smallTop.insert(num);
            bigTop.insert(*smallTop.begin());
            smallTop.erase(smallTop.begin());
        }
    }

    double GetMedian()
    { 
        if(smallTop.size() == 0) return 0;
        if(smallTop.size() > bigTop.size()){
            return *smallTop.begin();
        }else{
            return (*smallTop.begin() + *bigTop.begin())/2.0;
        }
    }

};