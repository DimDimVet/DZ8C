#include <stdio.h>

int argTask1 = 345; // task1
int sizeTask2 = 5;  // task2

void executorTask1(int arg);
void executorTask2(int size);

void sequenceData(float arr[], int size);
void printSeqDataConsole(float arr[], int size);

void main()
{
    printf("Start run DZ8\n\n");

    executorTask1(argTask1);
    executorTask2(sizeTask2);
}

void executorTask1(int arg)
{
    printf("Task1 run\n");
    int tempValum[] = {15, -100};
    int *pointer = &arg;
    printf("value Arg = %d, address Arg = %p\n", *pointer, (void *)pointer);

    printf("transform Arg...\n");
    *pointer = ~(*pointer * *tempValum + *(tempValum + 1));

    printf("newValue Arg = %d, address Arg = %p\n", arg, (void *)pointer);

    printf("Stop Task1\n\n");
}

void executorTask2(int size)
{
    printf("Task2 run\n");
    float tempValum[] = {2, 2.8, 9, -3.3};
    float arr[size];

    // наполним массив
    for (int i = 0; i < size; i++)
    {
        if ((i % 2) == 0)
        {
            *(arr + i) = i + *tempValum / *(tempValum + 1);
        }
        else
        {
            *(arr + i) = i + *(tempValum + 2) / *(tempValum + 3);
        }
    }
    // покажем
    for (int i = 0; i < size; i++)
    {
        printf("[%f] ", *(arr + i));
    }
    printf("\n");
    
    sequenceData(arr, size);

    printf("Stop Task2\n\n");
}

void sequenceData(float arr[], int size)
{
    float temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printSeqDataConsole(arr, size);
}

void printSeqDataConsole(float arr[], int size)
{
    printf("out seq data -> ");
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            printf("%f ", arr[i]);
        }
    }
    printf("\n");
}