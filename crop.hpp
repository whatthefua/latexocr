#ifndef crop_hpp
    #define crop_hpp

    #include "image_object.hpp"

    //crops img to fit black pixels
    void preprocessing_crop_fit(gy_image_object &img)
    {
        int w = img.width(),h = img.height(),i,j,mx = 0,Mx = w - 1,my = 0,My = h - 1;
        bool *buff;

        for(i = 0; i < w; i++)
        {
            for(j = 0; j < h; j++)
            {
                if(img.get_pixel(i,j) == 0)
                {
                    mx = i;
                    goto out1;
                }
            }
        }

        out1:
        for(i = w - 1; i > 0; i--)
        {
            for(j = 0; j < h; j++)
            {
                if(img.get_pixel(i,j) == 0)
                {
                    Mx = i;
                    goto out2;
                }
            }
        }

        out2:
        for(j = 0; j < h; j++)
        {
            for(i = 0; i < w; i++)
            {
                if(img.get_pixel(i,j) == 0)
                {
                    my = j;
                    goto out3;
                }
            }
        }

        out3:
        for(j = h - 1; j >= 0; j--)
        {
            for(i = 0; i < w; i++)
            {
                if(img.get_pixel(i,j) == 0)
                {
                    My = j;
                    goto out4;
                }
            }
        }

        out4:
        buff = (bool*) malloc((Mx - mx + 1) * (My - my + 1));

        for(i = mx; i <= Mx; i++)
        {
            for(j = my; j <= My; j++)
            {
                buff[(i - mx) * (My - my + 1) + j - my] = (img.get_pixel(i,j) == 0)? 0: 1;
            }
        }

        img.resize(Mx - mx + 1,My - my + 1);

        for(i = mx; i <= Mx; i++)
        {
            for(j = my; j <= My; j++)
            {
                img.set_pixel(i - mx,j - my,(buff[(i - mx) * (My - my + 1) + j - my] == 0)? 0: 255);
            }
        }
    }
#endif
