0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> //在以v为根的（AVL、SPLAY、rbTree等）BST子树中查找关键码e
0010 static BinNodePosi(T) & searchIn ( BinNodePosi(T) & v, const T& e, BinNodePosi(T) & hot ) {
0011    if ( !v || ( e == v->data ) ) return v; //递归基：在节点v（或假想的通配节点）处命中
0012    hot = v; //一般情况：先记下当前节点，然后再
0013    return searchIn ( ( ( e < v->data ) ? v->lc : v->rc ), e, hot ); //深入一层，递归查找
0014 } //返回时，返回值指向命中节点（或假想的通配哨兵），hot指向其父亲（退化时为初始值NULL）