#include "preprocessing.hpp"

int main()
{
    gy_image_object img;

    img.load_image("Foto.bmp");
    preprocessing_niblack(img,150,1.5);
    preprocessing_median_filter(img,7);
    img.save_image("fbin.bmp");
}
