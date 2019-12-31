/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Johnny Li, 707328350@qq.com
* ~
* Copyright (c) 2019-2020. All rights reserved.
******************************************************************************************/ 

/******************************************************************************************
* 二叉树模板类
* 树种需要维护的数据与节点不同，数据为根、规模、和高度
******************************************************************************************/ 

#include "BinNode.h"  //引入二叉树节点类

//二叉树模板类
template <typename T>
class BinTree {
protected:
	int size_;  //规模
	BinNodePosi(T) root_;  //树根
	virtual int updateHeight(BinNodePosi(T) x);  //更新节点x的高度
	void updateHeightAbove(BinNodePosi(T) x);  //更新节点x及其祖先的高度
public:
	BinTree():size_(0), root_(NULL){}  //构造函数
	~BinTree() {  //析构函数
		if (0 < size_)
			remove(root_); 
	}
	
	int size() const { return size_;}  //规模
	bool empty() const {return !root_;}  //判空
	BinNodePosi(T) root() const {return root_;}  //树根
	BinNodePosi(T) insertAsRoot(T const& e);  //插入根节点
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);  //e作为x的左孩子插入
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);  //e作为x的右孩子插入
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &T);  //T作为x的左子树接入
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &T);  //T作为x的右子树接入
	int remove(BinNodePosi(T) x);  //删除以位置x处节点为根的子树，返回该子树原先的规模
	BinTree<T>* secede(BinNodePosi(T)* x);  //将子树x从当前树种摘除，并将其转换为一颗独立的子树
	//层次遍历
	template <typename VST>
	void travLevel(VST& visit) {
		if (NULL != root_)
			root_->travLevel(visit);
	}
	//先序遍历
	template <typename VST>
	void travPre(VST& visit) {
		if (NULL != root_)
			root_->travPre(visit);
	}
	//中序遍历
	template <typename VST>
	void travIn(VST& visit) {
		if (NULL != root_)
			root_->travIn(visit);
	}
	//后序遍历
	template <typename VST>
	void travPost(VST& visit) {
		if (NULL != root_)
			root_->travPost(visit);
	}
	//遍历器
	bool operator==(BinTree<T> const& t) {
		return root_ && t._root_ && (root_ == t.root_);
	}
};
