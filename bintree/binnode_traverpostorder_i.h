0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> //在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
0010 static void gotoHLVFL ( Stack<BinNodePosi(T)>& S ) { //沿途所遇节点依次入栈
0011    while ( BinNodePosi(T) x = S.top() ) //自顶而下，反复检查当前节点（即栈顶）
0012       if ( HasLChild ( *x ) ) { //尽可能向左
0013          if ( HasRChild ( *x ) ) S.push ( x->rc ); //若有右孩子，优先入栈
0014          S.push ( x->lc ); //然后才转至左孩子
0015       } else //实不得已
0016          S.push ( x->rc ); //才向右
0017    S.pop(); //返回之前，弹出栈顶的空节点
0018 }
0019 
0020 template <typename T, typename VST>
0021 void travPost_I ( BinNodePosi(T) x, VST& visit ) { //二叉树的后序遍历（迭代版）
0022    Stack<BinNodePosi(T)> S; //辅助栈
0023    if ( x ) S.push ( x ); //根节点入栈
0024    while ( !S.empty() ) {
0025       if ( S.top() != x->parent ) //若栈顶非当前节点之父（则必为其右兄），此时需
0026          gotoHLVFL ( S ); //在以其右兄为根之子树中，找到HLVFL（相当于递归深入其中）
0027       x = S.pop(); visit ( x->data ); //弹出栈顶（即前一节点之后继），并访问之
0028    }
0029 }