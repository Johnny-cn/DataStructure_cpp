0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> template <typename VST> //元素类型、操作器
0010 void BinNode<T>::travLevel ( VST& visit ) { //二叉树层次遍历算法
0011    Queue<BinNodePosi(T)> Q; //辅助队列
0012    Q.enqueue ( this ); //根节点入队
0013    while ( !Q.empty() ) { //在队列再次变空之前，反复迭代
0014       BinNodePosi(T) x = Q.dequeue(); visit ( x->data ); //取出队首节点并访问之
0015       if ( HasLChild ( *x ) ) Q.enqueue ( x->lc ); //左孩子入队
0016       if ( HasRChild ( *x ) ) Q.enqueue ( x->rc ); //右孩子入队
0017    }
0018 }