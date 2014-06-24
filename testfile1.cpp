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

int main()
{
    gy_image_object test;

    test.load_image("image.bmp");

    printf("%d %d %d",test.width(),test.height(),test.get_pixel(99,113));

    preprocessing_otsu(test);
    test.save_image("otsu_test.bmp");
}
