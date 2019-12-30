/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

#include "list.h"

//构造与析构

//列表类的初始化
template <typename T>
void List<T>::init() {
	header_ = new ListNode<T>;
	trailer_ = new ListNode<T>;
	header_->succ = trailer_;
	header_->pred = NULL;
	trailer->succ = NULL;
	trailer->pred = header_;
	size_ = 0;
}

//列表内部方法，复制自位置p起的n项
template <typename T>
void List<T>::copyNode(ListNode < T > * p, int n) {
	init();
	while (n--) {
		insertAsLast(P->data_);  //将自p的n项节点作为末节点插入
		p = p->succ_;
	}
}

//默认的构造
template <typename T>
List<T>::List(){ init(); }  //构造空列表

//复制列表中自位置p起的n项
template <typename T>
List<T>::List(ListNode<T> *p , int n) {
	copyNode(p, n)
}

//整体复制构造
template <typename T>
List<T>::List(List<T> const& L) {
	copyNode(L.first(), L.size());
}

//部分复制构造，位置r起的后n项
template <typename T>
List<T>::List(List<T> const& L, RANK r, int n) {
	ListNode<T>* p = L.first();
	while (0 < r--) p = p->succ_;
	copyNode(p, n)
}

//链表析构
template <typename T>
List<T>::~List() {
	clear();  //清空链表
	if (NULL != header_) delete header_;
	if (NULL != trailer_) delete trailer_;
}

//将数据e封装成节点插入当前节点的前驱
template <typename T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e) {
	ListNode<T>* x = new ListNode(e, pred_, this);  //创建新节点,当前节点的前驱为新节点的前驱，当前节点为新节点的后继
	pred_->succ_ = x;  //当前节点的前驱的后继为新节点
	pred_ = x;         //当前节点的前驱更新为新节点
	return x;          //返回新生成的节点
}

//将数据e封装成节点插入当前节点的后继
template <typename T>
ListNode<T>* ListNode<T>:: insertAsSucc(T const& e) {
	ListNode<T>* x = new ListNode(e, this, succ_);
	succ_->pred_ = x;
	succ_ = x;
	return x;
}

//插入作为头节点
template <typename T>
ListNode<T>* List<T>::insertAsFirst(T const& e) {
	size_++;
	return header_->insertAsSucc(e);
}

//插入作为末节点
template <typename T>
ListNode<T>* List<T>::insertAsLast(T const& e) {
	size_++;
	return trailer_->insertAsPred(e);
}

//将e作为p的后继插入
template <typename T>
ListNode<T>* List<T>::insertAfter(ListNode<T>* p, T const& e) {
	size_++;
	return p->insertAsSucc(e);
}

//将e作为p的前驱插入
template <typename T>
ListNode<T>* List<T>::insertBefore(T const& e, ListNode<T>* p) {
	size_++;
	return p->insertAsPred(e);
}

//删除位置为p的节点
template <typename T>
T List<T>::remove(ListNode<T>* p) {
	T tmp = p->data;
	p->pred_->succ_ = p->succ_;
	p->succ_->pred_ = p->pred_;
	delete p;
	size_--;
	return tmp;
}

//清空所有节点
template <typename T>
int List<T>::clear() {
	int old_size = size_;
	while (0 < size_) {
		remove(header_->succ_);
	}
	return old_size;
}

//无序列表区间查找，在p(可以是尾节点)的n个真前驱中查找元素e
template <typename T>
ListNode<T>* List<T>::find(T const& e, int n, ListNode<T>* p) const {
	while (0 < n--) {
		if (e == (p = p->pred_)->data_) return p;
	}
	return NULL;
}

//有序列表区间查找元素e查找不大于e的元素位置
template <typename T>
ListNode<T>* List<T>::search(T const& e, int n, ListNode<T>* p) const {
	do {
		p = p->pred_;
		n--;
	} while (0 < n && e < p->data_);  //从右向左逐个判断，直到越界或者查找到第一个不大于e的元素。
	return p;  //未找到时，返回的位置可能是header
}

