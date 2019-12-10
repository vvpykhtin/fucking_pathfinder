#include "libmx.h"
// void print_path (int **mat, int present, int fin, int min) {
   
// }


void mx_pathfinder(char *v)
{
	char *s = mx_file_to_str(v);
    char **arr = mx_ss(s, '-', ',', '\n');
    int **mat = mx_matrix(v);
    int line = digits(arr[0]);
    //int min = 0;


    for(int i = 0; i < len;i++)
    {
    	for(int j = 0; j < len;j++)
    	{
    		printf("%d  ",mat[i][j]);
    	}
    	printf("%s\n", "\n");
    }
    printf("%s\n", "\n");

    for (int k=0; k<len; k++) {
        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                if (mat[i][k] && mat[k][j] && i!=j) {
                    if (mat[i][k]+mat[k][j]<mat[i][j] || mat[i][j]==0) {   
                        mat[i][j]=mat[i][k]+mat[k][j];
			        	printf("j %d ", j);
				        printf("i %d ", i);
				        printf("k %d\n", k);
					    for(int i = 0; i < len;i++)
					    {
					    	for(int j = 0; j < len;j++)
					    	{
					    		printf("%d  ",mat[i][j]);
					    	}
				    	printf("%s\n", "\n");
    					}
                    }             
                }
            }
        }
    } 
}
    //  for (int k=0; k<len; k++) {
    //     for (int i=0; i<len; i++) {
    //         for (int j=0; j<len; j++) {
    //             if (mat[i][k] && mat[k][j] && i!=j) {
    //                 if (mat[i][k]+mat[k][j]<mat[i][j] || mat[i][j]==0) {   
    //                     mat[i][j]=mat[i][k]+mat[k][j];
    //                 }             
    //             }
    //         }
    //     }
    // }   
