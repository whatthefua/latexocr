#define f first
#define s second
#define INF 2000000000
#define LNF 8000000000000000000
#define mp make_pair
#define ll long long int
#define BL for(int K = 1; K <= T; K++)
#define db double

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "preprocessing.hpp"
using namespace std;

bool B[3000][2000];
gy_image_object img;
int Mx,mx,My,my;

void clearB(int w, int h)
{
    int i,j;

    for(i = 0; i < w; i++)
    {
        for(j = 0; j < h; j++)
        {
            B[i][j] = 0;
        }
    }
}

void floodfill(int x, int y)
{
    B[x][y] = 1;
    img.set_pixel(x,y,255);
    Mx = max(Mx,x);
    mx = min(mx,x);
    My = max(My,y);
    my = min(my,y);

    if(img.get_pixel(x + 1,y) == 0)
    {
        floodfill(x + 1,y);
    }

    if(img.get_pixel(x - 1,y) == 0)
    {
        floodfill(x - 1,y);
    }

    if(img.get_pixel(x,y + 1) == 0)
    {
        floodfill(x,y + 1);
    }

    if(img.get_pixel(x,y - 1) == 0)
    {
        floodfill(x,y - 1);
    }
}

void saveimg(char* dir)
{
    gy_image_object tmp;
    int i,j;

    tmp.resize(Mx - mx + 1,My - my + 1);

    for(i = mx; i <= Mx; i++)
    {
        for(j = my; j <= My; j++)
        {
            tmp.set_pixel(i - mx,j - my,(B[i][j] == 0)? 255: 0);
        }
    }

    tmp.save_image(dir);
}

int main()
{
    int i,j,k,cnt,w,h;
    char buff[100];

    for(i = 4; i <= 9; i++)
    {
        sprintf(buff,"%d.bmp",i);
        img.load_image(buff);
        w = img.width();
        h = img.height();
        cnt = 1;

        for(j = 0; j < w; j++)
        {
            for(k = 0; k < h; k++)
            {
                if(img.get_pixel(j,k) == 0)
                {
                    Mx = 0;
                    mx = INF;
                    My = 0;
                    my = INF;

                    clearB(w,h);
                    floodfill(j,k);

                    sprintf(buff,"train_data/%d/%d.bmp",i,cnt);
                    saveimg(buff);
                    cnt++;
                }
            }
        }
    }
}
