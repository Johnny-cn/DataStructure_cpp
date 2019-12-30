0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> template <typename VST> //元素类型、操作器
0010 void BinNode<T>::travPre ( VST& visit ) { //二叉树先序遍历算法统一入口
0011    switch ( rand() % 3 ) { //此处暂随机选择以做测试，共三种选择
0012       case 1: travPre_I1 ( this, visit ); break; //迭代版#1
0013       case 2: travPre_I2 ( this, visit ); break; //迭代版#2
0014       default: travPre_R ( this, visit ); break; //递归版
0015    }
0016 }