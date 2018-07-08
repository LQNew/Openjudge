#include<iostream>
#include<cstring>
using namespace std;
int light[7][8];
int light_copy[7][8];
int press[6][7];
void Decomposition(int p) //将p转换为2进制
{
    int i=1;
    while(p!=0)
    {
        if(p%2)
        {
            press[1][i]=1;
            p=p/2;
        }
        else
        {
            p=p/2;
            press[1][i]=0;
        }
        i++;
    }
}

void press_1(int i)
{
    for(int j=1;j<7;j++)
    {
        if(press[i][j])
        {

            light_copy[i-1][j]=!light_copy[i-1][j];
            light_copy[i][j]=!light_copy[i][j];
            light_copy[i+1][j]=!light_copy[i+1][j];
            light_copy[i][j-1]=!light_copy[i][j-1];
            light_copy[i][j+1]=!light_copy[i][j+1];
        }
    }
}

void search_1(int i)
{
    for(int j=1;j<7;j++)
    {
        if(light_copy[i][j])
        {
            press[i+1][j]=1;
        }
    }
}

int main()
{
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<7;j++)
            cin>>light[i][j];
    }
    for(int num=0;num<64;num++)
    {
        memcpy(light_copy,light,sizeof(light));
        memset(press,0,sizeof(press));
        Decomposition(num);
        for(int j=1;j<5;j++)
        {
            press_1(j);
            search_1(j);
        }
        press_1(5);
        int k=1;
        for(k;k<7;k++)
        {
            if(light_copy[5][k])
                break;
        }
        if(k==7)
        {
            for(int i=1;i<6;i++)
            {
                for(int j=1;j<7;j++)
                    cout<<press[i][j]<<" ";
                cout<<endl;
            }
            break;
        }
    }
    return 0;
}
