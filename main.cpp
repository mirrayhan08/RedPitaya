#include <stdio.h>
#include <math.h>

double data[85];
int cnt=0;

double CalculateMean()

{

    double sum = 0;
    for(int i = 0; i < cnt; i++)sum=sum+data[i];
    //  printf("%lf",sum / 25);
    return (sum / cnt);

}


double CalculateVariane()

{

    double mean = CalculateMean();

    double temp = 0;

    for(int i = 0; i < cnt; i++)

    {

        temp += (data[i] - mean) * (data[i] - mean) ;

    }

    return temp / cnt;

}



double GetStandardDeviation()

{

    return sqrt(CalculateVariane());

}


double CalculateMedian()
{
    double median = 0;
    double value[100];
    int i, j;
    double temp;
    if(cnt > 100)
        return 0;
    for(i = 0; i < cnt; i++)
        value[i] = data[i];
    for(i = 0; i < cnt; i++)
    {
        for(j = 0; j < cnt - i - 1; j++)
        {
            if(value[j] > value[j + 1])
            {
                temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;
            }
        }
    }
    if( (cnt % 2) == 1)
    {
        median =  value[ (cnt + 1) / 2 - 1];
    }
    else
    {
        median = (value[cnt / 2] + value[cnt / 2 - 1]) / 2;
    }
    return median;
}




int main()
{

    freopen("C:\\D\\MS Study\\3rd Semester\\AIS\\RedPitaya\\human.txt","r",stdin);
    freopen("C:\\D\\MS Study\\3rd Semester\\AIS\\RedPitaya\\newresust.csv","w",stdout);
    double x;
    while(scanf("%lf",&x)==1)
    {
        if(x==0)
        {
            double mean=CalculateMean();
            double vr= CalculateVariane();
            double stdv=  GetStandardDeviation();
            double median = CalculateMedian();
            printf("%lf,%lf,%lf,%lf,1\n",mean,vr,stdv,median);
            cnt=0;

        }
        else data[cnt++]=x;


    }


    return 0;
}
