#ifndef image_object
    #define image_object

    #include <cstdlib>

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

            for(i = 0; i < _w; i++)
            {
                free(_image[i]);
            }

            free(_image);

            _w = w;
            _h = h;
            _image = (unsigned char**) malloc(w * sizeof(unsigned char*));

            for(int i = 0; i < w; i++)
            {
                _image[i] = (unsigned char*) malloc(h * sizeof(unsigned char));
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
    };
#endif
