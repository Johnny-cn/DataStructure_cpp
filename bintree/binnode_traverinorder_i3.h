0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T, typename VST> //元素类型、操作器
0010 void travIn_I3 ( BinNodePosi(T) x, VST& visit ) { //二叉树中序遍历算法（迭代版#3，无需辅助栈）
0011    bool backtrack = false; //前一步是否刚从右子树回溯——省去栈，仅O(1)辅助空间
0012    while ( true )
0013       if ( !backtrack && HasLChild ( *x ) ) //若有左子树且不是刚刚回溯，则
0014          x = x->lc; //深入遍历左子树
0015       else { //否则——无左子树或刚刚回溯（相当于无左子树）
0016          visit ( x->data ); //访问该节点
0017          if ( HasRChild ( *x ) ) { //若其右子树非空，则
0018             x = x->rc; //深入右子树继续遍历
0019             backtrack = false; //并关闭回溯标志
0020          } else { //若右子树空，则
0021             if ( ! ( x = x->succ() ) ) break; //回溯（含抵达末节点时的退出返回）
0022             backtrack = true; //并设置回溯标志
0023          }
0024       }
0025 }