#include <stdio.h>

int argTask1 = 345; // task1
int sizeTask = 5;  // task2, task3

void executorTask1(int arg);
void executorTask2(int *size);
void executorTask3(int *size);

float *executorStartArr(float arr[], int *size);// task2, task3
float *sequenceData(float arr[], int *size);   // task2
void printDataConsole(float arr[], int *size); // task2, task3

void main()
{
    printf("Start run DZ8\n\n");

    executorTask1(argTask1);
    executorTask2(&sizeTask);
    executorTask3(&sizeTask);
}

void executorTask1(int arg)
{
    printf("Task1 run\n");
    int tempValum[] = {15, -100};
    int *pointer = &arg;
    printf("value Arg = %d, address Arg = %p\n", *pointer, (void *)pointer);

    printf("transform Arg...\n");
    *pointer = ~(*pointer * (*tempValum) + *(tempValum + 1));

    printf("newValue Arg = %d, address Arg = %p\n", arg, (void *)pointer);

    printf("Stop Task1\n\n");
}

void executorTask2(int *size)
{
    printf("Task2 run\n");

    float arr[*size];

    float *arrTemp = executorStartArr(arr, &*size);
    *arr = *arrTemp;
    printDataConsole(arr, &*size);

    float *arrSeq = sequenceData(arr, &*size);
    *arr = *arrSeq;
    printDataConsole(arr, &*size);

    printf("Stop Task2\n\n");
}

void executorTask3(int *size)
{
    printf("Task3 run\n");

    float arr[*size];

    float *arrTemp = executorStartArr(arr, &*size);
    *arr = *arrTemp;
    printDataConsole(arr, &*size);


    printf("Stop Task3\n\n");
}

float *executorStartArr(float arr[], int *size)
{
    float tempValum[] = {2, 2.8, 9, -3.3};

    // наполним массив
    for (int i = 0; i < *size; i++)
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
    return arr;
}

float *sequenceData(float arr[], int *size)
{
    float temp;
    float *poinTemp = &temp;

    for (int i = 0; i < *size - 1; i++)
    {
        for (int j = 0; j < *size - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                *poinTemp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = *poinTemp;
            }
        }
    }
    return arr;
}

void printDataConsole(float arr[], int *size)
{
    printf("out data -> ");
    for (int i = 0; i < *size; i++)
    {
        printf("[%f] ", *(arr + i));
    }
    printf("\n");
}