0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> //二叉树子树接入算法：将S当作节点x的右子树接入，S本身置空
0010 BinNodePosi(T) BinTree<T>::attachAsRC ( BinNodePosi(T) x, BinTree<T>* &S ) { //x->rc == NULL
0011    if ( x->rc = S->_root ) x->rc->parent = x; //接入
0012    _size += S->_size; updateHeightAbove ( x ); //更新全树规模与x所有祖先的高度
0013    S->_root = NULL; S->_size = 0; release ( S ); S = NULL; return x; //释放原树，返回接入位置
0014 } //attachAsLC()完全对称，在此省略；release()负责释放复杂结构，与算法无直接关系，具体实现详见代码包