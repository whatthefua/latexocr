#ifndef mesc_preprocessing_hpp
    #define mesc_preprocessing_hpp

    #include "image_object.hpp"
    #include <utility>
    using namespace std;

    pair<double,double> mesc_mean(gy_image_object img)
    {
        int sumx = 0,sumy = 0,cnt = 0,i,j,w = img.width(),h = img.height();

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                if(img.get_pixel(i,j) == 0)
                {
                    sumx += i * i;
                    sumy += j * j;
                    cnt++;
                }
            }
        }

        return make_pair((double)sumx / (double)cnt / (double)w,(double)sumy / (double)cnt / (double)h);
    }
#endif
