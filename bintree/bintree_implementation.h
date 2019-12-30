0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 #include <iostream>
0010 using namespace std;
0011 
0012 /******************************************************************************************
0013  * 将binTree各方法的实现部分，简洁地引入binTree.h
0014  * 效果等同于将这些实现直接汇入binTree.h
0015  * 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
0016  ******************************************************************************************/
0017 #include "BinTree_updateHeight.h"
0018 #include "BinTree_insert.h"
0019 #include "BinTree_attach.h"
0020 #include "BinTree_remove.h"
0021 #include "BinTree_secede.h"