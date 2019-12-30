0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 /******************************************************************************************
0010  * BST节点旋转变换统一算法（3节点 + 4子树），返回调整之后局部子树根节点的位置
0011  * 注意：尽管子树根会正确指向上层节点（如果存在），但反向的联接须由上层函数完成
0012  ******************************************************************************************/
0013 template <typename T> BinNodePosi(T) BST<T>::rotateAt ( BinNodePosi(T) v ) { //v为非空孙辈节点
0014    BinNodePosi(T) p = v->parent; BinNodePosi(T) g = p->parent; //视v、p和g相对位置分四种情况
0015    if ( IsLChild ( *p ) ) /* zig */
0016       if ( IsLChild ( *v ) ) { /* zig-zig */
0017          p->parent = g->parent; //向上联接
0018          return connect34 ( v, p, g, v->lc, v->rc, p->rc, g->rc );
0019       } else { /* zig-zag */
0020          v->parent = g->parent; //向上联接
0021          return connect34 ( p, v, g, p->lc, v->lc, v->rc, g->rc );
0022       }
0023    else  /* zag */
0024       if ( IsRChild ( *v ) ) { /* zag-zag */
0025          p->parent = g->parent; //向上联接
0026          return connect34 ( g, p, v, g->lc, p->lc, v->lc, v->rc );
0027       } else { /* zag-zig */
0028          v->parent = g->parent; //向上联接
0029          return connect34 ( g, v, p, g->lc, v->lc, v->rc, p->rc );
0030       }
0031 }