#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int **alloc_matrix(int XDIM, int YDIM)
{
    int **array;
    array = malloc(sizeof(int*)*(size_t)YDIM);
    for(int i = 0 ; i < YDIM ; i++)
        array[i] = malloc( sizeof(int) *(size_t)XDIM);
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

void fill_matrix(int**matrix, int XDIM, int YDIM,char* file){
    FILE * img = fopen(file,"r");
    char *line = NULL;
    size_t len = 0;
    
    for(int i=0;i<YDIM;i++){
        getline(&line, &len, img);
        char* token = strtok(line," ");
        for(int j=0;j<XDIM;j++){
            matrix[i][j] = atoi(token);
            token=strtok(NULL," "); 
        } 
    } 
}

void print_matrix(int**matrix,int XDIM,int YDIM){
    for(int i=0;i<YDIM;i++){
        printf("\n");
        for(int j=0;j<XDIM;j++){
            printf("%d ",matrix[i][j]);
        }
    }
}

void compute(int**dist,int**img,int**template,int*dims){
    for(int i=0;i<(dims[1]-dims[3]);i++)
        for(int j=0;j<(dims[0]-dims[2]);j++)
            for(int y=0;y<dims[3];y++)
                for(int x=0;x<dims[2];x++)
                    dist[i][j]+=(template[y][x] - img[i+y][j+x])*(template[y][x] - img[i+y][j+x]);
}