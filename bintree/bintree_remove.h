/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Johnny Li, 707328350@qq.com
* ~
* Copyright (c) 2019-2020. All rights reserved.
******************************************************************************************/ 

/******************************************************************************************
* 二叉树中子树的删除
******************************************************************************************/ 


//删除二叉树中中位置x处的节点及其后代，返回被删除节点的数值
template <typename T>
static int removeat(BinNodePosi(T) x) {
	if (NULL == x)
		return 0;
	int n = 1 + removeat(x->lc) + removeat(x->rc);
	release(x->data);
	release(x);  //释放被摘除的节点
	return n;  //返回被删除节点的总数
}
//删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x) {
		FromParentTo(*x) = NULL;  //切断来自父节点的指针，让父节点失去该节点
		updateHeightAbove(x->parent);  //更新祖先高度
		int n = removeAt(x);
		size_ -= n;
		return n;
}