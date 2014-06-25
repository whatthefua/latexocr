#ifndef hough
    #define hough

    #include "image_object.hpp"
    #include <cstdlib>
    #include <cmath>

    //extracts line segments from img into M
    int* preprocessing_linear_hough(gy_image_object img, int *M)
    {
        int w = img.width(),h = img.height(),i,j,d,diagonal;
        double theta;

        diagonal = (int)ceil(sqrt(w * w + h * h));

        M = (int*) malloc ((diagonal + 1) * 360 * sizeof(int));

        for(i = 0; i < diagonal * 360; i++)
        {
            M[i] = 0;
        }

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                if(img.get_pixel(i,j) == 0)
                {
                    for(theta = (double)-89; theta <= (double)90; theta ++)
                    {
                        d = trunc((double)j * cos(theta * M_PI / (double)180) - (double)i * sin(theta * M_PI / (double)180)) + diagonal;
                        M[d * 180 + (int)theta + 89]++;
                    }
                }
            }
        }

        return M;
    }

    /*extracts circles from img into M
    WARNING: computationally expensive in both time and memory, beware of large images*/
    int* preprocessing_circular_hough(gy_image_object img, int* M, int minRadius, int maxRadius)
    {
        int w = img.width(),h = img.height(),i,j,k,l,x,y,mxi = 0,mni = 2000000000;

        M = (int*) malloc (w * h * (maxRadius - minRadius + 1) * sizeof(int));

        for(i = 0; i < w * h * (maxRadius - minRadius + 1); i++)
        {
            M[i] = 0;
            mxi = max(mxi,i);
            mni = min(mni,i);
        }

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                if(img.get_pixel(i,j) == 0)
                {
                    for(k = minRadius; k <= maxRadius; k++)
                    {
                        for(l = 0; l < 360; l += 5)
                        {
                            x = trunc((double)i + (double)k * cos((double)l * M_PI / (double)360));
                            y = trunc((double)j + (double)k * sin((double)l * M_PI / (double)360));

                            if((x >= 0) && (y >= 0) && (x < w) && (y < h))
                            {
                                M[(x * h + y) * (maxRadius - minRadius + 1) + k - minRadius]++;
                                mxi = max(mxi,(x * h + y) * (maxRadius - minRadius + 1) + k - minRadius);
                                mni = min(mni,(x * h + y) * (maxRadius - minRadius + 1) + k - minRadius);
                            }
                        }
                    }
                }
            }
        }

        return M;
    }
#endif
