#ifndef zhang_suen
    #define zhang_suen

    #include "image_object.hpp"

    //runs zhang suen thinning algorithm on img
    void preprocessing_zhang_suen(gy_image_object &img)
    {
        int w = img.width(),h = img.height(),i,j;

        char **A = new char*[w];
        char **B = new char*[w];
        unsigned char **N = new unsigned char*[w];
        for(size_t i=0;i<w;i++){
            A[i] = new char[h];
            B[i] = new char[h];
            N[i] = new unsigned char[h];
        }

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



        for(size_t i=w;i>0;){
            delete[] A[--i];
            delete[] B[i];
            delete[] N[i];
        }
        delete[] A;
        delete[] B;
        delete[] N;
    }

    void preprocessing_zhang_suen_100x100(bool** img)
    {
        char **A = new char*[100];
        char **B = new char*[100];
        unsigned char **N = new unsigned char*[100];

        for(size_t i = 0; i < 100; i++)
        {
            A[i] = new char[100];
            B[i] = new char[100];
            N[i] = new unsigned char[100];
        }

        bool change_flag = 1;
        int i,j;

        while(change_flag)
        {
            change_flag = 0;

            for(i = 0; i < 100; i++)
            {
                for(j = 0; j < 100; j++)
                {
                    A[i][j] = 0;
                    B[i][j] = 0;
                }
            }

            for(i = 1; i < 99; i++)
            {
                for(j = 1; j < 99; j++)
                {
                    if(img[i][j - 1] == 0 && img[i + 1][j - 1] == 1)
                    {
                        A[i][j]++;
                    }

                    if(img[i + 1][j - 1] == 0 && img[i + 1][j] == 1)
                    {
                        A[i][j]++;
                    }

                    if(img[i + 1][j] == 0 && img[i + 1][j + 1] == 1)
                    {
                        A[i][j]++;
                    }

                    if(img[i + 1][j + 1] == 0 && img[i][j + 1] == 1)
                    {
                        A[i][j]++;
                    }

                    if(img[i][j + 1] == 0 && img[i - 1][j + 1] == 1)
                    {
                        A[i][j]++;
                    }

                    if(img[i - 1][j + 1] == 0 && img[i - 1][j] == 1)
                    {
                        A[i][j]++;
                    }

                    if(img[i - 1][j] == 0 && img[i - 1][j - 1] == 1)
                    {
                        A[i][j]++;
                    }

                    if(img[i - 1][j - 1] == 0 && img[i][j - 1] == 1)
                    {
                        A[i][j]++;
                    }

                    if(img[i][j] == 1)
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

            for(i = 1; i < 99; i++)
            {
                for(j = 1; j < 99; j++)
                {
                    N[i][j] = img[i][j];

                    if(img[i][j] == 1 && (2 <= B[i][j]) && (B[i][j] <= 6) && (A[i][j] == 1) && ((img[i][j - 1] == 0) || (img[i + 1][j] == 0 ) || (img[i][j + 1] == 0)) && ((img[i + 1][j] == 0 ) || (img[i][j + 1] == 0) || (img[i - 1][j])))
                    {
                        change_flag = 1;
                        N[i][j] = 0;
                    }
                }
            }

            for(i = 1; i < 99; i++)
            {
                for(j = 1; j < 99; j++)
                {
                    N[i][j] = img[i][j];

                    if(img[i][j] == 1 && (2 <= B[i][j]) && (B[i][j] <= 6) && (A[i][j] == 1) && ((img[i][j - 1] == 0) || (img[i + 1][j] == 0 ) || (img[i - 1][j] == 0)) && ((img[i][j - 1] == 0 ) || (img[i][j + 1] == 0) || (img[i - 1][j])))
                    {
                        change_flag = 1;
                        N[i][j] = 0;
                    }
                }
            }

            for(i = 1; i < 99; i++)
            {
                for(j = 1; j < 99; j++)
                {
                    img[i][j] = N[i][j];
                }
            }
        }

        for(size_t i = 100; i > 0;)
        {
            delete[] A[--i];
            delete[] B[i];
            delete[] N[i];
        }

        delete[] A;
        delete[] B;
        delete[] N;
    }
#endif
