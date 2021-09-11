#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

struct datetime
{
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;
};

void in(datetime* array,int n)
{
    ifstream file;
    file.open("file.txt");
    for (int i=0;i<n;i++)
    {
    file>>array[i].second>>array[i].minute>>array[i].hour>>array[i].day>>array[i].month>>array[i].year;
    }
    file.close();
}
void out(datetime* array,int i)
{
    //for(int i=0;i<1;i++)
    
        cout<<"second"<<setw(7)<<"minute"<<setw(5)<<"hour"<<setw(5)<<"day"<<setw(8)<<"month"<<setw(7)<<"year"<<setw(5)<<endl;
        cout<<array[i].second<<setw(7)<<array[i].minute<<setw(5)<<array[i].hour<<setw(5)<<array[i].day<<setw(7)<<array[i].month<<setw(8)<<array[i].year;
        cout<<endl;
    
}
void nextdate(datetime* array,int i)
{
    
    if ((array[i].month==4)||(array[i].month==6)||(array[i].month==9)||(array[i].month==11))
    {
        if (array[i].day==30)
        {
            array[i].day=1;
            array[i].month+=1;
            if(array[i].month==13)
            {
                array[i].month=1;
                array[i].year+=1;
            }
        }
        else{
            array[i].day+=1;
        }
        return;
    }
    if(array[i].month==2)
    {
        if((array[i].year%4==0) &&(array[i].year%4000!=0) && ((array[i].year%100!=0)||(array[i].year%400==0)))
        {
            if(array[i].day==29)
            {
                array[i].day=1;
                array[i].month+=1;
            }
            else{
                array[i].day+=1;
            }
        }
        else{
            if(array[i].day==28)
            {
                array[i].day=1;
                array[i].month+=1;
            }
            else{
                array[i].day+=1;
            }
        }
        return;
    }
    if((array[i].month==1)||(array[i].month==3)||(array[i].month==5)||(array[i].month==7)||(array[i].month==8)||(array[i].month==10)||(array[i].month==12))
    {    
        if (array[i].day==31)
        {
            array[i].day=1;
            array[i].month+=1;
            if(array[i].month==13)
            {
                array[i].month=1;
                array[i].year+=1;
            }
        }
        else{
            array[i].day+=1;
        }
        return;
    }
}
void prevdate(datetime* arrayPrev,int i)
{
    arrayPrev[i].day-=1;

    if(arrayPrev[i].day==0)
    {
        arrayPrev[i].month-=1;
        if(arrayPrev[i].month==2)
        {
            if((arrayPrev[i].year%4==0) &&(arrayPrev[i].year%4000!=0) && ((arrayPrev[i].year%100!=0)||(arrayPrev[i].year%400==0)))
            {
                arrayPrev[i].day=29;
            }
            else {
                arrayPrev[i].day=28;
            }
            return;
        }
        if((arrayPrev[i].month==1)||(arrayPrev[i].month==3)||(arrayPrev[i].month==5)||(arrayPrev[i].month==7)||(arrayPrev[i].month==8)||(arrayPrev[i].month==10)||(arrayPrev[i].month==12))
        {
            arrayPrev[i].day=31;
            return;
        }
        if(arrayPrev[i].month==0)
        {
            arrayPrev[i].month=12;
            arrayPrev[i].year-=1;
            arrayPrev[i].day=31;
            return;
        }
        else 
        {
            arrayPrev[i].day=30;
            return;
        }

    }
}




main()
{
    int n=8;
    datetime date;
    datetime* array = new datetime[n];
    datetime* arrayPrev = new datetime[n];
    datetime* arrayCurrent = new datetime[n];
    in(array,n);
    in(arrayPrev,n);
    in(arrayCurrent,n);
    for(int i=0;i<n;i++)
    {
        cout<<endl<<"current"<<endl;
        out(array,i);
        cout<<endl<<"next"<<endl;
        nextdate(array,i);
        out(array,i);
        cout<<endl<<"prev"<<endl;
        prevdate(arrayPrev,i);
        out(arrayPrev,i);
     
    }
    arrayPrev=arrayCurrent;
    for(int i=0;i<n;i++)
    {
        if(arrayCurrent[i].day==1)
        {
            cout<<endl<<"dates for variant"<<endl;
            cout<<endl<<"current"<<endl;
            out(arrayCurrent,i);
            cout<<endl<<"prev"<<endl;
            prevdate(arrayPrev,i);
            out(arrayPrev,i);
        }
    }
    return 0;
}