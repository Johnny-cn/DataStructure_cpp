0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> BinNodePosi(T) BinNode<T>::zig() { //顺时针旋转
0010    BinNodePosi(T) lChild = lc;
0011    lChild->parent = this->parent;
0012    if ( lChild->parent )
0013       ( ( this == lChild->parent->rc ) ? lChild->parent->rc : lChild->parent->lc ) = lChild;
0014    lc = lChild->rc; if ( lc ) lc->parent = this;
0015    lChild->rc = this; this->parent = lChild;
0016 // update heights ()
0017    height = 1 + max ( stature ( lc ), stature ( rc ) );
0018    lChild->height = 1 + max ( stature ( lChild->lc ), stature ( lChild->rc ) );
0019    for ( BinNodePosi(T) x = lChild->parent; x; x = x->parent )
0020       if ( HeightUpdated( *x ) )
0021          break;
0022       else
0023          x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) );
0024    return lChild;
0025 }