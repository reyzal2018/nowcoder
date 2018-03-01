//数组中的逆序对
//https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0) return 0;
        int result = 0;
        int * temp = new int[data.size()];
        MergeSort(&data[0],0,data.size()-1,temp,result);
        delete temp;
        return result;
    }
    
    void MergeSort(int* data,int l,int r,int* temp,int& result){
        if(l < r){
            int mid = l + (r-l)/2;
            MergeSort(data,l,mid,temp,result);
            MergeSort(data,mid+1,r,temp,result);
            MergeArray(data,l,mid,r,temp,result);
        }
    }
    void MergeArray(int* data,int l,int mid,int r,int* temp,int& result){
        int i = l;
        int j = mid+1;
        int k = 0;
        while(i <= mid && j <= r){
            if(data[i] < data[j]){
                temp[k++] = data[i++];
            }else{
                //左边有多少就加多少个逆序对
                result += mid - i + 1;
                temp[k++] = data[j++];
                result = result % 1000000007;
            }
        }
        while(i <= mid)
            temp[k++] = data[i++];
        while(j <= r)
            temp[k++] = data[j++];
        for(i = 0;i<k;i++){
            data[l+i] = temp[i];
        }
    }
};