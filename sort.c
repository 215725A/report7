#include <stdio.h>

void data_sort(int scores[], int size);
void showData(int scores[], int size);

void data_sort(int scores[], int size)
{
    int tmp;

    /* 数値を降順にソート */
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (scores[i] < scores[j])
            {
                tmp = scores[i];
                scores[i] = scores[j];
                scores[j] = tmp;
            }
        }
    }

    showData(scores, size);
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
    data_sort(scores, SIZE);
    printf("----------\n");
    int scores2[SIZE] = {100, 60, 70, 100, 90};
    data_sort(scores2, SIZE);
    printf("----------\n");
    const int SIZE2 = 6;
    int scores3[SIZE2] = {100, 60, 70, 100, 90, 80};
    data_sort(scores3, SIZE2);

    return 0;
}