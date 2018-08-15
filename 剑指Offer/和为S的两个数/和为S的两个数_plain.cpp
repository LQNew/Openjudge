class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int multiply1=0x7fffffff;
        vector<int> tmp;
        for(int i=0;i<array.size();i++){
            for(int j=i+1;j<array.size();j++){
                if(array[i]+array[j]==sum){
                    if(array[i]*array[j]<multiply1){
                        multiply1=array[i]*array[j];
                        tmp.clear();//vector 向量的弹栈操作
                        tmp.push_back(array[i]);
                        tmp.push_back(array[j]);
                    }
                }
            }
        }
        return tmp;
    }
};
