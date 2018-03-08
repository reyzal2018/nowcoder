//滑动窗口的最大值
//https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> result;
		if (num.size() < size || size == 0) return result;
		list<int> l;
		int maxval = num[0];
		for (int i = 0; i<size; i++) {
			l.push_back(i);
			while (l.size() > 0 && num[l.front()] < num[i]) {
				l.pop_front();
			}
			maxval = max(num[i], maxval);
		}
		result.push_back(maxval);
		for (int i = size; i < num.size(); i++) {
			while (l.size() > 0 && num[l.back()] < num[i]) {
				l.pop_back();
			}
			while (l.size() > 0 && (i - l.front()) >= size)
			{
				l.pop_front();
			}
			l.push_back(i);
			result.push_back(num[l.front()]);
		}
		return result;
	}
};