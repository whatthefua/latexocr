#include "main.h"
#include "zone.h"

int main(){
//    freopen("output.txt","w",stdout);
    gy_image_object test;
    
    char *name = (char*)malloc(sizeof(char));
    strcpy(name,"train1_bin.bmp");
    test.load_image(name);
    
    std::vector < int** > x = find_all(test);
    for(int i=0;i<x.size();i++){
        gy_image_object output = print100x100(x[i]);
//        for(int j=0;j<100;j++){
//            for(int k=0;k<100;k++) printf("%c",output.get_pixel(k, j)?' ':'*');
//            printf("\n");
//        }
        char *out_name = (char*)malloc(sizeof(char));
        sprintf(out_name, "%d.bmp",i+1);
        
        printf("%s success\n",out_name);
        output.save_image(out_name);
    }
    return 0;
}
