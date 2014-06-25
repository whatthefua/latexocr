#ifndef zhang_suen
    #define zhang_suen

    #include "image_object.hpp"

    //runs zhang suen thinning algorithm on img
    void preprocessing_zhang_suen(gy_image_object &img)
    {
        int w = img.width(),h = img.height(),i,j;
        char A[w][h],B[w][h];
        unsigned char N[w][h];

        bool change_flag = 1;

        while(change_flag)
        {
            change_flag = 0;

            for(i = 0; i < w; i++)
            {
                for(j = 0; j < h; j++)
                {
                    A[i][j] = 0;
                    B[i][j] = 0;
                }
            }

            for(i = 1; i < w - 1; i++)
            {
                for(j = 1; j < h - 1; j++)
                {
                    if(img.get_pixel(i,j - 1) == 255 && img.get_pixel(i + 1,j - 1) == 0)
                    {
                        A[i][j]++;
                    }

                    if(img.get_pixel(i + 1,j - 1) == 255 && img.get_pixel(i + 1,j) == 0)
                    {
                        A[i][j]++;
                    }

                    if(img.get_pixel(i + 1,j) == 255 && img.get_pixel(i + 1,j + 1) == 0)
                    {
                        A[i][j]++;
                    }

                    if(img.get_pixel(i + 1,j + 1) == 255 && img.get_pixel(i,j + 1) == 0)
                    {
                        A[i][j]++;
                    }

                    if(img.get_pixel(i,j + 1) == 255 && img.get_pixel(i - 1,j + 1) == 0)
                    {
                        A[i][j]++;
                    }

                    if(img.get_pixel(i - 1,j + 1) == 255 && img.get_pixel(i - 1,j) == 0)
                    {
                        A[i][j]++;
                    }

                    if(img.get_pixel(i - 1,j) == 255 && img.get_pixel(i - 1,j - 1) == 0)
                    {
                        A[i][j]++;
                    }

                    if(img.get_pixel(i - 1,j - 1) == 255 && img.get_pixel(i,j - 1) == 0)
                    {
                        A[i][j]++;
                    }

                    if(img.get_pixel(i,j) == 0)
                    {
                        B[i - 1][j - 1]++;
                        B[i][j - 1]++;
                        B[i + 1][j - 1]++;
                        B[i - 1][j]++;
                        B[i + 1][j]++;
                        B[i - 1][j + 1]++;
                        B[i][j + 1]++;
                        B[i + 1][j + 1]++;
                    }
                }
            }

            for(i = 1; i < w - 1; i++)
            {
                for(j = 1; j < h - 1; j++)
                {
                    N[i][j] = (img.get_pixel(i,j) == 0)? 1: 0;
                }
            }

            for(i = 1; i < w - 1; i++)
            {
                for(j = 1; j < h - 1; j++)
                {
                    if(img.get_pixel(i,j) == 0 && (2 <= B[i][j]) && (B[i][j] <= 6) && (A[i][j] == 1) && ((img.get_pixel(i,j - 1) == 255) || (img.get_pixel(i + 1,j) == 255) || (img.get_pixel(i,j + 1) == 255)) && ((img.get_pixel(i + 1,j) == 255) || (img.get_pixel(i,j + 1) == 255) || (img.get_pixel(i - 1,j) == 255)))
                    {
                        change_flag = 1;
                        N[i][j] = 0;
                    }
                }
            }

            for(i = 1; i < w - 1; i++)
            {
                for(j = 1; j < h - 1; j++)
                {
                    if(img.get_pixel(i,j) == 0 && (2 <= B[i][j]) && (B[i][j] <= 6) && (A[i][j] == 1) && ((img.get_pixel(i,j - 1) == 255) || (img.get_pixel(i + 1,j) == 255) || (img.get_pixel(i - 1,j) == 255)) && ((img.get_pixel(i,j - 1) == 255) || (img.get_pixel(i,j + 1) == 255) || (img.get_pixel(i - 1,j) == 255)))
                    {
                        change_flag = 1;
                        N[i][j] = 0;
                    }
                }
            }

            for(i = 1; i < w - 1; i++)
            {
                for(j = 1; j < h - 1; j++)
                {
                    img.set_pixel(i,j,(N[i][j] == 0)? 255: 0);
                }
            }
        }
    }
#endif
