#include <stdio.h>
#include <math.h>

typedef struct
{
    float sides[3];
    float area;
    float parameter;
} triangle;

triangle setTriangle();
float area(triangle triangle);
void bubbleSort(triangle[], int);
int main()
{
    int num;
    printf("Enter number of triangles:\n");
    scanf("%d", &num);
    triangle triangles[num];
    for (int i = 0; i < num; i++)
    {

        printf("Enter sides of triangle %d\n", i + 1);
        triangles[i] = setTriangle();
    }
    bubbleSort(triangles, num);
    printf("Sorted in ascending order according to their area\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.1f ", triangles[i].sides[j]);
        }
        printf("\n");
    }

    return 0;
}
triangle setTriangle()
{
    triangle triangle;
    scanf("%f %f %f", &triangle.sides[0], &triangle.sides[1], &triangle.sides[2]);
    triangle.parameter = 0;
    for (int i = 0; i < 3; i++)
    {
        triangle.parameter += triangle.sides[i];
    }
    triangle.area = area(triangle);
    return triangle;
}
float area(triangle triangle)
{
    float halfParameter = triangle.parameter / 2;
    float underRoot = triangle.parameter / 2;
    for (int i = 0; i < 3; i++)
    {
        underRoot *= (halfParameter - triangle.sides[0]);
    }

    return sqrtf(underRoot);
}
void bubbleSort(triangle array[], int size)
{
    int sorted = 1;
    triangle temp;
    for (int j = 0; j < size; j++)
    {
        sorted = 1;
        for (int i = 0; i < size - j - 1; i++)
        {
            if (array[i].area > array[i + 1].area)
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted)
            break;
    }
}