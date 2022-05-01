int **alloc_matrix(int YDIM, int XDIM);
void get_dimensions(int*dims);
void fill_matrix(int**matrix, int YDIM, int XDIM,char* file);
void print_matrix(int**matrix,int YDIM,int XDIM);
void compute(int**dist,int**img,int**template,int*dims);