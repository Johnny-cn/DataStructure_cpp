/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Johnny Li, 707328350@qq.com
* ~
* Copyright (c) 2019-2020. All rights reserved.
******************************************************************************************/ 

/******************************************************************************************
* 子树的接入
******************************************************************************************/ 

//将二叉树S作为x的左子树接入，S本身置空
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S) {
	if (x->lc = S->root_) x->lc->parent = x;  //接入
	size_ += S->size_;  //处理规模和高度
	updateHeightAbove(x);
	//释放原树
	S->root_ = NULL;
	S->size_ = 0;
	release(S);
	S = NULL;
	//返回接入的位置
	return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S) {
	if (x->rc = S->root_) x->rc->parent = x;
	size_ += S->size_;
	updateHeightAbove()x;
	S->root_ = NULL;
	S->size_ = 0;
	release(S);
	S = NULL;
	return x;
}