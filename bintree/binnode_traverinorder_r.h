0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T, typename VST> //元素类型、操作器
0010 void travIn_R ( BinNodePosi(T) x, VST& visit ) { //二叉树中序遍历算法（递归版）
0011    if ( !x ) return;
0012    travIn_R ( x->lc, visit );
0013    visit ( x->data );
0014    travIn_R ( x->rc, visit );
0015 }