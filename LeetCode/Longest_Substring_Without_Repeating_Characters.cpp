/*
  用p2和p1两个指针一前一后走，p1记录当前查看的子串首个字符，p2在前面如果扫到和p1对应的字符不同的字符就继续向前走，直到发现与p1字符相同的字符，
  停下来计算当前扫描的字串长度，更新curMax长度。然后p1向前走，知道发现一个和p2相同的字符，再向前一步排除掉这个重复的字符，
  这样p1就成为了下一个不含重复字符的子符串起点，接着p2可以继续向前走，以此类推，直到扫描完整个字符串
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //双指针
        int i=0;
        int j=0;
        int flag[128];
        int maxlen=0;
        memset(flag,-1,sizeof(flag));///初始化为-1
        while(j<s.size()){
             //检测后扫的指针对应的位置的值是否-1即是否之前被访问过 or 后扫的指针如果被访问过，它的位置是否在当前头指针之前，如果是之前，
             //那么对于新的子串计算没有影响
            if(flag[s[j]]==-1||flag[s[j]]<i){
                flag[s[j]]=j;
                if(j==(s.size()-1)){
                    maxlen=max(maxlen,j-i+1);
                    return maxlen;
                }
                j++;
            }
            else{
                maxlen=max(maxlen,j-i);
                i=flag[s[j]]+1;
                flag[s[j]]=j;
                j++;
            }
        }
        return maxlen;
    }
};
