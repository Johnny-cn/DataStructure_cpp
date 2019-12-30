0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T, typename VST> //元素类型、操作器
0010 void travIn_I4 ( BinNodePosi(T) x, VST& visit ) { //二叉树中序遍历（迭代版#4，无需栈或标志位）
0011    while ( true )
0012       if ( HasLChild ( *x ) ) //若有左子树，则
0013          x = x->lc; //深入遍历左子树
0014       else { //否则
0015          visit ( x->data ); //访问当前节点，并
0016          while ( !HasRChild ( *x ) ) //不断地在无右分支处
0017             if ( ! ( x = x->succ() ) ) return; //回溯至直接后继（在没有后继的末节点处，直接退出）
0018             else visit ( x->data ); //访问新的当前节点
0019          x = x->rc; //（直至有右分支处）转向非空的右子树
0020       }
0021 }