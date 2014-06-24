#ifndef image_object
    #define image_object

    #include <cstdlib>
    #include <cmath>

    //grayscale image object
    class gy_image_object
    {
        int _w,_h;
        unsigned char **_image;

    public:
        //gy_image_object constructor
        gy_image_object()
        {
            _w = 0;
            _h = 0;

            resize(1,1);
        }

        //gy_image_object destructor
        ~gy_image_object()
        {
            int i;

            for(i = 0; i < _w; i++)
            {
                free(_image[i]);
            }

            free(_image);
        }

        //resize image to (w,h)
        void resize(int w, int h)
        {
            int i;

            _w = w;
            _h = h;
            _image = (unsigned char**) malloc(_w * sizeof(unsigned char*));

            for(int i = 0; i < _w; i++)
            {
                _image[i] = (unsigned char*) malloc(_h);
            }
        }

        //set pixel at (x,y) to v
        void set_pixel(int x, int y, unsigned char v)
        {
            if(x >= _w || x < 0 || y >= _h || y < 0)
            {
                return;
            }

            _image[x][y] = v;
        }

        //get pixel from position (x,y), if pixel does not exist returns 0
        unsigned char get_pixel(int x, int y)
        {
            if(x >= _w || x < 0 || y >= _h || y < 0)
            {
                return 0;
            }

            return _image[x][y];
        }

        //returns image's width
        int width()
        {
            return _w;
        }

        //returns image's height
        int height()
        {
            return _h;
        }

        //loads a bitmap file into image
        int load_image(char* filename)
        {
            FILE *image_fp;
            unsigned char buff[16];
            int w,h,i,j,padding_len;

            image_fp = fopen(filename,"rb");

            if(image_fp == NULL)
            {
                return -1;
            }

            fread(buff,1,2,image_fp);

            if((buff[0] != 'B') || (buff[1] != 'M'))
            {
                return -1;
            }

            fread(buff,1,16,image_fp);

            fread(buff,1,4,image_fp);
            w = (int)buff[0] + (((int)buff[1]) << 8) + ((int)buff[2] << 16) + ((int)buff[3] << 24);

            fread(buff,1,4,image_fp);
            h = (int)buff[0] + (((int)buff[1]) << 8) + ((int)buff[2] << 16) + ((int)buff[3] << 24);

            fread(buff,1,2,image_fp);

            fread(buff,1,2,image_fp);
            if((buff[0] != 24) || (buff[1] != 0))
            {
                return -1;
            }

            fread(buff,1,4,image_fp);
            if((buff[0] != 0) || (buff[1] != 0) || (buff[2] != 0) || (buff[3] != 0))
            {
                return -1;
            }

            fread(buff,1,16,image_fp);
            fread(buff,1,4,image_fp);

            if((buff[0] != 0) || (buff[1] != 0) || (buff[2] != 0) || (buff[3] != 0))
            {
                return -1;
            }

            resize(w,h);

            padding_len = (4 - ((3 * w) % 4)) % 4;

            for(i = h - 1; i >= 0; i--)
            {
                for(j = 0; j < w; j++)
                {
                    fread(buff,1,3,image_fp);
                    _image[j][i] = (int)trunc((double)buff[0] * (double)0.299 + (double)buff[1] * (double)0.587 + (double)buff[2] * (double)0.114);
                }

                fread(buff,1,padding_len,image_fp);
            }

            return 0;
        }
    };
#endif
