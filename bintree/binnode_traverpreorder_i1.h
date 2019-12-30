0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T, typename VST> //元素类型、操作器
0010 void travPre_I1 ( BinNodePosi(T) x, VST& visit ) { //二叉树先序遍历算法（迭代版#1）
0011    Stack<BinNodePosi(T)> S; //辅助栈
0012    if ( x ) S.push ( x ); //根节点入栈
0013    while ( !S.empty() ) { //在栈变空之前反复循环
0014       x = S.pop(); visit ( x->data ); //弹出并访问当前节点，其非空孩子的入栈次序为先右后左
0015       if ( HasRChild ( *x ) ) S.push ( x->rc ); if ( HasLChild ( *x ) ) S.push ( x->lc );
0016    }
0017 }