/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

//vector ģ����ӿ�ʵ��
#include "vector.h"

#include <iostream>
using namespace std;

//��������A[lo, hi)������Ԫ�أ���Ҫ�����ڹ���
template <typename T>
void Vector<T>::copyFrom(T const& A, RANK lo, RANK hi) {
	elem_ = new T[capacity_ = (hi - lo) << 1];  //����Ԫ�ؿռ�
	size_ = 0;  //��ʼ��������ģ
	while (lo < hi) {
		elem_[size++] = A[lo++];
	}
}

//��������
template <typename T>
void Vector<T>::expand() {
	if (size_ < DEFAULT_CAPACITY) return;  //δ��Աʱ��������

	if (capacity_ < DEFAULT_CAPACITY) {  //���õ���Ĭ������
		capacity_ = DEFAULT_CAPACITY;
	}

	T* old_elem = elem_;
	elem_ = new T[capacity <<= 1];  //������ԭ����2��
	for (int i = 0; i < size_; i++) {
		elem_[i] = old_elem[i];
	}
	delete []old_elem;  //ɾ��ԭ�ռ�
	return ;
}

//װ�����ӹ�Сʱ����
template <typename T>
void Vector<T>::shrink() {
	if (capacity_ < DEFAULT_CAPACITY << 1) return ;  //���ݺ󲻵õ���Ĭ������
	if (size_ < capacity_ >> 1) return ;  //����һ�����²�����

	T* old_elem = elem_;
	elem_ = new T[capacity >>= 1];  //�µ�������������
	for (int i = 0; i <size_; i++) {
		elem_[i] = old_elem[i];
	}
	delete []old_elem;

	return ;
}

//���ز�����[]
template <typename T>
T& Vector<T>::operator[] (RANK r){
	assert(0 <= r < size_);
	return elem_[r];
}

//����Ϊr��Ԫ�������޸�Ϊe
template <typename T>
void Vector<T>::put(RANK r, T const& e) {
	assert(0 <= r < size_);
	elem_[r] = e;
	return ;
}

//������Ϊr��Ԫ��
template <typename T>
T& Vector<T>::get(RANK r) {
	assert(0 <= r < size_)
	return elem_[r];
}

//ָ������Ϊr��λ�ò���Ԫ��e
template <typename T>
RANK Vector<T>::insert(RANK r, T const& e) {
	assert(0 <= r < size_);
	expand();  //��Ҫʱ����
	for (int i = size_; i > r; i--) {
		elem_[i] = elem_[i-1];
	}
	elem_[r] = e;
	size++;
	return r;
}
//Ĭ�ϲ���λ��ΪĩԪ��
template <typename T>
RANK Vector<T>::insert(T const& e) {
	return insert(size_, e);
}

//ɾ������[lo, hi)��Ԫ�أ����ر�ɾ��Ԫ�صĸ���
template <typename T>
int Vector<T>::remove(RANK lo, RANK hi) {
	assert(0 <= lo <= hi < size_);
	if (lo == hi) return ; //�˻������
	while (hi < size_) {  //[hi, size_)����������ǰ�ƶ�hi-lo����λ
		elem_[lo++] = elem_[hi++];
	}
	size_ = lo;  //���¹�ģ��ֱ�Ӷ���β��[lo,size_hi)����
	shrink();
	return hi - lo;
}
//ɾ����Ϊr��Ԫ��,���ر�ɾ��Ԫ�ص�����
template <typename T>
T Vector<T>::remove(RANK r) {
	T tmp = elem_[r];
	remove(r, r+1);
	return tmp;
}
//������������[lo, hi)�������һ��������e��Ԫ�أ����ظ�Ԫ�ص���
template <typename T>
RANK Vector<T>::search(T const& e, RANK lo, RANK hi) const {
	assert(0 <= lo <= hi < size_);
	return rand() % 2 ? binSearch(elem_, e, lo, hi):fibSearch(elem_, e, lo, hi);
}
//���������Ķ��ֲ���--�汾1
template <typename T>
RANK Vector<T>::binSearch(T* A, T const& e, RANK lo, RANK hi) {
	RANK mi = 0;
	while (lo < hi) {
		mi = (lo + hi) >> 1;
		if (e == A[mi]) return mi;
		else if (e < A[mi]) hi = mi;
		else lo = mi + 1;
	}
	return -1;  //δ�ҵ�����-1
}

//���������Ķ��ֲ���--�Ľ��汾A
//��������ʱ�临�Ӷȣ�������ǰ����
template <typename T>
RANK Vector<T>::binSearchA(T* A, T const& e, RANK lo, RANK hi) {
	RANK mi = 0;
	while (1 < hi - lo) {
		mi = (lo + hi) >> 1
		(e < A[mi]) ? hi = mi : lo = mi;
	}
	return e == A[lo] ? lo:-1;  //����λ�����ǲ�����e������ߣ� ���ܱ�֤���ص���λ�������Ԫ�ص�λ��
}

