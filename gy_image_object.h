#ifndef gy_image_object
    #define gy_image_object

    #include <cstdlib>

    class gy_image_object
    {
        int _w,_h;
        unsigned char **_image;

    public:
        gy_image_object()
        {
            _w = 1;
            _h = 1;

            resize(1,1);
        }

        void resize(int w, int h)
        {
            _w = w;
            _h = h;
            _image = (unsigned char**) malloc(w * sizeof(unsigned char*));

            for(int i = 0; i < w; i++)
            {
                _image[i] = (unsigned char*) malloc(h * sizeof(unsigned char));
            }
        }

        void set_pixel(int x, int y, unsigned char v)
        {
            if(x >= _w || x < 0 || y >= _h || y < 0)
            {
                return;
            }

            _image[x][y] = v;
        }

        unsigned char get_pixel(int x, int y)
        {
            if(x >= _w || x < 0 || y >= _h || y < 0)
            {
                return 0;
            }

            return _image[x][y];
        }
    };
#endif
