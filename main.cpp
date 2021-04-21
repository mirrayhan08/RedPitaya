#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>

float CalculateMean(float *value, int max)
{
    int i;
    float sum = 0;
    for( i = 0; i < max; i++)
        sum = sum + value[i];
    return (sum / max);
}

float CalculateVariane(float *value, int max)
{
    float mean = CalculateMean(value, max);
    int i = 0;
    float temp = 0;

    for(i = 0; i < max; i++)
        temp += (value[i] - mean) * (value[i] - mean) ;
    return temp / max;
}

float CalculateMedian(float *arrValue, int max)
{
    float median = 0;
    float value[100];
    int i, j;
    float temp;
    if(max > 100)
        return 0;
    for(i = 0; i < max; i++)
        value[i] = arrValue[i];
    for(i = 0; i < max; i++)
    {
        for(j = 0; j < max - i - 1; j++)
        {
            if(value[j] > value[j + 1])
            {
                temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;
            }
        }
    }
    if( (max % 2) == 1)
    {
        median =  value[ (max + 1) / 2 - 1];
    }
    else
    {
        median = (value[max / 2] + value[max / 2 - 1]) / 2;
    }
    return median;
}

float GetStandardDeviation(float *value, int max)
{
    return sqrt(CalculateVariane(value, max));
}

int main()
{
    float arrNumbers[100];
    int i, max;
    float mean, variance, median, devi;
    char buf[1024];
    printf("Total Number of Elements: ");
    scanf("%d", &max);

    for(i = 0; i < max; i++)
    {
        printf("Enter [%d] Number: ", i + 1);
        scanf("%f", &arrNumbers[i]);
    }

    printf("Total Numbers: %d\n", max);

    mean = CalculateMean(arrNumbers, max);
    median = CalculateMedian(arrNumbers, max);
    variance = CalculateVariane(arrNumbers, max);
    devi = GetStandardDeviation(arrNumbers, max);

    printf("Mean: %f", mean);
    printf("\nVariance: %f",  variance);
    printf("\nMedian: %f", median);
    printf("\nDeviation: %f", devi);
    return 0;
}
