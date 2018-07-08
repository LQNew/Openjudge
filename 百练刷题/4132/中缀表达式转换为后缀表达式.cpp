#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool compare(char b,char a)
{
    if(a=='+'||a=='-')
    {
        if(b=='+'||b=='-')
            return false;
    }
    else if(a=='*'||a=='/')
    {
        if(b=='+'||b=='-'||b=='*'||b=='/')
            return false;
    }
    return true;
}

int main()
{
    stack<char>mystack;
    char symbol[1000];
    char a,b;
    cin>>symbol;
    for(int i=0;i<strlen(symbol);i++)
    {
        a=symbol[i];
        if(a=='+'||a=='-')
        {
            if(mystack.empty())
                mystack.push(a);
            else
            {
                b=mystack.top();
                if(compare(a,b))
                {
                    mystack.push(a);
                }
                else
                {
                    while(!compare(a,b))
                    {
                        cout<<b;
                        mystack.pop();
                        if(mystack.empty())
                            break;
                        b=mystack.top();
                    }
                    mystack.push(a);
                }
            }
        }
        else if(a=='*'||a=='/')
        {
            if(mystack.empty())
                mystack.push(a);
            else
            {
                b=mystack.top();
                if(compare(a,b))
                {
                    mystack.push(a);
                }
                else
                {
                    while(!compare(a,b))
                    {
                        cout<<b;
                        mystack.pop();
                        if(mystack.empty())
                            break;
                        b=mystack.top();
                    }
                    mystack.push(a);
                }
            }
        }
        else if(a=='(')
            mystack.push(a);
        else if(a==')')
        {
            b=mystack.top();
            while(b!='(')
            {
                mystack.pop();
                cout<<b;
                b=mystack.top();
            }
            mystack.pop();
        }
        else
            cout<<a;
    }
    while(!mystack.empty())
    {
        b=mystack.top();
        cout<<b;
        mystack.pop();
    }
    cout<<endl;
    return 0;
}
