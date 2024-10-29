#include <stdio.h>

int argTask1 = 345; // task1
int sizeTask2 = 5;  // task2

void executorTask1(int arg);
void executorTask2(int size);

void main()
{
    printf("Start run DZ8\n\n");

    executorTask1(argTask1);
    executorTask2(sizeTask2);
}

void executorTask1(int arg)
{
    printf("Task1 run\n");
    int *pointer = &arg;
    printf("value Arg = %d, address Arg = %p\n", *pointer, (void *)pointer);

    printf("transform Arg...\n");
    *pointer = ~(*pointer * 15 - 100);

    printf("newValue Arg = %d, address Arg = %p\n", arg, (void *)pointer);

    printf("Stop Task1\n\n");
}

void executorTask2(int size)
{
    printf("Task2 run\n");
    float arr[size];

    // наполним массив
    for (int i = 0; i < size; i++)
    {
        if ((i % 2) == 0)
        {
            *(arr + i) = i+2/2.8;
        }
        else
        {
            *(arr + i) = i+9 / -3.3;
        }
    }
    // покажем
    for (int i = 0; i < size; i++)
    {
        printf("[%f] ", *(arr+i));
    }
    printf("\n");

    printf("Stop Task2\n\n");
}