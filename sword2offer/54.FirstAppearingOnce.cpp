//字符流中第一个不重复的字符
//https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720
class Solution
{
public:
    queue<char> q;
    map<char,int> m;
  //Insert one char from stringstream
    void Insert(char ch)
    {
         if(++m[ch] == 1){
             q.push(ch);
         }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty() && m[q.front()] > 1)
            q.pop();
        return q.empty()?'#':q.front();
    }

};