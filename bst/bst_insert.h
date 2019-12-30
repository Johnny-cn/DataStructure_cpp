0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> BinNodePosi(T) BST<T>::insert ( const T& e ) { //将关键码e插入BST树中
0010    BinNodePosi(T) & x = search ( e ); if ( x ) return x; //确认目标不存在（留意对_hot的设置）
0011    x = new BinNode<T> ( e, _hot ); //创建新节点x：以e为关键码，以_hot为父
0012    _size++; //更新全树规模
0013    updateHeightAbove ( x ); //更新x及其历代祖先的高度
0014    return x; //新插入的节点，必为叶子
0015 } //无论e是否存在于原树中，返回时总有x->data == e