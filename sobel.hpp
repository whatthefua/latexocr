#ifndef sobel
    #define sobel

    #include "image_object.hpp"

    void preprocessing_sobel(gy_image_object& img)
    {
        int Gx[img.width() - 2][img.height() - 2],Gy[img.width() - 2][img.height() - 2],IM[img.width()][img.height()],i,j,r,w,h;

        w = img.width();
        h = img.height();

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                IM[i][j] = img.get_pixel(i,j);
            }
        }

        w -= 2;
        h -= 2;

        img.resize(w,h);

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                Gx[i][j] = -IM[i][j] + IM[i + 2][j] - (IM[i][j + 1] << 1) + (IM[i + 2][j + 1] << 1) - IM[i][j + 2] + IM[i + 2][j + 2];
                Gy[i][j] = IM[i][j] - IM[i][j + 2] + (IM[i + 1][j] << 1) - (IM[i + 1][j + 2] << 1) + IM[i + 2][j] - IM[i + 2][j + 2];
                r = sqrt(Gx[i][j] * Gx[i][j] + Gy[i][j] * Gy[i][j]) / 2;
                img.set_pixel(i,j,r);
            }
        }
    }
#endif
