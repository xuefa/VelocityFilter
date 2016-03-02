//
//  cmdaccfilter.c
//  CmdAccFilter
//
//  Created by Allan on 14-1-23.
//  Copyright (c) 2014年 Allan. All rights reserved.
//

//#include "cmdaccfilter.h"
#include <stdio.h>

#define ALSIZE 10

int CmdAccFilter(int As, int *Av, int nNum)
{
    static int accArrList[ALSIZE] = {0};
    static int alFront = 0;
    static int alRear = ALSIZE - 1;
    static int alLen = 0;
    static int sum = 0;
    static int sum1 = 0;
    
    *Av = As;
    if(alLen == 0)          //the accArrList is empty
    {
        alRear = alFront;
        accArrList[alRear] = As;
        alLen ++;
        sum += accArrList[alRear];
        sum1 = 0;
        sum1 = accArrList[alFront];
        return 0;
    }
    if(alLen == ALSIZE)
    {
        sum -= accArrList[alFront];
		alRear = alFront;
        alFront = ( alFront + 1 ) % ALSIZE;
        accArrList[alRear] = As;
		sum += accArrList[alRear];
        if(nNum > ALSIZE)
            nNum = ALSIZE;
        int i = 0;
        sum1 = 0;
        for(; i < nNum; i++)
        {
            int idx = (alRear - i + ALSIZE) % ALSIZE;
            sum1 += accArrList[idx];        }
        *Av = sum1 / nNum;
        return 0;
    }
    alRear = ( alRear + 1 ) % ALSIZE;
    accArrList[alRear] = As;
	sum += accArrList[alRear];
	alLen ++;
    if(alLen < nNum)
    {
        int i = 0;
        sum1 = 0;
        for(; i < alLen; i++)
        {
            int idx = (alRear - i + ALSIZE) % ALSIZE;
            sum1 += accArrList[idx];        }
        *Av = sum1 / alLen;
    }
    else
    {
        int i = 0;
        sum1 = 0;        for(; i < nNum; i++)
        {
            int idx = (alRear - i + ALSIZE) % ALSIZE;
            sum1 += accArrList[idx];        }
        *Av = sum1 / nNum;
    }
    
    return 0;
}
