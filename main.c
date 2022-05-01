#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>


int **alloc_matrix(int YDIM, int XDIM)
{
    int **array;
    array = malloc(sizeof(int*)*(size_t)XDIM);
    for(int i = 0 ; i < XDIM ; i++)
        array[i] = malloc( sizeof(int) *(size_t)YDIM);
    return array;
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
    fclose(file);
}

void fill_matrix(int**matrix, int YDIM, int XDIM,char* file){
    FILE * img = fopen(file,"r");
    char *line = NULL;
    size_t len = 0;
    
    for(int i=0;i<XDIM;i++){
        getline(&line, &len, img);
        char* token = strtok(line," ");
        for(int j=0;j<YDIM;j++){
            matrix[i][j] = atoi(token);
            token=strtok(NULL," "); 
        } 
    }
    
    
}

void print_matrix(int**matrix,int YDIM,int XDIM){
    for(int i=0;i<XDIM;i++){
        printf("\n");
        for(int j=0;j<YDIM;j++){
            printf("%d ",matrix[i][j]);
        }
    }
}

int main(){

    int img_dims[4];
    get_dimensions(img_dims);
    //for(int i=0;i<4;i++) printf("%d ",img_dims[i]);
    int ** imagen = alloc_matrix(img_dims[0],img_dims[1]);
    //int ** template = alloc_matrix(img_dims[2],img_dims[3]);
    fill_matrix(imagen,img_dims[0],img_dims[1],"imagen.txt");
    //print_matrix(imagen,img_dims[0],img_dims[1]);

    return 1;

}
