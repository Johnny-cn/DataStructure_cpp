/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Johnny Li, 707328350@qq.com
* ~
* Copyright (c) 2019-2020. All rights reserved.
******************************************************************************************/ 
/******************************************************************************************
* 二叉树的中序遍历迭代版1，利用栈记录所有的左孩子，直到没有左孩子开始处理栈中的节点.
******************************************************************************************/ 
//处理以x为节点的树，将这棵树的根以及所有左子树存放到栈S中
template <typename T>
static void goAlongLeftBranch(BinNOdePosi<T> x, Stack<BinNOdePosi<T> &S>) {
	while (NULL != x) {
		S.push(x);
		x = x->lc;
	}
}
template <typename T, typename VST>
void BinTree<T>::travIn_I1(BinNOdePosi<T> x, VST& visit) {
	Stack<BinNOdePosi<T>> S;
	while (TRUE) {
		goAlongLeftBranch(x, S); //处理以x为节点的树，将这棵树的根以及所有左子树存放到栈S中
		if (S.empty) break;  //栈中所有的元素都访问完即可退出
		x = S.top(); S.pop(); //从栈顶弹出元素，即可开始访问
		visit(x->data);
		x = x->rc;  //处理它的右子树
	}
}