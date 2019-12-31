/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Johnny Li, 707328350@qq.com
* ~
* Copyright (c) 2019-2020. All rights reserved.
******************************************************************************************/ 
/******************************************************************************************
* 二叉树的层次遍历，也是一种BFS思想(利用队列记录当前操作节点的领接点)
******************************************************************************************/ 
template <typename T, typename VST>
void BinNode<T>::travLevel(VST& visit) {
	Queue<BinNodePosi<T>> Q;
	BinNodePosi<T> tmp = NULL;
	Q.enqueue(this);
	while (!Q.empty()) {
		tmp = Q,dequeue();
		visit(tmp->data);
		if (NULL != tmp->lc) Q.enqueue(tmp->lc);
		if (NULL != tmp->rc) Q.enqueue(tmp->rc);
	}
	
}