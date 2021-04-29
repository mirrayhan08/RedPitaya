#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>

#define BUFFER_SIZE 1024
#define MAXCHAR 1000

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

// A binary search based function that returns index of a peak element
int findPeakUtil(float arr[], int low, int high, int n)
{
    // Fin index of middle element
    int mid = low + (high - low)/2;  /* (low + high)/2 */

    // Compare middle element with its neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
        (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;
        // If middle element is not peak and its left neighbor is greater than it
        // then left half must have a peak element
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUtil(arr, low, (mid -1), n);
        // If middle element is not peak and its right neighbor is greater than it
        // then right half must have a peak element
    else return findPeakUtil(arr, (mid + 1), high, n);
}

// A wrapper over recursive function findPeakUtil()
int findPeak(float arr[], int n)
{
    return findPeakUtil(arr, 0, n-1, n);
}

int main()
{
    float data[] = {273,274,281,286,284,284,289,295,294,293,300,309,310,309,316,329,328,325,329,348,350,338,350,374,362,364,381,427,407,345,378,412,422,479,401,437,472,406,677,949,589,431,894,920,957,693,1098,723,601,1707,1900,1335,1721,1985,1360,2746,2627,1934,630,1247,1459,797,642,685,671,394,304,403,396,265,247,251,251,208,193,187,177,155,134,131,132,114,101,98,96};
    //float data[] = {1, 3, 20, 4, 1, 30};
    int  length =0;
    float mean, variance, median, devi, peak;
    char buf[BUFFER_SIZE];

    //CSV open testing
    FILE *fp;
    char row[MAXCHAR];
    fp = fopen("C:\\D\\MS Study\\3rd Semester\\AIS\\RedPitaya\\ml\\human.csv","r");
    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        printf("Row: %s", row);
    }

    //End of the CSV open testing

    //Calculate the Array Length
    length = sizeof(data) / sizeof(data[0]);
    //printf("\nLength: %d", length);
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
        peak = findPeak(data, length);
        //Writing the data into the file
        fprintf(fpt,"%f, %f, %f, %f, %f\n", mean, variance, median, devi, peak);
    }
    //Close the CSV file
    fclose(fpt);

    //Print the calculation values
    printf("Mean: %f", mean);
    printf("\nVariance: %f",  variance);
    printf("\nMedian: %f", median);
    printf("\nDeviation: %f", devi);
    printf("\nPeak point: %f", peak);

    //Input CSV file as arrya

    int peak_arr[length / 2];
    int i, k = 0;
    int next, previous = 0;

    for(i = 0; i < length; i++){
        if(i + 1 == length){
            next = 0;
        }
        else{
            next = data[i + 1];
        }

        if(data[i] > next && data[i] >= previous){
            peak_arr[k++] = data[i];
        }
        previous = data[i];
    }
    printf("\nPeak points: %d", previous);

    return 0;
}
