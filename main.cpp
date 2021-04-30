#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>

#define BUFFER_SIZE 1024
#define MAXCHAR 1000
#define MAXROWS 1000
#define MAXCOLS 100

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

// Load CSV


// Load CSV End

int main()
{
    float data[] = {273,274,281,286,284,284,289,295,294,293,300,309,310,309,316,329,328,325,329,348,350,338,350,374,362,364,381,427,407,345,378,412,422,479,401,437,472,406,677,949,589,431,894,920,957,693,1098,723,601,1707,1900,1335,1721,1985,1360,2746,2627,1934,630,1247,1459,797,642,685,671,394,304,403,396,265,247,251,251,208,193,187,177,155,134,131,132,114,101,98,96};
    int  length =0;
    float mean, variance, median, devi, peak;

    //CSV open testing
    //001

    //002

    //End of the CSV open testing

    //Calculate the Array Length
    length = sizeof(data) / sizeof(data[0]);
    //End or the calculation

    //Print the array length
    printf("Total Numbers: %d\n", length);
    //Crate a CSV file for store the Features
    FILE *fpt;
    fpt = fopen("C:\\D\\MS Study\\3rd Semester\\AIS\\RedPitaya\\ml\\features.csv", "w+");

    //Calculate the array 5 times for testing
    for (int o=0; o < 5; o++) {                 //Create the loop for saving the data 5 times
        mean = CalculateMean(data, length);
        median = CalculateMedian(data, length);
        variance = CalculateVariane(data, length);
        devi = GetStandardDeviation(data, length);
        //Writing the data into the file
        fprintf(fpt,"%f, %f, %f, %f, %f\n", mean, variance, median, devi);
    }
    //Close the CSV file
    fclose(fpt);

    //Print the calculation values
    printf("Mean: %f", mean);
    printf("\nVariance: %f",  variance);
    printf("\nMedian: %f", median);
    printf("\nDeviation: %f", devi);

    //Input CSV file as array
    return 0;
}
