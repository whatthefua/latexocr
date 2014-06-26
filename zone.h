//
//  zone.h
//  ocr
//
//  Created by Teerapat Jenrungrot on 6/26/2557 BE.
//  Copyright (c) 2557 Teerapat Jenrungrot. All rights reserved.
//
#ifndef ocr_zone_h
#define ocr_zone_h

#include "main.h"

int **pass;
int **img;

const int THRESHOLD = 50;

const int LEFT = 50;
const int TOP = 50;
const int RIGHT = 50;
const int BOTTOM = 50;

const int DIRECTION = 8;
const int dify[] = {-1,-1,-1,0,0,1,1,1};
const int difx[] = {-1,0,1,-1,1,-1,0,1};

int sum_y,sum_x;
int count_pixel;
int W,H;

void fill(int width,int height,int x,int y){
    pass[y][x] = true;
    sum_x += x;
    sum_y += y;
    count_pixel++;
    for(int i=0;i<DIRECTION;i++){
        if( y+dify[i] >= 0 && y+dify[i] < height && x+difx[i] >= 0 && x+difx[i] < width){
            if(not pass[y+dify[i]][x+difx[i]] and img[y+dify[i]][x+difx[i]] <= THRESHOLD){
                fill(width,height,x+difx[i],y+dify[i]);
            }
        }
    }
}

int** get_all(int width,int height,int x,int y,int L,int T,int R,int B){
    int **A = new int*[T+B];
    for(size_t i=0;i<T+B;i++) A[i] = new int[L+R];
    
    for(int r=std::max(y-T,0),i=0;r<std::min(y+B,height);r++,i++){
        for(int c=std::max(x-L,0),j=0;c<std::min(x+R,width);c++,j++){
            A[i][j] = img[r][c];
        }
    }
    return A;
}

gy_image_object print100x100(int **A){
    gy_image_object output;
    output.resize(100,100);
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            output.set_pixel(j, i, A[i][j]);
        }
    }
    return output;
}

// unoptimized to debug easier
std::vector < int** > find_all(gy_image_object _img){
    std::vector < int** > output;
   
    int W = _img.width(), H = _img.height();
    
    pass = new int*[H];
    img = new int*[H];
    for(size_t i=0;i<H;i++){
        pass[i] = new int[W];
        img[i] = new int[W];
    }
    for(int i=0;i<H;i++) for(int j=0;j<W;j++){
        pass[i][j] = false;
        img[i][j] = _img.get_pixel(j, i);
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(not pass[i][j] and img[i][j] <= THRESHOLD){
                count_pixel = sum_x = sum_y = 0;
                
                fill(W,H,j,i);
                
                sum_x = (int)floor((double)sum_x/(double)count_pixel);
                sum_y = (int)floor((double)sum_y/(double)count_pixel);
                
                int **A = get_all(W,H,sum_x,sum_y,LEFT,TOP,RIGHT,BOTTOM);
                output.push_back(A);
            }
        }
    }
    end:
    
    return output;
}

#endif
