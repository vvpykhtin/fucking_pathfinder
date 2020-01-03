#include "pathfinder.h"
void way(int len, int **kk, char *v)
{
    int arr[len];
    int **mat = mx_matrix(v);
   // int sum = 0;
    int hui = 0;
    for (int k=0; k<len; k++) { 
        for (int i=0; i<len; i++){ 
            for (int j=0; j<len; j++){ 
                if (mat[i][k] && mat[k][j] && i!=j) 
                    if (mat[i][k]+mat[k][j]<mat[i][j] || mat[i][j]==0) {
                        arr[hui] = mat[i][k];
                        arr[hui++] = mat[k][j];
                        mat[i][j]=mat[i][k]+mat[k][j];
                        if(mat[i][j] == kk[i][j])
                            printf("%d\n", mat[i][j]);
                    }
                }
            }
            hui = 0;
        }

}

void mx_pathfinder(char *v) {
	char *s = mx_file_to_str(v);
    char **arr = mx_ss(s, '-', ',', '\n');
    int **mat = mx_matrix(v);
    int len = digits(arr[0]);


    for (int k=0; k<len; k++) 
        for (int i=0; i<len; i++) 
            for (int j=0; j<len; j++) 
                if (mat[i][k] && mat[k][j] && i!=j) 
                    if (mat[i][k]+mat[k][j]<mat[i][j] || mat[i][j]==0)   
                        mat[i][j]=mat[i][k]+mat[k][j];
    for(int i = 0; i < len;i++) {
        for(int j = 0; j < len;j++)
            printf("%d ", mat[i][j]);
        printf("%c",'\n');
    }
    printf("%s",arr[0]);
    way(len, mat, v);
}
