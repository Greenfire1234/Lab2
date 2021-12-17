#include "header.h"
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
    int Choose=0;
    int Choose_Sort = 0;
    int Choose_interface = 0;
    int Choose_interface_normirovka = 0;
    printf("Enter n  ");  scanf_s("%d", &n);
    array = (float* ) malloc(n * sizeof(float));
    array_sbros = (float*)malloc(n * sizeof(float));
    
    fopen_s(&fo, "C:\\Users\\�������\\source\\repos\\Sort\\Sort\\textfilesec.txt", "r");
    for (int i=0; i < n; i++)
    {
        fscanf_s(fo, "%f", &(array[i]));
    }
    fclose(fo);
    for (int i = 0; i < n; i++) {
        array_sbros[i] = array[i];
    }
    while (Choose_interface != 4) {
        printf("\n1-������ 2-���������� 3-����� 4-����� 5-����������\n");
        scanf_s("%d", &Choose_interface);


        if (Choose_interface == 1) {
            for (int i = 0; i < n; i++) {
                printf("%lf\n", array[i]);
            }
        }
        if (Choose_interface == 2) {


            printf("\n�������� ��� ����������:1-�������,2-������,3-�������\n");
            scanf_s("%d", &Choose_Sort);
            if (Choose_Sort == 1) {

                clock_t start1 = clock();
                Vstavki(array, n);
                clock_t end1 = clock();
                printf("\n�������=%lf\n", (double)((end1 - start1)) / CLOCKS_PER_SEC);
            }
            if (Choose_Sort == 2) {
                clock_t start1 = clock();
                Bistro(array, n);
                clock_t end1 = clock();
                printf("\n������=%lf\n", (double)((end1 - start1)) / CLOCKS_PER_SEC);
            }
            if (Choose_Sort == 3) {
                clock_t start1 = clock();
                Puzirek(array, n);
                clock_t end1 = clock();
                printf("\n�������=%lf\n", (double)((end1 - start1)) / CLOCKS_PER_SEC);

            }
        }
        if (Choose_interface == 3) {
            for (int i = 0; i < n; i++) {
                array[i] = array_sbros[i];
            }
        }


        if (Choose_interface == 5)
        {
            printf("\n�������� ������ ����������\n 1-������ ����� 2-������ ����� 3-����� �������� 4-����������� ����� 5-����������\n");
            scanf_s("%d", &Choose_interface_normirovka);
            if (Choose_interface_normirovka == 1)

            {
                clrscr();
                long double x = 0;
                for (int i = 0; i < n; i++)
                    x += fabs(array[i]);
                printf("\n������ �����=%lf\n\n", x);
            }
            if (Choose_interface_normirovka == 2)
            {
                clrscr();
                long double x = 0, w = 0;
                for (int i = 0; i < n; i++)
                    w += pow(array[i], 2);
                x = sqrt(w);
                printf("\n������ �����=%lf\n\n", x);
            }
            if (Choose_interface_normirovka == 3)
            {
                long double x = 0, w = 0;
                double p = 0;
                printf("\n������� p-�����\n\n");
                scanf_s("%lf", &p);


                for (int i = 0; i < n; i++)
                    w += pow(fabs(array[i]), p);
                x = pow(w, (long double)(1 / p));
                printf("\n����� ø������(%.0lf)=%lf\n\n", p, x);
            }
            if (Choose_interface_normirovka == 4)
            {
                clrscr();
                Bistro(array, n);
                printf("\n����������� �����=%f\n\n", array[n - 1]);
            }
            if (Choose_interface_normirovka == 5)
            {
                clrscr();
                long double x = 0, w = 0;
                for (int i = 0; i < n; i++)
                    w += pow(array[i], 2);
                x = sqrt(w);
                printf("����������:\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%f\n", array[i] * (1.0 / x));
                }
                printf("\n");

            }
        }
    }
    free(array);
    free(array_sbros);

    
    return 0;
}
