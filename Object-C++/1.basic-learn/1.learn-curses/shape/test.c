/*************************************************************************
	> File Name: test.c
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月26日 星期四 19时38分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
# include <stdio.h>
# include <math.h>
 
/*
* print_circle: 打印半径为r的圆
*@r: 圆的半径
*/
int print_circle( int r)
{
    /*每行打印两个点'*'
      point1_1: 第一个点上一行打印的位置，point1_2: 第一个点上上行打印的位置;
      point2_1: 第一个点上一行打印的位置，point2_1: 第一个点上上行打印的位置;
    */
    int point1_1 = -1, point1_2 = -1, point2_1 = -1, point2_2 = -1;
 
    /*一共有2r行*/
    for (int i = 0; i <= 2* r; i++){
        /*每行打印两个星'*'*/
        for(int j = 1; j <= 2 * 2 * r; j++){
            /*打印第一个星'*'*/
            if ( (int)sqrt( pow(r, 2) - pow(r -i, 2)) ==( r- j/2) 
                && (r- j/2) != point1_1 
                && (r- j/2) != point1_2){
                   printf("*");
                   point1_2 = point1_1;
                   point1_1 =  r- j/2;
                   j++;
            }/*打印第二个星'*'*/
            else if(((int)sqrt( pow(r, 2) - pow(r - i, 2)) == j/2 - r) 
                && (j/2 - r) != point2_1 
                && (j/2 - r) != point2_2){
                    printf("*");
                    point2_2 = point2_1;
                    point2_1 = j/2 - r;
                    j++;
            }
 
            else
                printf(" ");
        }
        printf("\n");
    }
 
    return 0;
}
 
int main()
{
    int r;
 
    while(1){
        printf("请输入半径: \n");
        scanf("%d", &r);
         print_circle(r);
    }
 
    return 0;
}

