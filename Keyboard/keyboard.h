#ifndef __KEYBOARD__
#define __KEYBOARD__

#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 
 * 采取行列扫描的方式
 * 默认扫描4*4的矩阵 如需更改,
 * 请更改.c中的for()和结构体数组的内容的数量
 * 还有键盘标号的计算公式（j*行数+列数+1）
 * 请把行命名为col_x 列命名为row_x
 * keyboard_scan()函数返回的是键盘标号
 * 使用if or switch来控制键盘的每一个按键
 * 行为input 列为output 且行下拉
 */
// switch())
// {
// case :1
//     break;
// case :2
//     break;
// case :3
//     break;
// case :4
//     break;
// case :5
//     break;
// case :6
//     break;
// case :7
//     break;
// case :8
//     break;
// case :9
//     break;
// case :10
//     break;
// case :11
//     break;
// case :12
//     break;
// case :13
//     break;
// case :14
//     break;
// case :15
//     break;
// case :16
//     break;
// case :
//     break;
// case :
//     break;
// case :
//     break;
// case :
//     break;
// case :
//     break;
// }

typedef struct KB
{
    GPIO_TypeDef* Port;
    uint32_t Pin;

}keyboard_pin;


int keyboard_scan();

#ifdef __cplusplus
}
#endif


#endif