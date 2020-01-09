#include <stdio.h>
#include "pathfinder.h"

int **getm() //эта функция вам не нужна
{
    int **mat = (int **)malloc(5 * sizeof(int *));
    int mat2[5][5] = {
        {0,  11, 10, 0, 0},
        {11, 0,  0,  5, 0},
        {10, 0,  0,  6, 15},
        {0,  5,  6,  0, 4},
        {0,  0,  15, 4, 0}
    };

    for (int i = 0; i < 5; i++)
    {
        mat[i] = (int *)malloc(5 * sizeof(int));
        for (int j = 0; j < 5; j++)
            mat[i][j] = mat2[i][j];
    }
    return mat;
}

char **get_names() //и эта тоже
{
    char **names = (char **)malloc(5 * sizeof(char *));

    for (int i = 0; i < 5; i++)
    {
        names[i] = (char *)malloc(2 *sizeof(char));
        names[i][0] = 65 + i;
        names[i][1] = '\0'; //шо ты вылупился?
    }
    return names;
}

//это может пригодится
void clean_mat(int ***mat, int size)
{
    for (int i = 0; i < size; i++)
        free((*mat)[i]);
    free(*mat);
    *mat = NULL;
}

//примерно так у вас будет выглядить мейник, но коменты я бы поудалял
int main(int c, char **v)
{
    //if (mx_error(c,v[1])) {
    c++;
    char * s = mx_file_to_str(v[1]);
    char **arr = mx_ss(s, '-', ',', '\n');
    int size = digits(arr[0]);
    int **mat = mx_matrix(v[1]); //короче эта ваша матрица которую вы получили из файла (тоесть та к которой вы еще не применили алгоритм флойда)

    char **names = mx_onlywords(arr); //а это ваш массив имен островов
    t_pf **pf = pathfinder(mat, size); //тут у нас функция которая создает двумерный массив списков путей, но вам должно быть похуй как оно работает, просто знайте что он есть
    clean_mat(&mat, size); //нахуй это дерьмо
    print_result(pf, names, size); // а этой функцией мы принтуем наши пути, и все что вам нужно сделать это поменять принтф на чтото из либы
    mx_del_strarr(&names);
    clean_pathfinder(&pf, size); // славик все почистил
    //system("leaks -q test");
    //}
}
//если вы выполнили все предыдущие коменты, то поздравляю, вы выйграли