//���������Ķ��ֲ���--�Ľ��汾B
//��������ʱ�临�Ӷȣ�������ǰ����
//�����ǲ��Ҵ���e�ĵ�һ��Ԫ�أ�Ȼ�󷵻ص������Ԫ�ص�ǰ��һ��Ԫ��
template <typename T>
RANK Vector<T>::binSearchB(T* A, T const& e, RANK lo, RANK hi) {
	RANK mi = 0;
	while (lo < hi) {
		mi = (lo + hi) >> 1
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	return lo - 1;  //����λ�����ǲ�����e������ߣ� ���Ա�֤����Ԫ��������Ԫ��
}

//�����������ң� ���ҳɹ��������һ��Ԫ��e���ȣ� ʧ�ܷ���lo-1
template <typename T>
RANK Vector<T>::find(T const& e, RANK lo, RANK hi) const {
	while ((lo < hi--) && e != elem_[hi]);
	return hi;
}

//�������������ú����������
template <typename VST>
void Vector<T>::traverse(VST& visit) {
	RANK i = 0;
	while (i < size_) {
		visit(elem_[i]);
		i++;
	}
	return ;
}

//��������ȥ��
template <typename T>
int Vector<T>::deduplicate() {
	int old_size = size_;
	RANK i = 1; //�ӵڶ���Ԫ�ؿ�ʼ
	while (i < size_) {
		(find(elem_[i], 0, i) < 0) ? i++ : remove(i) ;  //��[0,i)�в���Ԫ��elem_[i],�ҵ��˾�ɾ����Ԫ��
	}

	return old_size - size_; //����ɾ�����ظ�Ԫ�ظ���
}

//��������ȥ��
template <typename T>
int Vector<T>::uniquify() {
	RANK i = 0;
	RANK j = 0;
	while (++j < size_) {
		if (elem_[i] != elem_[j]) {  //����ͬʱֱ�����Ƶ�elem_[i+1]
			elem_[++i] = elem_[j];
		}
	}
	size_ = ++i;  //���¹�ģ
	shrink();  //���ݴ���
	return j - i;
}

//��������[lo, hi)�������
template <typename T>
int Vector<T>::disorded(RANK lo, RANK hi) {
	int count = 0;
	while (++lo < hi) {
		if (elem_[lo] < elem_[lo - 1]) {
			count++;
		}
	}
	return count;
}

//��������[lo, hi)�����ֵ����
template <typename T>
RANK Vector<T>::max(RANK lo, RANK hi) {
	RANK max = lo;
	while (++lo < hi) {
		if (elem_[lo] < elem_[lo - 1]) {
			max = lo;
		}
	}
	return max;
}

//ð��ɨ�轻���� 
template <typename T>
int Vector<T>::bubble(RANK lo, RANK hi) {
	RANK last = lo;  //��¼���һ������Ե�λ�ã���ʼ��Ϊ[lo-1, lo]�� last֮������������������
	while (++lo < hi) {  //�����ң����ɨ��
		if (elem_[lo - 1] > elem_[lo]) {
			last = lo;  //�����������ʱ����last��λ��
			swap(elem_[lo - 1], elem_[lo]);  //��������ԣ�ʹ֮����
		}
	}
	return last;
}

//ð�������㷨
template <typename T>
int Vector<T>::bubbleSort(RANK lo, RANK hi) {
	while (lo < (hi = bubble(lo, hi)));  //hi = last��ֻ��Ҫ��[lo, last]֮���Ԫ��������Ϊ[last, size)֮���Ԫ�ض��������
}

//�鲢�㷨
//ͨ��lo,mi,hi��ԭ���������A[lo, hi)�ֳ���������B[lo, mi) �� ��������C[mi, hi)
template <typename T>
void Vector<T>::merge(RANK lo, RANK mi, RANK hi) {
	RANK i = 0, j = 0, k = 0; //A[i], B[j], C[k] 
	T* A = elem_ + lo;  //Ҫ�ϳɵ�����A[lo,hi)
	T* B = new T[mi - lo]; //������������B�Ŀռ�
	T* C = elem_ + mi;  //����Ҫ����������C��������ռ�
	RANK lb = mi - lo;  //��������B�Ĵ�С
	RANK lc = hi - mi;  //��������C�Ĵ�С
	while ((j<lb) || (k < lc)) {
		if ((j < lb) && (lc <= k || (B[j] <= C[k]))) A[i++] = B[j++];  //B ����Ԫ�أ��ң�C��û��Ԫ�� ���� C��Ԫ�ؽ�С��
		if ((k < lc) && (lb <= j || (C[k] < B[j]))) A[i++] = C[k++];  //C����Ԫ�أ��ң�B��û��Ԫ�� ���� C�е�Ԫ�ؽ�С��
	}
	delete []B;  //�ͷ������B�Ŀռ�
}

//�鲢����
//[lo,hi)
template <typename T>
void Vector<T>::mergeSort(RANK lo, RANK hi) {
	if ((hi - lo) < 2) return ;  //��Ԫ��������Ȼ����ע�����������ұ�������2��������Ԫ��
	RANK mi = (lo + hi) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

