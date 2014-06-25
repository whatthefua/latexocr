#ifndef otsu
    #define otsu

    #include "image_object.hpp"

    //runs otsu's method on image
    void preprocessing_otsu(gy_image_object &image)
    {
        int histogram[256],i,j,w = image.width(),h = image.height(),sum = 0;

        for(i = 0; i < 256; i++)
        {
            histogram[i] = 0;
        }

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                histogram[image.get_pixel(i,j)]++;
            }
        }

        for(i = 1; i < 256; i++)
        {
            sum += i * histogram[i];
        }

        int tot = w * h,wB = 0,wF = 0,sumB = 0,threshold=0;
        double mB,mF,between,mx = 0,th1=0.0,th2=0.0;

        for(i = 0; i < 256; i++)
        {
            wB += histogram[i];
            wF = tot - wB;
            sumB += i * histogram[i];
            mB = (double)sumB / (double)wB;
            mF = (double)(sum - sumB) / (double)wF;
            between = (double)wB * (double)wF * (mB - mF) * (mB - mF);

            if(between >= mx)
            {
                th1 = (double)i;

                if(between > mx)
                {
                    th2 = (double)i;
                }

                mx = between;
            }
        }

        threshold = (int)((th1 + th2) / (double)2.0);

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                (image.get_pixel(i,j) < threshold)? image.set_pixel(i,j,0): image.set_pixel(i,j,255);
            }
        }
    }
#endif
