#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myfuncs.h"

int main(){

    int dims[4];
    get_dimensions(dims);
    //for(int i=0;i<4;i++) printf("%d ",dims[i]);
    int ** imagen = alloc_matrix(dims[0],dims[1]);
    int ** template = alloc_matrix(dims[2],dims[3]);
    fill_matrix(imagen,dims[0],dims[1],"imagen.txt");
    fill_matrix(template,dims[2],dims[3],"template.txt");
    //print_matrix(imagen,dims[0],dims[1]);
    //print_matrix(template,dims[2],dims[3]);
    int**dist = alloc_matrix(dims[0]-dims[2],dims[1]-dims[3]);
    compute(dist,imagen,template,dims);
    print_matrix(dist,dims[0]-dims[2],dims[1]-dims[3]);


    return 1;

}
