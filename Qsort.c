#include <stdio.h>

void Qsort(int scores[], int left, int right);
void Swap(int scores[], int i, int j);
void showData(int scores[], int size);

 /* クイックソートを行う */
void QSort(int scores[], int left, int right)
{
    int i, j;
    int pivot;

    i = left;                           /* ソートする配列の一番小さい要素の添字 */
    j = right;                          /* ソートする配列の一番大きい要素の添字 */

    pivot = scores[(left + right) / 2]; /* 基準値を配列の中央付近にとる */

    while (1) {                    

        while (scores[i] < pivot)       /* pivot より大きい値が */
            i++;                        /* 出るまで i を増加させる */

        while (pivot < scores[j])       /* pivot より小さい値が */
            j--;                        /*  出るまで j を減少させる */
        if (i >= j)                     /* i >= j なら */
            break;                 

        Swap(scores, i, j);             /* x[i] と x[j]を交換 */
        i++;                            /* 次のデータ */
        j--;
    }

    if (left < i - 1)                   /* 基準値の左に 2 以上要素があれば */
        QSort(scores, left, i - 1);     /* 左の配列を Q ソートする */
    if (j + 1 <  right)                 /* 基準値の右に 2 以上要素があれば */
        QSort(scores, j + 1, right);    /* 右の配列を Q ソートする */
}

  /* 配列の要素を交換する */
void Swap(int scores[], int i, int j)
{
    int temp;

    temp = scores[i];
    scores[i] = scores[j];
    scores[j] = temp;
}



void showData(int scores[], int size)
{
    for (int num = 0; num < size; num++)
    {
        printf("data[%d]: %d\n", num, scores[num]);
    }
}

int main()
{
    const int SIZE = 5; //定数として配列のサイズを宣言
    int scores[SIZE] = {0, 60, 70, 100, 90};
    printf("データサイズ: %d\n",SIZE);
    QSort(scores, 0, SIZE - 1);
    showData(scores, SIZE);

    const int OTHER_SIZE = 6;
    printf("データサイズ: %d\n",OTHER_SIZE);
    int scores3[OTHER_SIZE] = {100, 60, 70, 100, 90, 80};
    QSort(scores3, 0, OTHER_SIZE - 1);
    showData(scores3, OTHER_SIZE);

    return 0;
}