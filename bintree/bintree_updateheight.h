/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Johnny Li, 707328350@qq.com
* ~
* Copyright (c) 2019-2020. All rights reserved.
******************************************************************************************/ 

/******************************************************************************************
* 更新二叉树节点的高度
******************************************************************************************/ 

//更新节点x的高度
template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x) {
	return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

//更新节点x及其祖先的高度
template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) {
	while (NULL != x) {
		updateHeight(x);
		x = x->parent; 
	}
}