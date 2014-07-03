/*#define f first
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
#include <windows.h>
using namespace std;

#include "preprocessing.hpp"
#include "ai.hpp"

int *M,*N;
vector<bool**> S;

double dist(double a, double b, double c, double d, double e, double f)
{
    return sqrt((a - d) * (a - d) + (b - e) * (b - e) + (c - f) * (c - f));
}

int main()
{
    gy_image_object inp;
    char buff[1000];
    int i,j,k,l,m,n,d,mx,mx1,mx2,mx3,res,cnt,bcnt,w,h;
    double v1,v2,v3,mn = 10000000;
    FILE *fp;

    for(i = 2; i == 2; i++)
    {
        for(j = 1; j <= 4; j++)
        {
            sprintf(buff,"test_data/%d/%d.bmp",i,j);
            inp.load_image(buff);

            sprintf(buff,"test_data/vec/%d/%d.vec",i,j);
            fp = fopen(buff,"w");

            w = inp.width();
            h = inp.height();

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

                            if(inp.get_pixel(m,n) == 0)
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

                    if(inp.get_pixel(k,l) == 0)
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

                    if(inp.get_pixel(k,l) == 0)
                    {
                        bcnt++;
                    }
                }
            }

            fprintf(fp,"%lf ",(double)bcnt / (double)cnt);
            fprintf(fp,"%lf ",(double)inp.width() / (double)inp.height());

            /*M = preprocessing_linear_hough(inp,M);
            N = preprocessing_circular_hough(inp,N,10,25);

            d = ceil(sqrt(inp.width() * inp.width() + inp.height() * inp.height()));

            mx = 0;

            for(k = 0; k < d; k++)
            {
                for(l = 0; l < 180; l++)
                {
                    if(M[k * 180 + l] > mx)
                    {
                        mx = M[k * 180 + l];
                        mx1 = k;
                        mx2 = l;
                    }
                }
            }

            printf("<%lf,%d>: %d, ",(double)(mx1 - d) / (double)d,mx2 - 89,mx);

            mx = 0;

            for(k = 0; k < inp.width(); k++)
            {
                for(l = 0; l < inp.height(); l++)
                {
                    for(m = 0; m < 16; m++)
                    {
                        if(N[(k * inp.height() + l) * 16 + m] > mx)
                        {
                            mx = N[(k * inp.height() + l) * 16 + m];
                            mx1 = k;
                            mx2 = l;
                            mx3 = m;
                        }
                    }
                }
            }

            printf("<%lf,%lf,%lf>: %d\n",(double)mx1 / (double)inp.width(),(double)mx2 / (double)inp.height(),(double)(mx3 + 10) / (double)d,mx);*/

    //    }
    //}

    /*int i,j;

    inp.load_image("train_data/1/c2.bmp");
    M = preprocessing_linear_hough(inp,M);

    for(i = 0; i < 86; i++)
    {
        for(j = 0; j < 180; j++)
        {
            if(M[i * 180 + j] > 25)
            {
                printf("<%d,%d>: %d\n",i - 43,j - 89,M[i * 180 + j]);
            }
        }
    }
}

*/
