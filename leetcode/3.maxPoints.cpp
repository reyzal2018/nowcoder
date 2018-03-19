//max-points-on-a-line
//https://www.nowcoder.com/practice/bfc691e0100441cdb8ec153f32540be2
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int result = points.size() < 2 ? points.size() : 2;
        for (int i = 0; i < points.size(); i++)
        {
            int vtl = 0;
            map<double, int> mapSlope;
            int same = 0;
            for (int j = 0; j < points.size(); j++)
            {
                if (points[i].x == points[j].x &&
                    points[i].y == points[j].y) {
                    //相同的点
                    same++;
                }else if (points[i].x == points[j].x)
                {
                    //垂直的点特殊处理
                    vtl++;
                }
                else {
                    mapSlope[1.0*(points[j].y - points[i].y) / (points[j].x - points[i].x)]++;
                }
            }
            result = max(vtl + same, result);
            for (auto& it : mapSlope) {
                result = max(result, it.second + same);
            }
        }
        return result;
    }
};