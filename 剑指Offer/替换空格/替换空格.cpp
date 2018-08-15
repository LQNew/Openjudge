// 本道题主要是先计算出替换为空格后的字符串应变为的长度，然后开始从后往前替换，填补，这样不会影响到之前的值，感觉思路十分精巧！！
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(length <= 0 || str == NULL) return;
        int num_of_space = 0;
        int origin_length = 0;
        int i=0;
        while(str[i] != '\0'){
            origin_length++;
            if(str[i]==' ') num_of_space++;
            i++;
        }
        int final_length = origin_length + num_of_space * 2;
        if(final_length > length) return; //如果最后替换为空格后的长度大于str字符串的最大长度，那么无法替换，return
        while(origin_length>=0 && final_length > origin_length){
            if(str[origin_length]==' '){
                str[final_length--] = '0';
                str[final_length--] = '2';
                str[final_length--] = '%';
                origin_length --;
            }
            else{
                str[final_length--] = str[origin_length];
                origin_length --;
            }
        }
	}
};
