class Solution {
public:
    int myAtoi(string str) {
        queue<int> a;
        stack<int> s;
        bool flag=false;
        bool neg=false;
        const int INF=0x7fffffff;
        const int MIN=0x80000000; //the binary style of the minimum value
        int cnt=0;
        long a1=0;
        long b=1;
        while(!a.empty()) a.pop();
        while(!s.empty()) s.pop();
        for(int i=0;i<str.size();i++){ //判别输入是否合理，已将输入的值压入队列中
            if(str[i]==' '&&!flag) continue;
            else if(str[i]!=' '&&str[i]!='+'&&str[i]!='-'&&!(str[i]>='0'&&str[i]<='9')&&!flag) return 0;
            else if(str[i]=='-'&&!flag){
                neg=true;
                flag=true;
            }
            else if(str[i]=='+'&!flag) flag=true;
            else if(str[i]>='0'&&str[i]<='9'){
                cnt++;
                a.push(str[i]-'0');
                flag=true;
            }
            else if(!(str[i]>='0'&&str[i]<='9')&&flag) break;
        }
        while(a.front()==0 &&!a.empty()) a.pop(); //去除首部的0
        while(!a.empty()){ //将队列的值弹出压入到栈中，为了方便运算，从低位到高位~
            int c=a.front();
            a.pop();
            s.push(c);
        }
        if(neg){
            while(!s.empty()){
                if(b>INF) return MIN;
                a1-=b*s.top();
                s.pop();
                if(a1<MIN) return MIN;
                b*=10;
            }
        }
        else{
            while(!s.empty()){
                if(b>INF) return INF;
                a1+=b*s.top();
                s.pop();
                if(a1>INF) return INF;
                b*=10;
            }
        }
        return a1;
    }
};
