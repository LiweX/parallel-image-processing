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
    //print_matrix(dist,dims[0]-dims[2],dims[1]-dims[3]);
    int coordenadas[2];
    //printf("%d %d",coordenadas[1],coordenadas[0]);
    get_minor(coordenadas,dist,dims);
    //printf("%d %d",coordenadas[1],coordenadas[0]);
    FILE * output = fopen("output.txt","w");
    fprintf(output,"%d\n%d\n%d\n%d\n",coordenadas[0],coordenadas[1],dims[2],dims[3]);
    fclose(output);
    return 1;

}
