#ifndef median_filter
    #define median_filter

    #include "image_object.hpp"

    //run median filter of img with window size window_size
    void preprocessing_median_filter(gy_image_object &img, int window_size)
    {
        int w = img.width(),h = img.height(),i,j,*QS,sum;

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

        window_size--;

        img.resize(w - window_size,h - window_size);

        for(i = 0; i < w - window_size; i++)
        {
            for(j = 0; j < h - window_size; j++)
            {
                sum = QS[(i + window_size) * h + j + window_size];
                //printf("sum = QS[%d][%d] = %d\n",i + window_size,j + window_size,QS[(i + window_size) * h + j + window_size]);

                if(j > 0)
                {
                    sum -= QS[(i + window_size) * h + j - 1];
                    //printf("sum -= QS[%d][%d]\n",i + window_size,j - 1);
                }

                if(i > 0)
                {
                    sum -= QS[(i - 1) * h + j + window_size];
                    //printf("sum -= QS[%d][%d]\n",i - 1,j + window_size);
                }

                if(i > 0 && j > 0)
                {
                    sum += QS[(i - 1) * h + j - 1];
                    //printf("sum += QS[%d][%d]\n",i - 1,j - 1);
                }

                //printf("<%d,%d> = %d\n",i,j,sum);

                img.set_pixel(i,j,(sum < (window_size + 1) * (window_size + 1) >> 1)? 255: 0);
            }
        }

        free(QS);
    }
#endif
