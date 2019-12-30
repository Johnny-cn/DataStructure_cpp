0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 //通过zig旋转调整，将BST子树x拉伸成最右侧通路
0010 template <typename T> void stretchByZig ( BinNodePosi(T) & x ) {
0011    BinNodePosi(T) v = x;
0012    while ( x->lc ) x = x->lc;
0013    for ( ; v; v = v->rc ) {
0014       while ( v->lc )
0015          v = v->zig();
0016    }
0017 }