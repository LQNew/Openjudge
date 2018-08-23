class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int flag = 1; // unsigned 此处很重要，同时还是主要利用了二进制中的与操作
        while(flag){
            if(flag&n) count++;
            flag = flag<<1;
        }
        return count;
    }
};
