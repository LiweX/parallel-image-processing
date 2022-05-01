#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>


// We return the pointer
int **alloc_matrix(int XDIM, int YDIM) /* Allocate the array */
{
    /* Check if allocation succeeded. (check for NULL pointer) */
    int **array;
    array = calloc((size_t)XDIM, sizeof(int *));
    for(int i = 0 ; i < XDIM ; i++)
        array[i] = calloc((size_t)YDIM, sizeof(int));
    return array;
}

void fill_matrix(int**matrix){

}

void get_dimensions(int*dims){
    FILE * file = fopen("dimensiones.txt","r");
    char buffer[100];
    fgets(buffer,100,file);
    char* token = strtok(buffer," ");
    int i = 0;
    while(token!=NULL){
        dims[i]=atoi(token);
        i++;
        token=strtok(NULL," "); 
    }
}


int main(){
    int img_dims[4];
    get_dimensions(img_dims);
}
