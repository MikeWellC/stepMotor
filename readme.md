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
### 角度精度
 2 相步进电机旋转一圈需要200个步，每步是1.8度。
### 控制方式
 相步进电机具有4 种驱动方式： 
- 1 Wave Drive 
- 2 Full Step Drive 
- 3 Half Step Drive（Mbed stepTest是这种模式） 
- 4 Microstepping 
### 半角驱动脉冲序列
|| 1 | 2 | 3 | 4 | 5 | 6  |7 | 8 |
|---|---|---|---|---|---|---|---|---|
| 4 | 1 | 1 |   |   |   |   |   | 1 |
| 3 |   | 1 | 1 | 1 |   |   |   |   |
| 2 |   |   |   | 1 | 1 | 1 |   |   |
| 1 |   |   |   |   |   | 1 | 1 | 1 |





