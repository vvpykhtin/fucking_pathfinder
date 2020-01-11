#include <stdio.h>
#include "pathfinder.h"



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
