#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int N, K;
int vis[201000];

struct point
{
    int pos;
    int step;
    point(int p, int s)
    {
        pos = p;
        step = s;
    }
};

int main()
{
    scanf("%d%d", &N, &K);
    queue<point> q;
    q.push(point(N, 0));      // Å©·ò³õÊ¼Î»ÖÃ
    int end_step = -1;

    while(!q.empty())
    {
        point this_pos = q.front();
        q.pop();

        int x = this_pos.pos, step = this_pos.step;
        if(x == K)
        {
            end_step = step;
            break;
        }

        if(x-1>=0 && x-1<=100000 && vis[x-1]==0)
        {
            q.push(point(x-1, step+1));
            vis[x-1] = 1;
        }
        if(x+1>=0 && x+1<=100000 && vis[x+1]==0)
        {
            q.push(point(x+1, step+1));
            vis[x+1] = 1;
        }
        if(x*2<=100000 && x*2>=0 && vis[x*2]==0)
        {
            q.push(point(x*2, step+1));
            vis[x*2] = 1;
        }
    }
    printf("%d\n", end_step);
    return 0;
}
