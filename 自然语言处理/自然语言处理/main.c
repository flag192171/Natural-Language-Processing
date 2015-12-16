//
//  main.c
//  自然语言处理
//
//  Created by 李子晨 on 15/12/15.
//  Copyright © 2015年 李子晨. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include "deal.h"
int main()
{
    char Num[6][6];
    int result;
    while((result = judge(Num, input_asg(Num)))) {
        output(result);
    }
    return 0;
}

