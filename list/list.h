/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/
#ifndef _LIST_H_
#define _LIST_H_

typedef int RANK;  //秩

//列表节点类的模板(双向链表实现)
template <typename T>
class ListNode {
public:
	T data_;  //数据
	ListNode<T>* pred_;
	ListNode<T>* succ_;
	ListNode() {}
	ListNode(T e, ListNode<T>* p = NULL, ListNode<T>* s = NULL):data_(e), pred_(p), succ_(s) {}
	ListNode<T>* insertAsPred(T const& e);  //将数据e封装成节点插入当前节点的前驱
	ListNode<T>* insertAsSucc(T const& e);  //将数据e封装成节点插入当前节点的后继
};

//列表类模板(双向链表，拥有头节点，首节点，末节点，尾结点)
template <typename T>
class List{
public:
//构造函数
	List(); //默认构造函数，使用init初始化
	List(List<T> const& L);  //整体复制构造
	List(List<T> const& L, RANK r, int n);  //部分复制构造，位置r起的后n项
	List(ListNode<T>* p, int n);  //复制列表中自位置p起的n项
//析构函数
	~List();  //对头节点和尾节点的清理
//只读访问接口
	RANK size() const { return size_; }  //返回列表规模
	RANK empty() const {return 0 == size_; }  //判空
	T& operator[](RANK r) const ; //重载操作符[]，支持循秩访问
	ListNode<T>* first() const { return header_->succ_; }  //返回首节点
	ListNode<T>* last() const {return trailer_->pred_; }  //返回末节点
	bool valid(ListNode<T>* p) const { return p && (trailer_ != p) && (header_ != p);}  //判断位置p是否对外合法
	ListNode<T>* find(T const& e, int n, ListNode<T>* p) const;  //无序区间查找元素e
	ListNode<T>* find(T const& e) const { return find(e, size_, trailer_);}  //无序列表查找元素e
	ListNode<T>* search(T const& e, int n, ListNode<T>* p) const;  //有序区间查找元素e
	ListNode<T>* search(T const& e) const { return search(e, size_, trailer_);}	//有序列表查找元素e
	ListNode<T>* selectMax(ListNode<T>* p, int n);  //在p及其后继的n-1个元素中找出最大元素，返回位置
	ListNode<T>* selecaMax() const { return selectMax(header_, size_);}  //列表中最大元素的位置
//可写访问接口
	ListNode<T>* insertAsFirst(T const& e);  //插入作为头节点
	ListNode<T>* insertAsLast(T const& e);  //插入作为末节点
	ListNode<T>* insertAfter(ListNode<T>* p, T const& e);  //将e作为p的后继插入
	ListNode<T>* insertBefore(T const& e, ListNode<T>* p);  //将e作为p的前驱插入
	T remove(ListNode<T>* p);  //删除位置为p的节点
	void merge(List<T>& L) { merge(first(), size_, L, L.first(), L.size()); }  //全列表归并
	void sort(ListNode<T>* p, int n);  //列表区间排序
	void sort() { sort(first(), size_);}  //列表整体排序
	int deduplicate();  //无序去重
	int uniquify();  //有序去重
	void reverse();  //列表逆转
//遍历
	template <typename VST>  //操作器
	void traverse(VST& visit);  //遍历操作， 对所有元素执行visit操作
protected:
	void init();  //列表初始化
	int clear();  //清空所有节点
	void copyNode(ListNode<T>* p, int n);  //复制列表中自位置p起的n个节点
	void merge(ListNode<T>*& p, int, List<T> const&, ListNode<T>*, int);  //归并
	void mergeSort(ListNode<T>* p,int n);  //对p位置开始的n个节点归并排序
	void selectionSort(ListNode<T>* p,int n);  //对p位置开始的n个节点选择排序
	void insertionSort(ListNode<T>* p,int n);  //对p位置开始的n个节点插入排序
private:
	int size_;
	ListNode<T>* header_;
	ListNode<T>* trailer_;
};

#endif

