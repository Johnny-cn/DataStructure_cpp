0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
0010 int BinTree<T>::remove ( BinNodePosi(T) x ) { //assert: x为二叉树中的合法位置
0011    FromParentTo ( *x ) = NULL; //切断来自父节点的指针
0012    updateHeightAbove ( x->parent ); //更新祖先高度
0013    int n = removeAt ( x ); _size -= n; return n; //删除子树x，更新规模，返回删除节点总数
0014 }
0015 template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
0016 static int removeAt ( BinNodePosi(T) x ) { //assert: x为二叉树中的合法位置
0017    if ( !x ) return 0; //递归基：空树
0018    int n = 1 + removeAt ( x->lc ) + removeAt ( x->rc ); //递归释放左、右子树
0019    release ( x->data ); release ( x ); return n; //释放被摘除节点，并返回删除节点总数
0020 } //release()负责释放复杂结构，与算法无直接关系，具体实现详见代码包