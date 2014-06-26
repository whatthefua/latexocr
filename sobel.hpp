/*
invert color
*/
#ifndef sobel
    #define sobel

    #include "image_object.hpp"
    #include <cassert>

    void preprocessing_sobel(gy_image_object &img)
    {
        assert(img.width() > 2);
        assert(img.height() > 2);
        
        int **Gx = new int*[img.width() - 2];
        int **Gy = new int*[img.width() - 2];
        for(size_t i=0;i<img.width()-2;i++){
            Gx[i] = new int[img.height() - 2];
            Gy[i] = new int[img.height() - 2];
        }
        
        int **IM = new int*[img.width()];
        for(size_t i=0;i<img.width();i++) IM[i] = new int[img.height()];

        int r=0,w=0,h=0;

        w = img.width();
        h = img.height();
        
        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < h; j++)
            {
                IM[i][j] = img.get_pixel(i,j);
            }
        }

        w -= 2;
        h -= 2;

        img.resize(w,h);

        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < h; j++)
            {
                Gx[i][j] = -IM[i][j] + IM[i + 2][j] - (IM[i][j + 1] << 1) + (IM[i + 2][j + 1] << 1) - IM[i][j + 2] + IM[i + 2][j + 2];
                Gy[i][j] = IM[i][j] - IM[i][j + 2] + (IM[i + 1][j] << 1) - (IM[i + 1][j + 2] << 1) + IM[i + 2][j] - IM[i + 2][j + 2];
                r = sqrt(Gx[i][j] * Gx[i][j] + Gy[i][j] * Gy[i][j]) / 2;
                img.set_pixel(i,j,r);
            }
        }
        
        for(size_t i=img.width();i>0;) delete[] IM[--i];
        delete [] IM;
        
        for(size_t i=img.width()-2;i>0;){
            delete[] Gx[--i];
            delete[] Gy[i];
        }
        delete [] Gx;
        delete [] Gy;
    }
#endif
