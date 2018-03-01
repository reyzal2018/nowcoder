//数字在排序数组中出现的次数
//https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int index1 = GetFirstOfK(data,k);
        int index2 = GetLastOfK(data,k);
        if(index1 == -1) return 0;
        return index2 - index1+1;
    }
    int GetFirstOfK(vector<int> data,int k){
        int l = 0;
        int r = data.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(data[mid] >= k)
                r = mid-1;
            if(data[mid] < k) 
                l = mid+1;
            if(data[mid] == k && (mid == 0 || data[mid-1] != k))
                return mid;
        }
        return -1;
    }
    int GetLastOfK(vector<int> data,int k){
        int l = 0;
        int r = data.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(data[mid] > k)
                r = mid-1;
            if(data[mid] <= k) 
                l = mid+1;
            if(data[mid] == k && (mid == data.size()-1 || data[mid+1] != k))
                return mid;
        }
        return -1;
    }
};