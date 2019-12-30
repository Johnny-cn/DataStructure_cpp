/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

#include "list.h"

//����������

//�б���ĳ�ʼ��
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

//�б��ڲ�������������λ��p���n��
template <typename T>
void List<T>::copyNode(ListNode < T > * p, int n) {
	init();
	while (n--) {
		insertAsLast(P->data_);  //����p��n��ڵ���Ϊĩ�ڵ����
		p = p->succ_;
	}
}

//Ĭ�ϵĹ���
template <typename T>
List<T>::List(){ init(); }  //������б�

//�����б�����λ��p���n��
template <typename T>
List<T>::List(ListNode<T> *p , int n) {
	copyNode(p, n)
}

//���帴�ƹ���
template <typename T>
List<T>::List(List<T> const& L) {
	copyNode(L.first(), L.size());
}

//���ָ��ƹ��죬λ��r��ĺ�n��
template <typename T>
List<T>::List(List<T> const& L, RANK r, int n) {
	ListNode<T>* p = L.first();
	while (0 < r--) p = p->succ_;
	copyNode(p, n)
}

//��������
template <typename T>
List<T>::~List() {
	clear();  //�������
	if (NULL != header_) delete header_;
	if (NULL != trailer_) delete trailer_;
}

//������e��װ�ɽڵ���뵱ǰ�ڵ��ǰ��
template <typename T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e) {
	ListNode<T>* x = new ListNode(e, pred_, this);  //�����½ڵ�,��ǰ�ڵ��ǰ��Ϊ�½ڵ��ǰ������ǰ�ڵ�Ϊ�½ڵ�ĺ��
	pred_->succ_ = x;  //��ǰ�ڵ��ǰ���ĺ��Ϊ�½ڵ�
	pred_ = x;         //��ǰ�ڵ��ǰ������Ϊ�½ڵ�
	return x;          //���������ɵĽڵ�
}

//������e��װ�ɽڵ���뵱ǰ�ڵ�ĺ��
template <typename T>
ListNode<T>* ListNode<T>:: insertAsSucc(T const& e) {
	ListNode<T>* x = new ListNode(e, this, succ_);
	succ_->pred_ = x;
	succ_ = x;
	return x;
}

//������Ϊͷ�ڵ�
template <typename T>
ListNode<T>* List<T>::insertAsFirst(T const& e) {
	size_++;
	return header_->insertAsSucc(e);
}

//������Ϊĩ�ڵ�
template <typename T>
ListNode<T>* List<T>::insertAsLast(T const& e) {
	size_++;
	return trailer_->insertAsPred(e);
}

//��e��Ϊp�ĺ�̲���
template <typename T>
ListNode<T>* List<T>::insertAfter(ListNode<T>* p, T const& e) {
	size_++;
	return p->insertAsSucc(e);
}

//��e��Ϊp��ǰ������
template <typename T>
ListNode<T>* List<T>::insertBefore(T const& e, ListNode<T>* p) {
	size_++;
	return p->insertAsPred(e);
}

//ɾ��λ��Ϊp�Ľڵ�
template <typename T>
T List<T>::remove(ListNode<T>* p) {
	T tmp = p->data;
	p->pred_->succ_ = p->succ_;
	p->succ_->pred_ = p->pred_;
	delete p;
	size_--;
	return tmp;
}

//������нڵ�
template <typename T>
int List<T>::clear() {
	int old_size = size_;
	while (0 < size_) {
		remove(header_->succ_);
	}
	return old_size;
}

//�����б�������ң���p(������β�ڵ�)��n����ǰ���в���Ԫ��e
template <typename T>
ListNode<T>* List<T>::find(T const& e, int n, ListNode<T>* p) const {
	while (0 < n--) {
		if (e == (p = p->pred_)->data_) return p;
	}
	return NULL;
}

//�����б��������Ԫ��e���Ҳ�����e��Ԫ��λ��
template <typename T>
ListNode<T>* List<T>::search(T const& e, int n, ListNode<T>* p) const {
	do {
		p = p->pred_;
		n--;
	} while (0 < n && e < p->data_);  //������������жϣ�ֱ��Խ����߲��ҵ���һ��������e��Ԫ�ء�
	return p;  //δ�ҵ�ʱ�����ص�λ�ÿ�����header
}

//��p�����̵�n��Ԫ�����ҳ����Ԫ�أ�����λ��
template <typename T>
ListNode<T>* List<T>::selectMax(ListNode<T>* p, int n) {
	ListNode<T>* max = p;
	while (0 < n-- && p != trailer_) {
		if ((p = p->succ_)->data_ < max->data_) max = p;
	}
	return max;
}
//�б���������
void List<T>::sort(ListNode<T>* p, int n) {

}

//�����б�ȥ�أ����б��������֣��Ѿ�ȷ�����ص�ǰ׺����Ҫ�ų��ĺ�׺��
//�ӵڶ���Ԫ�ؿ�ʼ��ǰ׺�в��ң��о�ɾ����û��ǰ׺+1
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

//�����б�ȥ��
template <typename T>
int List<T>::uniquify() {
	int old_size = size_;
	ListNode<T>* p = first();
	ListNode<T>* q = NULL;
	while (trailer_ != (q = p->succ_)) {  //qΪp�ĺ��
		if (p->data_ != q->data_) p = q;  //���߲���ͬ��p����
		else remove(q);                   //��ͬʱɾ��q
	}
	return old_size - size_;              //���ر�ɾ����Ԫ�ظ���
}

//�б���ת
template <typename T>
void List<T>::reverse() {
	if (size_ < 2) return ; //һ���ڵ㲻����ת
	for (ListNode<T>* p = header_; p; p = p->pred_) {
		swap(p->pred_; p->succ_);
	}
	swap(header_, trailer);
}

//�б���ת
template <typename T>
void reverse_1() {
	if (size_ < 2) return ; //һ���ڵ㲻����ת
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

//���б���ת
template <typename T>
void reverse_2() {
	ListNode<T>* new_head = NULL;  //�½ڵ��ʼΪNULL
	ListNode<T>* cur = header_;    //��ͷ�ڵ㿪ʼ��ת
	while (NULL != cur) {
		header_ = header_->succ_;  //ͷ�ڵ����
		cur->succ_ = new_head;     //�޸ĵ�ǰ�ڵ��ָ��
		new_head = cur;            //����ͷ�ڵ�
		cur = header_;             //����һ���ڵ������ת
	}
	return new_head;
}
//�鲢
template <typename T>

void List<T>::merge(ListNode<T>*& p, int, List<T> const&, ListNode<T>*, int) {

}
//��pλ�ÿ�ʼ��n���ڵ�鲢����
template <typename T>
void List<T>::mergeSort(ListNode<T>* p,int n) {

}
//��pλ�ÿ�ʼ��n���ڵ�ѡ������
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
//��pλ�ÿ�ʼ��n���ڵ��������
template <typename T>
void List<T>::insertionSort(ListNode<T>* p,int n) {
	for (int r = 0; r < n; r++) {
		insertAfter(search(p->data, r, p), p->data_);  //��p��ʼ��ǰr��Ԫ�����ҵ�������p->data��λ�ã�Ȼ��p->data���뵽���λ��
		p = p->succ_;
		remove(p->pred_);
	}
}

