0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 #define EQUAL(e, v)  (!(v) || (e) == (v)->data) //节点v（或假想的通配哨兵）的关键码等于e
0010 template <typename T> //在以v为根的（AVL、SPLAY、rbTree等）BST子树中查找关键码e
0011 static BinNodePosi(T) & searchIn ( BinNodePosi(T) & v, const T& e, BinNodePosi(T) & hot ) {
0012    if ( EQUAL ( e, v ) ) return v; hot = v; //退化情况：在子树根节点v处命中
0013    while ( 1 ) { //一般地，反复不断地
0014       BinNodePosi(T) & c = ( e < hot->data ) ? hot->lc : hot->rc; //确定深入方向
0015       if ( EQUAL ( e, c ) ) return c; hot = c; //命中返回，或者深入一层
0016    } //hot始终指向最后一个失败节点
0017 } //返回时，返回值指向命中节点（或假想的通配哨兵），hot指向其父亲（退化时为初始值NULL）