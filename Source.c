#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include<time.h>
int main(void) {
    FILE* fo;
    setlocale(LC_ALL, "Russian");

    float* array;
    float* array_sbros;

    int n;
    unsigned int max;
    int min;
    float input;
    int Choose = 0;
    int Choose_Sort = 0;
    int Choose_interface = 0;
    printf("Enter n  ");  scanf_s("%d", &n);
    array = (float*)malloc(n * sizeof(float));
    array_sbros = (float*)malloc(n * sizeof(float));
    //����� Random,����� ��� c �����
    printf("1-������,2-�����,3-����\n");
    printf("�������:"); scanf_s("%d", &Choose);

    //������ start
    if (Choose == 1) {
        printf("Enter min: "); scanf_s("%d", &min);
        printf("Enter max: "); scanf_s("%d", &max);
        fopen_s(&fo, "C:\\Users\\�������\\source\\repos\\Sort\\Sort\\textfilesec.txt", "w");
        for (int i = 0; i < n; i++)
        {
            array[i] = (float)rand() / RAND_MAX * (max - min) + min;
            
            fprintf(fo, "%f\n", (array[i]));
        }
        fclose(fo);

    }


    //������ end
    //���������� start
    if (Choose == 2) {
        fopen_s(&fo, "C:\\Users\\�������\\source\\repos\\Sort\\Sort\\textfilesec.txt", "w");
        for (int i = 0; i < n; i++) {
            printf("Enter numb %d:\n", n); scanf_s("%f", &input);
            array[i] = input;

        }
        fclose(fo);
    }
    //���������� end
    //���� start
    if (Choose == 3)
    {
        fopen_s(&fo, "C:\\Users\\�������\\source\\repos\\Sort\\Sort\\textfile.txt", "r");
        for (int i = 0; i < n; i++)
        {
            fscanf_s(fo, "%f", &(array[i]));
        }
        fclose(fo);
        fopen_s(&fo, "C:\\Users\\�������\\source\\repos\\Sort\\Sort\\textfilesec.txt", "w");
        for (int i = 0; i < n; i++)
        {
            fprintf(fo, "%f\n", (array[i]));
        }
        fclose(fo);
    }   
}
    //���� end