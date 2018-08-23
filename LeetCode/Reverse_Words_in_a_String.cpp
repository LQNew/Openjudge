// 难度较大，两次翻转字符串且要求删除多余的空格项，主要是要灵活应用string 库函数中的 erase()函数
// 还是逻辑上的细节思索问题！
class Solution {
public:
    void reverseWords(string &s) {
        int length = s.size();
        if(length==0) return;
        int a,b;
        a = 0; b = 0;
        while(s[b]==' ') b++; // 去除首部的空格
        s.erase(a,b); // 删除从a开始的 b个字符
        length -= b;
        if(length==0) return;
        int i = 0;
        int j = length - 1;
        // 第一次翻转，翻转整个字符串
        while(i<j){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        a = 0; b = 0;
        while(s[b]==' ') b++; // 去除尾部的空格
        s.erase(a,b);
        length -= b;
        if(length==0) return;
        // 第二次翻转，翻转每个单词
        i = 0; j = 0;
        while( i < length ){
            while(s[i] == ' ' && i<length){ // 删除多余空格，因为首部、尾部的空格均已去除，所以此处只有单词间的多余的空格
                s.erase(i,1);
                length -= 1;
            }
            if( i>=length ) break;
            if(s[j] == ' '||s[j] == '\0'){
                int tmp1 = j;
                tmp1 --;
                while(i<tmp1){
                    char tmp = s[i];
                    s[i] = s[tmp1];
                    s[tmp1] = tmp;
                    i++;
                    tmp1--;
                }
                i = ++j; // 此处对于空格项有一个跳一个空格的操作，所以在前面删除多余的空格处，可以直接处理

            }
            else j++;
        }
    }
};
