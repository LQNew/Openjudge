//momentaһ��ԭ�⣬�������������ף�����������ʵû����������ôˮ����������߼��Ǻ���̵ģ�
//�����Լ������߶�ͼȥ˼��һ�£�
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int res = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) res += (prices[i] - prices[i-1]);
        }
        return res;
    }
};