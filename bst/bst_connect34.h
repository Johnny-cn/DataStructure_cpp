0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 /******************************************************************************************
0010  * 按照“3 + 4”结构联接3个节点及其四棵子树，返回重组之后的局部子树根节点位置（即b）
0011  * 子树根节点与上层节点之间的双向联接，均须由上层调用者完成
0012  * 可用于AVL和RedBlack的局部平衡调整
0013  ******************************************************************************************/
0014 template <typename T> BinNodePosi(T) BST<T>::connect34 (
0015    BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
0016    BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3
0017 ) {
0018    a->lc = T0; if ( T0 ) T0->parent = a;
0019    a->rc = T1; if ( T1 ) T1->parent = a; updateHeight ( a );
0020    c->lc = T2; if ( T2 ) T2->parent = c;
0021    c->rc = T3; if ( T3 ) T3->parent = c; updateHeight ( c );
0022    b->lc = a; a->parent = b;
0023    b->rc = c; c->parent = b; updateHeight ( b );
0024    return b; //该子树新的根节点
0025 }