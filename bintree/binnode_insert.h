
0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC ( T const& e )
0010 { return lc = new BinNode ( e, this ); } //将e作为当前节点的左孩子插入二叉树
0011 
0012 template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC ( T const& e )
0013 { return rc = new BinNode ( e, this ); } //将e作为当前节点的右孩子插入二叉树