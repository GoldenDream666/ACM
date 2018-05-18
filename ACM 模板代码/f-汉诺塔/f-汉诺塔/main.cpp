//
//  main.cpp
//  f-汉诺塔
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  汉诺塔
 *  一号柱有n个盘子,叫做源柱.移往3号柱,叫做目的柱.2号柱叫做中间柱. 
 *  全部移往3号柱要f(n)=(2^n)-1次.
 *  最大盘n号盘在整个移动过程中只移动一次,n-1号移动2次,i号盘移动2^(n-i)次.
 *  1号盘移动次数最多,每2次移动一次.
 *  第2k+1次移动的是1号盘,且是第k+1次移动1号盘.第4k+2次移动的是2号盘,且是第k+1次移动2号盘.
 *  第(2^s)k+2^(s-1)移动的是s号盘,这时s号盘已被移动了k+1次.每2^s次就有一次是移动s号盘.
 *  第一次移动s号盘是在第2^(s-1)次.
 *  第二次移动s号盘是在第2^s+2^(s-1)次.
 *  ......
 *  第k+1次移动s号盘是在第k*2^s+2^(s-1)次.1--2--3--1叫做顺时针方向,1--3--2--1叫做逆时针方向.
 *  最大盘n号盘只移动一次:1--3,它是逆时针移动.
 *  n-1移动2次:1--2--3,是顺时针移动.
 *  如果n和k奇偶性相同,则k号盘按逆时针移动,否则顺时针. 
 */
int main()
{
    int i, k;
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        int n, l;
        __int64_t m, j;
        __int64_t s, t;
        scanf("%d%lld", &n, &m);
        s = 1;
        t = 2;
        for (l = 1; l <= n; l++)
        {
            if (m % t == s)
            {
                break;
            }
            s = t;
            t *= 2;
        }
        printf("%d ", l);
        j = m / t;
        if (n % 2 == l % 2)
        {   //  逆时针
            if ((j + 1) % 3 == 0)
            {
                printf("2 1\n");
            }
            if ((j + 1) % 3 == 1)
            {
                printf("1 3\n");
            }
            if ((j + 1) % 3 == 2)
            {
                printf("3 2\n");
            }
        }
        else
        {   //  逆时针
            if ((j + 1) % 3 == 0)
            {
                printf("3 1\n");
            }
            if ((j + 1) % 3 == 1)
            {
                printf("1 2\n");
            }
            if ((j + 1) % 3 == 2)
            {
                printf("2 3\n");
            }
        }
    }
    return 0;
}