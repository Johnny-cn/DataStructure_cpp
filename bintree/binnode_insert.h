/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Johnny Li, 707328350@qq.com
* ~
* Copyright (c) 2019-2020. All rights reserved.
******************************************************************************************/
/******************************************************************************************
* 二叉树节点的插入操作
******************************************************************************************/

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const& e) {
	return lc = new BinNode(e, this);  //以传入数值e，父节点为当前节点创建新节点，并赋值给当前节点的左孩子。
}

template <typename T>
BinNodePosi(T) BinNodePosi(T)::insertAsRC(T const& e) {
	return rc = new BinNode(e, this);
}
