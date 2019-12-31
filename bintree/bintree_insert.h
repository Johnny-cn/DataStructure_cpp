/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Johnny Li, 707328350@qq.com
* ~
* Copyright (c) 2019-2020. All rights reserved.
******************************************************************************************/ 

/******************************************************************************************
* 二叉树的节点插入，与二叉树节点插入的区别在与需要处理树的规模和高度
******************************************************************************************/ 
template <typenmae T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e) {
	size_ = 1;
	return root_ = new BinNode(e);  //将e封装为新节点作为树的根节点插入空的二叉树中
}
//将e封装为新节点作为x的左孩子插入
template<typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e) {
	size_++;  
	x->insertAsLC(e);  
	updateHeightAbove(x);
	return x->lc;
}

//将e封装为新节点作为x的右孩子插入
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e) {
	size++;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rc;
}