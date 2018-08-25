class Solution {
public:
    bool test_zero(char* pattern){
        if(*pattern == '\0') return true;
        if(*(pattern + 1) == '*') return test_zero(pattern + 2);
        if(*pattern == '*') return test_zero(pattern + 1);
        return false;

    }

    bool test(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0') return true; // 如果匹配串与正则表达式均搜索到末端，匹配
        if(*str != '\0' && *pattern == '\0') return false; // 如果匹配串未到末端，但是正则表达式搜索到末端，那么不匹配
        if(*(pattern + 1) == '*'){
            if((*pattern == *str) || (*pattern == '.' && *str != '\0')){ // 如果 p[j] 和 s[i] 相等，且p[j + 1] 为 '*'
                return test(str + 1, pattern + 2) || test(str + 1, pattern)\
                       || test(str, pattern + 2);
                // (i+1, j+2) 到下一状态； (i+1, j) 比对是否下一个字符s[i+1] 等于 p[j]； (i, j+2)忽略 p[j]和'*'
            }
            else return test(str, pattern + 2); // 忽略 p[j] 和 '*'
        }
        // p[j+1] != '*'时的情况分析
        if(*str == *pattern || (*pattern == '.' && *str != '\0')) return test(str + 1, pattern + 1);
        return false;
    }

    bool match(char* str, char* pattern){
        if(str != NULL && pattern == NULL) return false;
        if(str == NULL){
            if(pattern == NULL) return true;
            return test_zero(pattern); // 测试str 为空时的情况
        }
        return test(str, pattern);
    }
};
