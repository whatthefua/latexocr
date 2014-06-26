#ifndef median_filter
    #define median_filter

    #include "image_object.hpp"

    //run median filter of img with window size window_size
    void preprocessing_median_filter(gy_image_object &img, int window_size)
    {
        int w = img.width(),h = img.height(),i,j,*QS;

        QS = (int*) malloc (w * h * sizeof(int));

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                QS[i * h + j] = (img.get_pixel(i,j) == 0)? 1: 0;
            }
        }

        for(i = 0; i < w; i++)
        {
            for(j = 1; j < h; j++)
            {
                QS[i * h + j] += QS[i * h + j - 1];
            }
        }

        for(i = 1; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                QS[i * h + j] += QS[(i - 1) * h + j];
            }
        }

        img.resize(w - window_size + 1,h - window_size + 1);


    }
#endif
