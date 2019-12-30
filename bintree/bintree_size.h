0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> //统计二叉树子树规模
0010 int BinTree<T>::size ( BinNodePosi(T) x ) //assert: x为二叉树中的合法位置
0011 {  return x ? size ( x->lc ) + size ( x->RChild ) : 0;  }