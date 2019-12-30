0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> int BinTree<T>::updateHeight ( BinNodePosi(T) x ) //更新节点x高度
0010 { return x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) ); } //具体规则，因树而异
0011 
0012 template <typename T> void BinTree<T>::updateHeightAbove ( BinNodePosi(T) x ) //更新高度
0013 { while ( x ) { updateHeight ( x ); x = x->parent; } } //从x出发，覆盖历代祖先。可优化