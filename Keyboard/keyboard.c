#include "keyboard.h"
#include "gpio.h"

keyboard_pin col[4]=
{
    {col_1_GPIO_Port,col_1_Pin},
    {col_2_GPIO_Port,col_2_Pin},
    {col_3_GPIO_Port,col_3_Pin},
    {col_4_GPIO_Port,col_4_Pin}
};

keyboard_pin row[4]=
{
    {row_1_GPIO_Port,row_1_Pin},
    {row_2_GPIO_Port,row_2_Pin},
    {row_3_GPIO_Port,row_3_Pin},
    {row_4_GPIO_Port,row_4_Pin},
};

int keyboard_scan()
{
    int temp=0;
    for(int i=0;i<4;i++)
    {
        HAL_GPIO_WritePin(col[i].Port,col[i].Pin,1);
        for(int j=0;j<4;j++)
        {
            if(HAL_GPIO_ReadPin(row[j].Port,row[j].Pin))
            temp=j*4+i+1;
        }
        HAL_GPIO_WritePin(col[i].Port,col[i].Pin,0);
    }
    return temp;
}