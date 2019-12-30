0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 //通过zag旋转调整，将BST子树x拉伸成最左侧通路
0010 template <typename T> void stretchByZag ( BinNodePosi(T) & x ) {
0011    BinNodePosi(T) p = x; while ( p->rc ) p = p->rc; //最大节点，必是子树最终的根
0012    while ( x->lc ) x = x->lc; //转至初始最左侧通路的末端
0013    for ( ; x != p; x = x->parent ) { //若x右子树已空，则上升一层
0014       while ( x->rc ) //否则，反复地
0015          x->zag(); //以x为轴做zag旋转
0016    } //直到抵达子树的根
0017 }