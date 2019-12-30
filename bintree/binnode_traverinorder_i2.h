0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T, typename VST> //元素类型、操作器
0010 void travIn_I2 ( BinNodePosi(T) x, VST& visit ) { //二叉树中序遍历算法（迭代版#2）
0011    Stack<BinNodePosi(T)> S; //辅助栈
0012    while ( true )
0013       if ( x ) {
0014          S.push ( x ); //根节点进栈
0015          x = x->lc; //深入遍历左子树
0016       } else if ( !S.empty() ) {
0017          x = S.pop(); //尚未访问的最低祖先节点退栈
0018          visit ( x->data ); //访问该祖先节点
0019          x = x->rc; //遍历祖先的右子树
0020       } else
0021          break; //遍历完成
0022 }