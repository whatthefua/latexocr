#ifndef image_object
    #define image_object

    #include <cstdlib>
    #include <cmath>
    #include <vector>

    //grayscale image object
    class gy_image_object
    {
        int _w,_h;
        unsigned char *_image;

    public:
        //gy_image_object constructor
        gy_image_object()
        {
            _w = 0;
            _h = 0;
            _image = (unsigned char*)malloc(sizeof(unsigned char));

            resize(1,1);
        }

        //gy_image_object destructor
        ~gy_image_object()
        {
            
            _image = (unsigned char*)malloc(sizeof(unsigned char));
            free(_image);
        }

        //resize image to (w,h)
        void resize(int w, int h)
        {
            free(_image);

            _w = w;
            _h = h;
            _image = (unsigned char*)malloc(_w * _h);
        }
        
        // get size of image
        // return pair of (width,height)
        std::pair<int,int> size(){
            return std::pair<int,int>(_w,_h);
        }
        
        //set pixel at (x,y) to v
        void set_pixel(int x, int y, unsigned char v)
        {
            if(x >= _w || x < 0 || y >= _h || y < 0)
            {
                return;
            }

            _image[x * _h + y] = v;
        }

        //get pixel from position (x,y), if pixel does not exist returns 0
        unsigned char get_pixel(int x, int y)
        {
            if(x >= _w || x < 0 || y >= _h || y < 0)
            {
                printf("pixel out of bound\n");

                return 0;
            }

            return _image[x * _h + y];
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

        //loads a bitmap file into image, returns -1 when failure occurs
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
                    _image[j * _h + i] = (int)trunc((double)buff[0] * (double)0.299 + (double)buff[1] * (double)0.587 + (double)buff[2] * (double)0.114);
                }

                fread(buff,1,padding_len,image_fp);
            }

            return 0;
        }

        //saves a bitmap file, returns -1 when failure occurs
        int save_image(char* filename)
        {
            FILE *image_fp;
            unsigned char buff[16];
            int i,j,padding_len,file_size;

            image_fp = fopen(filename,"wb");

            if(image_fp == NULL)
            {
                return -1;
            }

            buff[0] = 'B';
            buff[1] = 'M';
            fwrite(buff,1,2,image_fp);

            padding_len = (4 - ((3 * _w) % 4)) % 4;
            file_size = 54 + (3 * _w + padding_len) * _h;
            buff[0] = file_size % 256;
            buff[1] = (file_size >> 8) % 256;
            buff[2] = (file_size >> 16) % 256;
            buff[3] = (file_size >> 24) % 256;
            fwrite(buff,1,4,image_fp);

            buff[0] = 0;
            buff[1] = 0;
            buff[2] = 0;
            buff[3] = 0;
            fwrite(buff,1,4,image_fp);

            buff[0] = 54;
            fwrite(buff,1,4,image_fp);

            buff[0] = 40;
            fwrite(buff,1,4,image_fp);

            buff[0] = _w % 256;
            buff[1] = (_w >> 8) % 256;
            buff[2] = (_w >> 16) % 256;
            buff[3] = (_w >> 24) % 256;
            fwrite(buff,1,4,image_fp);

            buff[0] = _h % 256;
            buff[1] = (_h >> 8) % 256;
            buff[2] = (_h >> 16) % 256;
            buff[3] = (_h >> 24) % 256;
            fwrite(buff,1,4,image_fp);

            buff[0] = 1;
            buff[1] = 0;
            fwrite(buff,1,2,image_fp);

            buff[0] = 24;
            fwrite(buff,1,2,image_fp);

            buff[0] = 0;
            fwrite(buff,1,4,image_fp);

            file_size -= 54;
            buff[0] = file_size % 256;
            buff[1] = (file_size >> 8) % 256;
            buff[2] = (file_size >> 16) % 256;
            buff[3] = (file_size >> 24) % 256;
            fwrite(buff,1,4,image_fp);

            buff[0] = 0;
            buff[1] = 0;
            buff[2] = 0;
            buff[3] = 0;
            fwrite(buff,1,4,image_fp);
            fwrite(buff,1,4,image_fp);
            fwrite(buff,1,4,image_fp);
            fwrite(buff,1,4,image_fp);

            for(i = _h - 1; i >= 0; i--)
            {
                for(j = 0; j < _w; j++)
                {
                    buff[0] = _image[j * _h + i];
                    buff[1] = _image[j * _h + i];
                    buff[2] = _image[j * _h + i];
                    fwrite(buff,1,3,image_fp);
                }

                buff[0] = 0;
                buff[1] = 0;
                buff[2] = 0;
                buff[3] = 0;
                fwrite(buff,1,padding_len,image_fp);
            }

            return 0;
        }
    };
#endif
