#ifndef otsu
    #define otsu

    #include "gy_image_object.h"

    void preprocessing_otsu(gy_image_object &image)
    {
        int histogram[256],i;

        for(i = 0; i < 256; i++)
        {
            histogram[i] = 0;
        }
    }
#endif
