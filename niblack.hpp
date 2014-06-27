#ifndef niblack
    #define niblack

    #include "image_object.hpp"
    #include <cmath>

    //runs niblack algorithm on img with window size of window_size, pixels will be identified as black if it's darker than avg-threshold_constant*sd
    void preprocessing_niblack(gy_image_object &img, int window_size, double threshold_constant)
    {
        int w = img.width(),h = img.height(),i,j,x1,x2,y1,y2,pix,sum,sd;
        int *QS;
        long long int *PWQS,pwsum;

        QS = (int*) malloc (w * h * sizeof(int));
        PWQS = (long long int*) malloc (w * h * sizeof(long long int));

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                QS[i * h + j] = img.get_pixel(i,j);
                PWQS[i * h + j] = (long long int)img.get_pixel(i,j);
                PWQS[i * h + j] *= PWQS[i * h + j];
            }
        }

        for(i = 0; i < w; i++)
        {
            for(j = 1; j < h; j++)
            {
                QS[i * h + j] += QS[i * h + j - 1];
                PWQS[i * h + j] += PWQS[i * h + j - 1];
            }
        }

        for(i = 1; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                QS[i * h + j] += QS[(i - 1) * h + j];
                PWQS[i * h + j] += PWQS[(i - 1) * h + j];
            }
        }

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                x1 = i - window_size;
                x2 = i + window_size;
                y1 = j - window_size;
                y2 = j + window_size;

                if(x1 < 0)
                {
                    x1 = -1;
                }

                if(y1 < 0)
                {
                    y1 = -1;
                }

                if(x2 >= w)
                {
                    x2 = w - 1;
                }

                if(y2 >= h)
                {
                    y2 = h - 1;
                }

                pix = (x2 - x1) * (y2 - y1);

                sum = QS[x2 * h + y2];
                pwsum = PWQS[x2 * h + y2];

                if(x1 >= 0)
                {
                    sum -= QS[x1 * h + y2];
                    pwsum -= PWQS[x1 * h + y2];
                }

                if(y1 >= 0)
                {
                    sum -= QS[x2 * h + y1];
                    pwsum -= PWQS[x2 * h + y1];
                }

                if(x1 >= 0 && y1 >= 0)
                {
                    sum += QS[x1 * h + y1];
                    pwsum += PWQS[x1 * h + y1];
                }

                sd = (int)sqrt(((long long int)pwsum - (2 * (long long int)sum * (long long int)sum / (long long int)pix)) / (long long int)pix + ((long long int)sum * (long long int)sum / (long long int)pix / (long long int)pix));

                (img.get_pixel(i,j) < sum / pix - (int)(threshold_constant * (double)sd))? img.set_pixel(i,j,0): img.set_pixel(i,j,255);
            }
        }
    }
#endif
