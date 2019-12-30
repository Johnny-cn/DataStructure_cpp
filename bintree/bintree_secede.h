0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> //二叉树子树分离算法：将子树x从当前树中摘除，将其封装为一棵独立子树返回
0010 BinTree<T>* BinTree<T>::secede ( BinNodePosi(T) x ) { //assert: x为二叉树中的合法位置
0011    FromParentTo ( *x ) = NULL; //切断来自父节点的指针
0012    updateHeightAbove ( x->parent ); //更新原树中所有祖先的高度
0013    BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //新树以x为根
0014    S->_size = x->size(); _size -= S->_size; return S; //更新规模，返回分离出来的子树
0015 }