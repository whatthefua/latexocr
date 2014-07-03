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
#include <windows.h>
using namespace std;

#include "preprocessing.hpp"
#include "ai.hpp"

double dat[28],cmp[28];

double meas()
{
    int i;
    double res = (double)0;

    for(i = 0; i < 28; i++)
    {
        res += (dat[i] - cmp[i]) * (dat[i] - cmp[i]);
    }

    return res;
}

int main()
{
    FILE *fp;
    char buff[100];
    int i,j,k,res;
    double mn = 100000;

    fp = fopen("test_data/vec/0/4.vec","r");

    for(i = 0; i < 28; i++)
    {
        fscanf(fp,"%lf",dat + i);
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 1; j <= 10; j++)
        {
            sprintf(buff,"train_data/vec/%d/%d.vec",i,j);
            fp = fopen(buff,"r");

            for(k = 0; k < 28; k++)
            {
                fscanf(fp,"%lf",cmp + k);
            }

            if(meas() < mn)
            {
                mn = meas();
                res = i;
            }
        }
    }

    printf("%lf %d",mn,res);
}
