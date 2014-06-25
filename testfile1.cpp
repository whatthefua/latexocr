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
using namespace std;

#include "preprocessing.hpp"

int *M;

int main()
{
    gy_image_object test;

    test.load_image("hough_test.bmp");

    free(M);

    M = preprocessing_circular_hough(test,M,30,50);

    int i,j,k,w = test.width(),h = test.height(),mxi = 0,mni = 2000000000;

    for(i = 0; i < w; i++)
    {
        for(j = 0; j < h; j++)
        {
            for(k = 0; k < 21; k++)
            {
                if(M[(i * h + j) * 21 + k] > 60)
                {
                    printf("(%d,%d,%d): %d\n",i,j,k + 30,M[(i * h + j) * 21 + k]);
                }

                mxi = max(mxi,(i * h + j) * 21 + k);
                mni = min(mni,(i * h + j) * 21 + k);
            }
        }
    }

    printf("%d %d %d\n",mxi,mni,M);

    free(M);
}
