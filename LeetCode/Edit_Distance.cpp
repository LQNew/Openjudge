//edit distance 是典型的动归问题，对它的理解可以由现场画表格推导理解！或者是它的递推式非常经典，很容易推出~
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n==0 && m==0) return 0;
        int edit[n+1][m+1];
        edit[0][0] = 0;
        for(int i=1;i<=n;i++) edit[i][0] = i;
        for(int j=1;j<=m;j++) edit[0][j] = j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int f = 1;
                if(word1[i-1]==word2[j-1]) f = 0;
                int min1 = min(edit[i-1][j]+1,edit[i][j-1]+1);
                min1 = min(edit[i-1][j-1]+f, min1);
                edit[i][j] = min1;
            }
        }
        return edit[n][m];
    }
};
