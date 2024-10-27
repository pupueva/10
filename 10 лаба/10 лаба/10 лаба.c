#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define CRT_NO_SECURE_DEPRECATE
#define M_PI 3.1415926535
double factor(int N)
{
    double c = 1;
    for (int j = 1; j <= N; j++)
    {
        if (j == 1) {
            c = 1;
        }
        else {
            c = c * j;
        }
    }
    return c;
}
double fa(double x)
{
    double y;
    if (x <= 3) {
        y = pow(x, 2) - 3 * x + 9;
    }
    if (x > 3) {
        y = 1 / (pow(x, 3) + 3);
    }
    return y;
}
double fb(double x)
{
    double y;
    y = x * exp(sin(pow(x, 2)));
    return y;
}

double sinus_n(double x, int N)
{
    double sin = 0.;
    for (int k = 1; k <= N; k++)
    {
        int c = 2 * k - 1;
        sin = x - (pow(-1, k - 1) * (pow(x, c) / factor(c)));
    }
    return sin;
}
double epssin(double x, double eps)
{
    double s = 0, x2 = 0;
    int k = 1, d = 1;
    while (fabs(x) > eps)
    {
        s += d * x2;
        int c = 2 * k - 1;
        x2 = x - (pow(-1, k - 1) * (pow(x, c) / factor(c)));
        d = -d;
        k++;
    }
    return s;
}

void main()
{
    setlocale(LC_CTYPE, "RUS");
    while (1)
    {
        double x, eps;
        int N;
        char a;
        printf("Введите x:");
        scanf_s("%lf", &x);
        printf("Введите eps (Пример: 0.001):");
        scanf_s("%lf", &eps);
        printf("Введите N:");
        scanf_s("%d", &N);
        printf("f1(x) = %lf\t f2(x) = %lf", fa(x), fb(x));
        printf("\nПроизведение = %lf\t Сложение = %lf\t Вычитание = %lf", fa(x) * fb(x), fa(x) + fb(x), fa(x) - fb(x));
        printf("\n");

        double result = epssin(x, eps);

        //вывод значений 
        printf(" Номер  Результат  Отклонение ");
        for (int i = 1; i <= N; i++) {
            double res = sinus_n(x, i);
            printf("\n%4.d | \t%lf | %e | %lf ", i, res, sin(x) - res, result);
        }

        printf("\nПродолжить ? (Да-y / Нет-n)");
        scanf_s("%c", &a, 2);
        if ((a = getchar()) == 'n')break;
    }
    //дз

    float area_round(float a){
        const float pi = 3.14159;
        return pi * a * a;
    }

    float area_rectangle(float a, float b) {
        return a * b;
    }

    float area_triangle(float a, float b, float c) {
        float s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void draw_rectangle(int a, int b) {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }

    void draw_round(char symbol;)
    {
        int radius;

        printf("Enter the radius of the pentagon: ");
        scanf_s("%d", &radius);

        printf("Enter the symbol to draw the pentagon: ");
        scanf_s(" %c", &symbol);

        int center = radius;

        for (int i = 1; i <= 2 * radius - 1; i++) {
            for (int j = 1; j <= 2 * radius - 1; j++) {
                if (j >= center - i + 1 && j <= center + i - 1) {
                    printf("%c", symbol);
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    

    void name(int a) {
        if (a == 5) {
            printf("пентагон\n");
        }
        else {
            printf("кол-во сторон не поддерживается\n");
        }
    }

    int pime() {
        // Задаем стороны пентагона
        float side1, side2, side3, side4, side5;
        printf("введите стороны: ");
        scanf_s("%f %f %f %f %f", &side1, &side2, &side3, &side4, &side5);

        // Меню операций
        int choice;
        printf("\nменю:\n");
        printf("1. рассчет площади\n");
        printf("2.вывести определение \n");
        printf("3. нарисовать фигуру\n");
        printf("напишите свой выбор: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("площадь пентагона: %.2f\n", area_triangle(side1, side2, side3) + area_triangle(side3, side4, side5));
            break;
        case 2:
            name(5);
            break;
        case 3:
            // Рисуем пентагон символом '*'
            draw_round('*');
            break;

        default:

            printf("Invalid choice\n");
            break;
        }

        return 0;
    }
}





   
	

