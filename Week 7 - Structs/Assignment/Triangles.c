#include <stdio.h>
#include <math.h>

typedef struct triangle
{
    float a;
    float b;
    float c;

    float premiter;
    float area;
} t_TRIANGLE;

void get_triangles(t_TRIANGLE triangles[], int n);
void sort_triangles(t_TRIANGLE triangles[], int n);
void print_sorted_triangles(t_TRIANGLE triangles[], int n);

int main(void)
{
    int n = 0;
    printf("Enter numer of triangles: ");
    scanf("%d", &n);

    t_TRIANGLE triangles[n];

    get_triangles(triangles, n);
    //printf("%f %f %f %f %f", triangles[0].a, triangles[0].b, triangles[0].c, triangles[0].premiter, triangles[0].area);
    sort_triangles(triangles, n);
    print_sorted_triangles(triangles, n);

    return 0;
}

void get_triangles(t_TRIANGLE triangles[], int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%f %f %f", &triangles[i].a, &triangles[i].b, &triangles[i].c);
        triangles[i].premiter = triangles[i].a + triangles[i].b + triangles[i].c;
        float p = triangles[i].premiter / 2;
        triangles[i].area = sqrt(p * (p - triangles[i].a) * (p - triangles[i].b) * (p - triangles[i].c));
    }
}

void sort_triangles(t_TRIANGLE triangles[], int n)
{
    int i = 0;
    int j = 0;
    int min_idx = 0;
    t_TRIANGLE temp;

    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (triangles[j].area < triangles[min_idx].area)
                min_idx = j;
        }
        temp = triangles[min_idx];
        triangles[min_idx] = triangles[i];
        triangles[i] = temp;

    }
}

void print_sorted_triangles(t_TRIANGLE triangles[], int n)
{
    printf("\n\n");
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("%.2f %.2f %.2f\n", triangles[i].a, triangles[i].b, triangles[i].c);
    }
}