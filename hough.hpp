#ifndef hough
    #define hough

    #include "image_object.hpp"
    #include "matrix.hpp"
    #include <cstdlib>
    #include <cmath>

    //extracts line segments from img into M
    int* preprocessing_linear_hough(gy_image_object &img, int *M)
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
#endif
