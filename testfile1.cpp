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

vector<bool**> chars;

int main()
{
    gy_image_object test;

    test.load_image("otsu.bmp");

    chars = find_all(test);

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 70; j++)
        {
            printf("%c",(chars[140][i][j] == 0)? ' ':'#');
        }
        printf("\n");
    }

    preprocessing_zhang_suen_100x100(chars[140]);

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 70; j++)
        {
            printf("%c",(chars[140][i][j] == 0)? ' ':'#');
        }
        printf("\n");
    }
}
