0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 //从当前节点出发，沿左分支不断深入，直至没有左分支的节点；沿途节点遇到后立即访问
0010 template <typename T, typename VST> //元素类型、操作器
0011 static void visitAlongVine ( BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S ) {
0012    while ( x ) {
0013       visit ( x->data ); //访问当前节点
0014       S.push ( x->rc ); //右孩子入栈暂存（可优化：通过判断，避免空的右孩子入栈）
0015       x = x->lc;  //沿左分支深入一层
0016    }
0017 }
0018 
0019 template <typename T, typename VST> //元素类型、操作器
0020 void travPre_I2 ( BinNodePosi(T) x, VST& visit ) { //二叉树先序遍历算法（迭代版#2）
0021    Stack<BinNodePosi(T)> S; //辅助栈
0022    while ( true ) {
0023       visitAlongVine ( x, visit, S ); //从当前节点出发，逐批访问
0024       if ( S.empty() ) break; //直到栈空
0025       x = S.pop(); //弹出下一批的起点
0026    }
0027 }