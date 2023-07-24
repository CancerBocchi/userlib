## TI三相锁相环库的用法

### 1.abc_dq0_neg.h | abc_dq0_pos.h 三相转旋转坐标系的轴

首先定义结构体

![image-20230724100146107](C:\Users\CANCER_CMP\AppData\Roaming\Typora\typora-user-images\image-20230724100146107.png)

在初始化调用reset函数2

![image-20230724100214514](C:\Users\CANCER_CMP\AppData\Roaming\Typora\typora-user-images\image-20230724100214514.png)

在运行的时候输入三相的值和正余弦值（正余弦的值由锁相环得到）

![image-20230724100334706](C:\Users\CANCER_CMP\AppData\Roaming\Typora\typora-user-images\image-20230724100334706.png)

### 2.spll_3ph_ddsrf.h | spll_3ph_srf.h 三相锁相环使用方法

定义结构体

初始化函数调用（ddsrf中有两个滤波系数）

![image-20230724105303111](C:\Users\CANCER_CMP\AppData\Roaming\Typora\typora-user-images\image-20230724105303111.png)

![image-20230724105328965](C:\Users\CANCER_CMP\AppData\Roaming\Typora\typora-user-images\image-20230724105328965.png)

输入 posq，posd，negq，negd 四个值到 ddsrf 的文件中的函数中

![image-20230724103127465](C:\Users\CANCER_CMP\AppData\Roaming\Typora\typora-user-images\image-20230724103127465.png)

输入v_p_q到 srf 文件中的函数中

![image-20230724103052594](C:\Users\CANCER_CMP\AppData\Roaming\Typora\typora-user-images\image-20230724103052594.png)

最终输出的相位位于结构体的 `theta[1]` 中

## 测试锁相环的思路

#### 使用ADC采样三相电网电压与电流

#### 使用ABC-DQ轴的转换将电网电压和电流转换到dq轴，由于电网波形畸变的问题，使用 ddsrf 的库

