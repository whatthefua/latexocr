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

int main()
{
    int i,j,k,l,m,n,w,h,cnt,bcnt;
    char buff[100];
    gy_image_object img;
    FILE *fp;

    for(i = 3; i <= 9; i++)
    {
        for(j = 1; j <= 9; j++)
        {
            sprintf(buff,"train_data/%d/%d.bmp",i,j);
            img.load_image(buff);
            sprintf(buff,"train_data/vec/%d/%d.vec",i,j);
            fp = fopen(buff,"w");

            w = img.width();
            h = img.height();

            for(k = 0; k < 5; k++)
            {
                for(l = 0; l < 5; l++)
                {
                    cnt = 0;
                    bcnt = 0;

                    for(m = (k * w) / 5; m < ((k + 1) * w) / 5; m++)
                    {
                        for(n = (l * h) / 5; n < ((l + 1) * h) / 5; n++)
                        {
                            cnt++;

                            if(img.get_pixel(m,n) == 0)
                            {
                                bcnt++;
                            }
                        }
                    }

                    fprintf(fp,"%lf ",(double)bcnt / (double)cnt);
                }

                fprintf(fp,"\n");
            }

            bcnt = 0;
            cnt = 0;

            for(k = 0; k < w; k++)
            {
                for(l = 0; 2 * l < h; l++)
                {
                    cnt++;

                    if(img.get_pixel(k,l) == 0)
                    {
                        bcnt++;
                    }
                }
            }

            fprintf(fp,"%lf ",(double)bcnt / (double)cnt);

            bcnt = 0;
            cnt = 0;

            for(k = 0; 2 * k < w; k++)
            {
                for(l = 0; l < h; l++)
                {
                    cnt++;

                    if(img.get_pixel(k,l) == 0)
                    {
                        bcnt++;
                    }
                }
            }

            fprintf(fp,"%lf ",(double)bcnt / (double)cnt);
            fprintf(fp,"%lf ",(double)w / (double)h);
        }
    }
}
