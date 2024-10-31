#include <stdio.h>

int argTask1 = 345; // task1
int sizeTask = 5;   // task2, task3

void executorTask1(int arg);
void executorTask2(int *size);
void executorTask3(int *size);

float *executorStartArr(float arr[], int *size);              // task2, task3
float *sequenceData(float arr[], int *size);                  // task2, task3
void printDataConsole(float arr[], int *size);                // task2, task3
float deltaArr(float arr[], int *size);                       // task3
float medianArr(float arr[], int *size);                      // task3
float *findMinMaxArr(float outArr[], float arr[], int *size); // task3

void main()
{
    printf("Start run DZ8\n\n");

    executorTask1(argTask1);
    executorTask2(&sizeTask);
    executorTask3(&sizeTask);
    printf("\nEnd DZ8\n\n");
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

    float deltaTemp;
    float *delta = &deltaTemp;
    *delta = deltaArr(arr, &*size);
    printf("\ndelta = %.4f\n", *delta);

    float medianTemp;
    float *median = &medianTemp;
    *median = medianArr(arr, &*size);
    printf("\nmedian = %.4f\n", *median);

    float valumFind[2] = {};// 0-min 1-max
    float *valumFindTemp = findMinMaxArr(valumFind, arr, &*size);
    *valumFind = *valumFindTemp;
    printf("\nvalumMin = %.4f\n", *valumFind);// 0-min
    printf("\nvalumMax = %.4f\n", *(valumFind + 1));// 1-max

    printf("Stop Task3\n\n");
}

float deltaArr(float arr[], int *size)
{
    float delta;
    float *poinDelta = &delta;

    for (int i = 0; i < *size; i++)
    {
        *poinDelta += *(arr + i);
    }

    *poinDelta = *poinDelta / *size;
    return *poinDelta;
}

float medianArr(float arr[], int *size)
{
    float median;
    float *poinMedian = &median;
    float *arrSeq = sequenceData(arr, &*size);
    *arr = *arrSeq;

    if (*size % 2 == 0)
    {
        *poinMedian = (*(arr + (*size / 2)) + *(arr + (*size / 2 + 1))) / 2; // при четном (серединка[x]+серединка[x+1])/2=сред.серединок
    }
    else
    {
        *poinMedian = *(arr + (*size / 2 + 1)); // или при нечетном середина массива
    }
    return *poinMedian;
}

float *findMinMaxArr(float outArr[], float arr[], int *size)
{
    float *arrSeq = sequenceData(arr, &*size);
    
    *outArr = *arrSeq;// 0-min
    *(outArr + 1) = *(arrSeq + *size - 1);// 1-max
    return outArr;
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