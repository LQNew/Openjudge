// 用dp算法处理，题目难在思路上！
// 本道题其实还是没有特别理解透彻，仍需要加强训练以及理解！
class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();
        s.insert(0, "#");
        p.insert(0, "#");
        bool judge[len1 + 1][len2 + 1];
        judge[0][0] = true;
        for (int i = 1; i <= len1; i++) judge[i][0] = false;
        for (int j = 1; j <= len2; j++) judge[0][j] = (j > 1) && (p[j] == '*') && judge[0][j - 2];
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(p[j] != '*') judge[i][j] = judge[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                else judge[i][j] = judge[i][j - 2] || (s[i] == p[j - 1] || p[j - 1] == '.') && judge[i - 1][j];
            }
        }
        return judge[len1][len2];
    }
};
