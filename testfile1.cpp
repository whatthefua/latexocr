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

    M = preprocessing_linear_hough(test,M);

    int d = (int)ceil(sqrt(test.width() * test.width() + test.height() * test.height())),i,j;

    for(i = 0; i <= 2 * d; i++)
    {
        for(j = 0; j < 180; j++)
        {
            if(M[i * 180 + j] > 60)
            {
                printf("(%d,%d): %d\n",i - d,j - 89,M[i * 180 + j]);
            }
        }
    }

    free(M);
}
