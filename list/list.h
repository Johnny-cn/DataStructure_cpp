/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/
#ifndef _LIST_H_
#define _LIST_H_

typedef int RANK;  //��

//�б�ڵ����ģ��(˫������ʵ��)
template <typename T>
class ListNode {
public:
	T data_;  //����
	ListNode<T>* pred_;
	ListNode<T>* succ_;
	ListNode() {}
	ListNode(T e, ListNode<T>* p = NULL, ListNode<T>* s = NULL):data_(e), pred_(p), succ_(s) {}
	ListNode<T>* insertAsPred(T const& e);  //������e��װ�ɽڵ���뵱ǰ�ڵ��ǰ��
	ListNode<T>* insertAsSucc(T const& e);  //������e��װ�ɽڵ���뵱ǰ�ڵ�ĺ��
};

//�б���ģ��(˫������ӵ��ͷ�ڵ㣬�׽ڵ㣬ĩ�ڵ㣬β���)
template <typename T>
class List{
public:
//���캯��
	List(); //Ĭ�Ϲ��캯����ʹ��init��ʼ��
	List(List<T> const& L);  //���帴�ƹ���
	List(List<T> const& L, RANK r, int n);  //���ָ��ƹ��죬λ��r��ĺ�n��
	List(ListNode<T>* p, int n);  //�����б�����λ��p���n��
//��������
	~List();  //��ͷ�ڵ��β�ڵ������
//ֻ�����ʽӿ�
	RANK size() const { return size_; }  //�����б��ģ
	RANK empty() const {return 0 == size_; }  //�п�
	T& operator[](RANK r) const ; //���ز�����[]��֧��ѭ�ȷ���
	ListNode<T>* first() const { return header_->succ_; }  //�����׽ڵ�
	ListNode<T>* last() const {return trailer_->pred_; }  //����ĩ�ڵ�
	bool valid(ListNode<T>* p) const { return p && (trailer_ != p) && (header_ != p);}  //�ж�λ��p�Ƿ����Ϸ�
	ListNode<T>* find(T const& e, int n, ListNode<T>* p) const;  //�����������Ԫ��e
	ListNode<T>* find(T const& e) const { return find(e, size_, trailer_);}  //�����б����Ԫ��e
	ListNode<T>* search(T const& e, int n, ListNode<T>* p) const;  //�����������Ԫ��e
	ListNode<T>* search(T const& e) const { return search(e, size_, trailer_);}	//�����б����Ԫ��e
	ListNode<T>* selectMax(ListNode<T>* p, int n);  //��p�����̵�n-1��Ԫ�����ҳ����Ԫ�أ�����λ��
	ListNode<T>* selecaMax() const { return selectMax(header_, size_);}  //�б������Ԫ�ص�λ��
//��д���ʽӿ�
	ListNode<T>* insertAsFirst(T const& e);  //������Ϊͷ�ڵ�
	ListNode<T>* insertAsLast(T const& e);  //������Ϊĩ�ڵ�
	ListNode<T>* insertAfter(ListNode<T>* p, T const& e);  //��e��Ϊp�ĺ�̲���
	ListNode<T>* insertBefore(T const& e, ListNode<T>* p);  //��e��Ϊp��ǰ������
	T remove(ListNode<T>* p);  //ɾ��λ��Ϊp�Ľڵ�
	void merge(List<T>& L) { merge(first(), size_, L, L.first(), L.size()); }  //ȫ�б�鲢
	void sort(ListNode<T>* p, int n);  //�б���������
	void sort() { sort(first(), size_);}  //�б���������
	int deduplicate();  //����ȥ��
	int uniquify();  //����ȥ��
	void reverse();  //�б���ת
//����
	template <typename VST>  //������
	void traverse(VST& visit);  //���������� ������Ԫ��ִ��visit����
protected:
	void init();  //�б��ʼ��
	int clear();  //������нڵ�
	void copyNode(ListNode<T>* p, int n);  //�����б�����λ��p���n���ڵ�
	void merge(ListNode<T>*& p, int, List<T> const&, ListNode<T>*, int);  //�鲢
	void mergeSort(ListNode<T>* p,int n);  //��pλ�ÿ�ʼ��n���ڵ�鲢����
	void selectionSort(ListNode<T>* p,int n);  //��pλ�ÿ�ʼ��n���ڵ�ѡ������
	void insertionSort(ListNode<T>* p,int n);  //��pλ�ÿ�ʼ��n���ڵ��������
private:
	int size_;
	ListNode<T>* header_;
	ListNode<T>* trailer_;
};

#endif

