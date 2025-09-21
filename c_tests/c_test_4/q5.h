#include<stdio.h>
int check_leap(int y)
{
        if(y%100==0)
        {
                if(y%400==0)
                        return 1;
                else
                        return 0;
        }
        else
        {
                if(y%4==0)
                        return 1;
                else
                        return 0;
        }
}
