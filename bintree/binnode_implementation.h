0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 /******************************************************************************************
0010  * 将BinNode各方法的实现部分，简洁地引入BinNode.h
0011  * 效果等同于将这些实现直接汇入BinNode.h
0012  * 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
0013  ******************************************************************************************/
0014 #include "BinNode_macro.h"
0015 #include "BinNode_size.h" //后代数目
0016 #include "BinNode_insert.h" //插入
0017 #include "BinNode_succ.h" //取节点后继
0018 #include "BinNode_travPreorder.h" //先序遍历
0019 #include "BinNode_travInorder.h" //中序遍历
0020 #include "BinNode_travPostorder.h" //后序遍历
0021 #include "BinNode_travLevel.h" //层次遍历
0022 #include "BinNode_zig.h" //顺时针旋转
0023 #include "BinNode_zag.h" //逆时针旋转
0024 #include "BinNode_stretchByZig.h"
0025 #include "BinNode_stretchByZag.h"