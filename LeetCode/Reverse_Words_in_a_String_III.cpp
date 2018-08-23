class Solution {
public:
    string reverseWords(string s) {
        int length = s.size();
        if(length == 0) return s;
        int i,j;
        i = 0; j = 0;
        while(i<length){
            if(s[i] == ' '){ // 对于首部出现多余的空格，直接滑过
                i++;
                j++;
            }
            else if(s[j] == ' ' || s[j] == '\0'){ // 尾部出现空格或到结尾，翻转 头至尾这一部分的单词
                int tmp1 = j;
                tmp1--;
                while(i<tmp1){ // 折半交换，时间开销会小一些！
                    char tmp = s[i];
                    s[i] = s[tmp1];
                    s[tmp1] = tmp;
                    i ++;
                    tmp1--;
                }
                i = ++j;
            }
            else j++;
        }
        return s;
    }
};
