# 步进马达项目
## 概述
本项目演示如何使用modular-2 控制一个2相 5线步进进电机的驱动。 
## 步进电机的驱动方式
市面上流行的步进电机2 相制步进电机。两相步进电机的接线方式可以分为
+ 4线双向（bipolar)方式,电机线圈的电流是双向的。所以需要使用H型驱动电路。比如ST 公司的L298或者TI的 DRV8825.
+ 5线/6线单向(unipolar)方式。 单向方式由中心抽头输入电压。其它4线的电流是单向的。 
## 使用的IO扩展板
- 4线双向：[M2_DIO-DRV8825](https://github.com/modular2/modular-2/blob/master/hardware/M2-RS485-DRV8825.md)
- 5线单向：[M2-RS485-DRV8803](https://github.com/modular2/modular-2/blob/master/hardware/M2-RS485-DRV8803.md)
## 接线图
## 步进电机技术背景
### 转速
步进电机转速为100到600转/分。

### 控制方式
 相步进电机具有4 种驱动方式  
- 1 Wave Drive 
- 2 Full Step Drive 
- 3 Half Step Drive（Mbed stepTest是这种模式） 
- 4 Microstepping 
### 角度精度
 市面上 2相步进电机一般每步是1.8度。旋转一圈需要360/1.8=200个步，如果是half step 模式，需要400个脉冲。
### 半角驱动脉冲序列
|  引线   |  1  |  2  |  3  |  4  |  5  |  6  | 7  |  8  |
|--------|-----|-----|-----|-----|-----|-----|----|------|
| 4 （B-)|  1  |  1  |     |     |     |     |    |  1   |
| 3（A-) |     |  1  |  1  |  1  |     |     |    |      |
| 2 （B）|     |     |     |  1  |  1  |  1  |    |      |
| 1（A） |     |     |     |     |     |  1  |  1  |  1  |  

## sMotor 类

构造函数 
----

<pre><code>
 sMotor(PinName A0, PinName A1, PinName A2, PinName A3,int stepsPerTurn,uint8_t polarMask); 
 </code></pre> 

 参数
-----

  +  A0,A1,A2,A3 分别为 A，B，A-，B- ，其中A，A-为一组。B，-B 为另一组。
  +  stepPerTurn 每转脉冲数
  + polarMask 极性选择
   - 0 极性不变，
   - 1 极性反向

控制函数
----

<pre><code>
void step(float degree, int speed);
</code></pre> 

参数
---
+ degree  角度
  + 大于零，为顺时针
  + 小于零，为逆时针
+ speed 转速，单位是 转/分钟







