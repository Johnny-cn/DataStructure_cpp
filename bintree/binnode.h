/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Johnny Li, 707328350@qq.com
 * ~
 * Copyright (c) 2019-2020. All rights reserved.
 ******************************************************************************************/
 /******************************************************************************************
 * 定义二叉树节点模板类，为简化描述，采用结构体封装节点
 ******************************************************************************************/
 
#define BinNodePosi(T) BinNode<T>*  //节点位置
#define stature(p) ((p) ? (p)->height : -1 ) //节点高度（与空树高度为-1的约定统一）

typedef enum {RB_RED, RB_BLACK} RBColor;  //节点颜色

//二叉树节点模板类
template <typename T>
struct BinNode {
//成员
	T data;
	BinNodePosi(T) parent;  //父节点
	BinNodePosi(T) lc;  //左孩子
	BinNodePosi(T) rc;  //右孩子
	int height;  //高度（通用）
	int npl;  //左式堆
	RBColor color;  //颜色
//构造函数
	BinNode():parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 0, RBColor c = RB_RED)
	: data (e), parent(p), lc(lc), rc(rc),height(h), npl(l), color(c){}
//操作接口
	int size();  //统计当前节点后代总数，即以当前节点为根的树的规模
	BinNodePosi(T) insertAsLC(T const& );  //作为当前节点的左孩子插入新节点
	BinNodePosi(T) insertAsRC(T const& );  //作为当前节点的右孩子插入新节点
	BinNodePosi(T) succ();  //返回当前节点的直接后继
	BinNodePosi(T) prec();  //返回当前节点的直接前驱
	template <typename VST> 
	void travLevel(VST& );  //子树层次遍历
	template<typename VST>  
	void travPre(VST& );  //子树先序遍历
	template <typename VST>
	void trevIn(VST& );  //子树中序遍历
	template <typename VST>
	void travPost(VST& );  //子树后序遍历
//比较器、判断器
	bool operator<(BinNode const& bn) {
		return data < bn.data;
	}
	bool operator==(BinNode const& bn) {
		return data == bn.data;
	}
};

