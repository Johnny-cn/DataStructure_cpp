0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 /******************************************************************************************
0010  * BST节点删除算法：删除位置x所指的节点（全局静态模板函数，适用于AVL、Splay、RedBlack等各种BST）
0011  * 目标x在此前经查找定位，并确认非NULL，故必删除成功；与searchIn不同，调用之前不必将hot置空
0012  * 返回值指向实际被删除节点的接替者，hot指向实际被删除节点的父亲——二者均有可能是NULL
0013  ******************************************************************************************/
0014 template <typename T>
0015 static BinNodePosi(T) removeAt ( BinNodePosi(T) & x, BinNodePosi(T) & hot ) {
0016    BinNodePosi(T) w = x; //实际被摘除的节点，初值同x
0017    BinNodePosi(T) succ = NULL; //实际被删除节点的接替者
0018    if ( !HasLChild ( *x ) ) //若*x的左子树为空，则可
0019       succ = x = x->rc; //直接将*x替换为其右子树
0020    else if ( !HasRChild ( *x ) ) //若右子树为空，则可
0021       succ = x = x->lc; //对称地处理——注意：此时succ != NULL
0022    else { //若左右子树均存在，则选择x的直接后继作为实际被摘除节点，为此需要
0023       w = w->succ(); //（在右子树中）找到*x的直接后继*w
0024       swap ( x->data, w->data ); //交换*x和*w的数据元素
0025       BinNodePosi(T) u = w->parent;
0026       ( ( u == x ) ? u->rc : u->lc ) = succ = w->rc; //隔离节点*w
0027    }
0028    hot = w->parent; //记录实际被删除节点的父亲
0029    if ( succ ) succ->parent = hot; //并将被删除节点的接替者与hot相联
0030    release ( w->data ); release ( w ); return succ; //释放被摘除节点，返回接替者
0031 } //release()负责释放复杂结构，与算法无直接关系，具体实现详见代码包