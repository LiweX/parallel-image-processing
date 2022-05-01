#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <omp.h>

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
    if(fgets(buffer,100,file) == NULL) exit(EXIT_FAILURE);
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
        if(getline(&line, &len, img) == -1) exit(EXIT_FAILURE);
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

void compute(int**dist,int**img,int**template,int*dims,int threads){
    omp_set_dynamic(0);
    omp_set_num_threads(threads);
    double n_comparaciones=0;
    double comparaciones_totales=(dims[1]-dims[3])*(dims[0]-dims[2]);
    int i,j,y,x;
    #pragma omp parallel for private(i,j,y,x)
    for(i=0;i<(dims[1]-dims[3]);i++){
        for(j=0;j<(dims[0]-dims[2]);j++){
            for(y=0;y<dims[3];y++)
                for(x=0;x<dims[2];x++){
                    int tmp=(template[y][x] - img[i+y][j+x]);
                    dist[i][j]+=tmp*tmp;
                }
        }
        n_comparaciones+=(dims[0]-dims[2]);
        double porcentaje = (n_comparaciones/comparaciones_totales)*100;
        printf("%.2f%% Complete\r",porcentaje);    
    }
}

void get_minor(int*coords,int**dist,int*dims){
    int temp = dist[0][0];
    for(int i=0;i<(dims[1]-dims[3]);i++)
        for(int j=0;j<(dims[0]-dims[2]);j++){
            if(dist[i][j] < temp){
                temp=dist[i][j];
                coords[0]=j;
                coords[1]=i;
            }  
        }              
}