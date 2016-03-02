//
//  main.c
//  CmdAccFilter
//
//  Created by Allan on 14-1-23.
//  Copyright (c) 2014年 Allan. All rights reserved.
//

#include "cmdaccfilter.h"
#include <stdio.h>

int main(int argc, const char * argv[])
{

    // insert code here...
    int as = 0;
    int accAverage = 0;
    int num = 8;
    while(1)
    {
        printf("Input: ");
        scanf("%d", &as);
        CmdAccFilter(as, &accAverage, num);
        printf("Avr = %d\n",accAverage);
    }
    printf("Hello, World!\n");
    return 0;
}