//在p及其后继的n个元素中找出最大元素，返回位置
template <typename T>
ListNode<T>* List<T>::selectMax(ListNode<T>* p, int n) {
	ListNode<T>* max = p;
	while (0 < n-- && p != trailer_) {
		if ((p = p->succ_)->data_ < max->data_) max = p;
	}
	return max;
}
//列表区间排序
void List<T>::sort(ListNode<T>* p, int n) {

}

//无序列表去重，将列表看做两部分，已经确认无重的前缀和需要排除的后缀。
//从第二个元素开始在前缀中查找，有就删除。没有前缀+1
template <typename T>
int List<T>::deduplicate() {
	int old_size = size_;
	ListNode<T>* p = first();
	ListNode<T>* q = NULL;
	for (RANK r = 0; p != trailer_; p = p->succ_, q = find(p->data_, r, q)) {
		(NULL != q) ? remove(q):r++;
	}
	return old_size - size_;
}

//有序列表去重
template <typename T>
int List<T>::uniquify() {
	int old_size = size_;
	ListNode<T>* p = first();
	ListNode<T>* q = NULL;
	while (trailer_ != (q = p->succ_)) {  //q为p的后继
		if (p->data_ != q->data_) p = q;  //二者不相同是p后移
		else remove(q);                   //相同时删除q
	}
	return old_size - size_;              //返回被删除的元素个数
}

//列表逆转
template <typename T>
void List<T>::reverse() {
	if (size_ < 2) return ; //一个节点不能逆转
	for (ListNode<T>* p = header_; p; p = p->pred_) {
		swap(p->pred_; p->succ_);
	}
	swap(header_, trailer);
}

//列表逆转
template <typename T>
void reverse_1() {
	if (size_ < 2) return ; //一个节点不能逆转
	ListNode<T>* p; 
	ListNode<T>* q;
	for (p = header_, q = p->succ_; p != trailer_; p = q, q = p->succ_) {
		p->pred_ = q;
	}
	trailer_->pred_ = NULL;
	for (p = header_, q = p->pred_; p != trailer_; p = q; q = p->pred_) {
		p ->succ_ = q;
	}
	header_->succ_ = NULL;
	swap(header_, trailer_);
}

//单列表逆转
template <typename T>
void reverse_2() {
	ListNode<T>* new_head = NULL;  //新节点初始为NULL
	ListNode<T>* cur = header_;    //从头节点开始逆转
	while (NULL != cur) {
		header_ = header_->succ_;  //头节点后移
		cur->succ_ = new_head;     //修改当前节点的指向
		new_head = cur;            //更新头节点
		cur = header_;             //对下一个节点进行逆转
	}
	return new_head;
}
//归并
template <typename T>

void List<T>::merge(ListNode<T>*& p, int, List<T> const&, ListNode<T>*, int) {

}
//对p位置开始的n个节点归并排序
template <typename T>
void List<T>::mergeSort(ListNode<T>* p,int n) {

}
//对p位置开始的n个节点选择排序
template <typename T>
void List<T>::selectionSort(ListNode<T>* p,int n) {
	ListNode<T>* head = p->pred_;
	ListNode<T>* tail = p;
	ListNode<T>* max = NULL;
	for (int i = 0; i < n; i++) tail = tail->succ_;
	while (1 < n--) {
		max = selectMax(head->succ_, n);
		insertBefore(remove(max), tail);
		tail = tai->pred;
	}
}
//对p位置开始的n个节点插入排序
template <typename T>
void List<T>::insertionSort(ListNode<T>* p,int n) {
	for (int r = 0; r < n; r++) {
		insertAfter(search(p->data, r, p), p->data_);  //从p开始的前r个元素中找到不大于p->data的位置，然后将p->data插入到这个位置
		p = p->succ_;
		remove(p->pred_);
	}
}

