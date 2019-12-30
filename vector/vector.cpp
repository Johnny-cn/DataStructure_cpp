/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

//vector 模板类接口实现
#include "vector.h"

#include <iostream>
using namespace std;

//拷贝数组A[lo, hi)的区间元素，主要是用于构造
template <typename T>
void Vector<T>::copyFrom(T const& A, RANK lo, RANK hi) {
	elem_ = new T[capacity_ = (hi - lo) << 1];  //申请元素空间
	size_ = 0;  //初始化向量规模
	while (lo < hi) {
		elem_[size++] = A[lo++];
	}
}

//向量扩容
template <typename T>
void Vector<T>::expand() {
	if (size_ < DEFAULT_CAPACITY) return;  //未满员时不必扩容

	if (capacity_ < DEFAULT_CAPACITY) {  //不得低于默认容量
		capacity_ = DEFAULT_CAPACITY;
	}

	T* old_elem = elem_;
	elem_ = new T[capacity <<= 1];  //扩大完原来的2倍
	for (int i = 0; i < size_; i++) {
		elem_[i] = old_elem[i];
	}
	delete []old_elem;  //删除原空间
	return ;
}

//装填因子过小时缩容
template <typename T>
void Vector<T>::shrink() {
	if (capacity_ < DEFAULT_CAPACITY << 1) return ;  //缩容后不得低于默认容量
	if (size_ < capacity_ >> 1) return ;  //至少一半以下才缩容

	T* old_elem = elem_;
	elem_ = new T[capacity >>= 1];  //新的向量容量减半
	for (int i = 0; i <size_; i++) {
		elem_[i] = old_elem[i];
	}
	delete []old_elem;

	return ;
}

//重载操作符[]
template <typename T>
T& Vector<T>::operator[] (RANK r){
	assert(0 <= r < size_);
	return elem_[r];
}

//将秩为r的元素数据修改为e
template <typename T>
void Vector<T>::put(RANK r, T const& e) {
	assert(0 <= r < size_);
	elem_[r] = e;
	return ;
}

//返回秩为r的元素
template <typename T>
T& Vector<T>::get(RANK r) {
	assert(0 <= r < size_)
	return elem_[r];
}

//指定在秩为r的位置插入元素e
template <typename T>
RANK Vector<T>::insert(RANK r, T const& e) {
	assert(0 <= r < size_);
	expand();  //必要时扩容
	for (int i = size_; i > r; i--) {
		elem_[i] = elem_[i-1];
	}
	elem_[r] = e;
	size++;
	return r;
}
//默认插入位置为末元素
template <typename T>
RANK Vector<T>::insert(T const& e) {
	return insert(size_, e);
}

//删除区间[lo, hi)的元素，返回被删除元素的个数
template <typename T>
int Vector<T>::remove(RANK lo, RANK hi) {
	assert(0 <= lo <= hi < size_);
	if (lo == hi) return ; //退化的情况
	while (hi < size_) {  //[hi, size_)所有数据向前移动hi-lo个单位
		elem_[lo++] = elem_[hi++];
	}
	size_ = lo;  //更新规模，直接丢弃尾部[lo,size_hi)区间
	shrink();
	return hi - lo;
}
//删除秩为r的元素,返回被删除元素的数据
template <typename T>
T Vector<T>::remove(RANK r) {
	T tmp = elem_[r];
	remove(r, r+1);
	return tmp;
}
//有序向量区间[lo, hi)查找最后一个不大于e的元素，返回该元素的秩
template <typename T>
RANK Vector<T>::search(T const& e, RANK lo, RANK hi) const {
	assert(0 <= lo <= hi < size_);
	return rand() % 2 ? binSearch(elem_, e, lo, hi):fibSearch(elem_, e, lo, hi);
}
//有序向量的二分查找--版本1
template <typename T>
RANK Vector<T>::binSearch(T* A, T const& e, RANK lo, RANK hi) {
	RANK mi = 0;
	while (lo < hi) {
		mi = (lo + hi) >> 1;
		if (e == A[mi]) return mi;
		else if (e < A[mi]) hi = mi;
		else lo = mi + 1;
	}
	return -1;  //未找到返回-1
}

//有序向量的二分查找--改进版本A
//减少最坏情况时间复杂度，不能提前返回
template <typename T>
RANK Vector<T>::binSearchA(T* A, T const& e, RANK lo, RANK hi) {
	RANK mi = 0;
	while (1 < hi - lo) {
		mi = (lo + hi) >> 1
		(e < A[mi]) ? hi = mi : lo = mi;
	}
	return e == A[lo] ? lo:-1;  //返回位置总是不超过e的最大者， 不能保证返回的是位置是最后元素的位置
}

//有序向量的二分查找--改进版本B
//减少最坏情况时间复杂度，不能提前返回
//本质是查找大于e的第一个元素，然后返回的是这个元素的前面一个元素
template <typename T>
RANK Vector<T>::binSearchB(T* A, T const& e, RANK lo, RANK hi) {
	RANK mi = 0;
	while (lo < hi) {
		mi = (lo + hi) >> 1
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	return lo - 1;  //返回位置总是不超过e的最大者， 可以保证返回元素是最后的元素
}

//无序向量查找， 查找成功返回最后一个元素e的秩， 失败返回lo-1
template <typename T>
RANK Vector<T>::find(T const& e, RANK lo, RANK hi) const {
	while ((lo < hi--) && e != elem_[hi]);
	return hi;
}

//遍历操作，利用函数对象机制
template <typename VST>
void Vector<T>::traverse(VST& visit) {
	RANK i = 0;
	while (i < size_) {
		visit(elem_[i]);
		i++;
	}
	return ;
}

//无序向量去重
template <typename T>
int Vector<T>::deduplicate() {
	int old_size = size_;
	RANK i = 1; //从第二个元素开始
	while (i < size_) {
		(find(elem_[i], 0, i) < 0) ? i++ : remove(i) ;  //在[0,i)中查找元素elem_[i],找到了就删除该元素
	}

	return old_size - size_; //返回删除的重复元素个数
}

//有序向量去重
template <typename T>
int Vector<T>::uniquify() {
	RANK i = 0;
	RANK j = 0;
	while (++j < size_) {
		if (elem_[i] != elem_[j]) {  //不相同时直接右移到elem_[i+1]
			elem_[++i] = elem_[j];
		}
	}
	size_ = ++i;  //更新规模
	shrink();  //缩容处理
	return j - i;
}

//返回区间[lo, hi)的逆序对
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

//返回区间[lo, hi)的最大值的秩
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

//冒泡扫描交换， 
template <typename T>
int Vector<T>::bubble(RANK lo, RANK hi) {
	RANK last = lo;  //记录最后一对逆序对的位置，初始化为[lo-1, lo]。 last之后的子向量都是有序的
	while (++lo < hi) {  //从左到右，逐次扫描
		if (elem_[lo - 1] > elem_[lo]) {
			last = lo;  //发现有逆序对时更新last的位置
			swap(elem_[lo - 1], elem_[lo]);  //交换逆序对，使之有序
		}
	}
	return last;
}

//冒泡排序算法
template <typename T>
int Vector<T>::bubbleSort(RANK lo, RANK hi) {
	while (lo < (hi = bubble(lo, hi)));  //hi = last，只需要对[lo, last]之间的元素排序，因为[last, size)之间的元素都是有序的
}

//归并算法
//通过lo,mi,hi将原来大的向量A[lo, hi)分成左子向量B[lo, mi) 和 右子向量C[mi, hi)
template <typename T>
void Vector<T>::merge(RANK lo, RANK mi, RANK hi) {
	RANK i = 0, j = 0, k = 0; //A[i], B[j], C[k] 
	T* A = elem_ + lo;  //要合成的向量A[lo,hi)
	T* B = new T[mi - lo]; //申请左子向量B的空间
	T* C = elem_ + mi;  //不需要给右子向量C重新申请空间
	RANK lb = mi - lo;  //左子向量B的大小
	RANK lc = hi - mi;  //右子向量C的大小
	while ((j<lb) || (k < lc)) {
		if ((j < lb) && (lc <= k || (B[j] <= C[k]))) A[i++] = B[j++];  //B 中有元素，且（C中没有元素 或者 C的元素较小）
		if ((k < lc) && (lb <= j || (C[k] < B[j]))) A[i++] = C[k++];  //C中有元素，且（B中没有元素 或者 C中的元素较小）
	}
	delete []B;  //释放申请的B的空间
}

//归并排序
//[lo,hi)
template <typename T>
void Vector<T>::mergeSort(RANK lo, RANK hi) {
	if ((hi - lo) < 2) return ;  //单元素区间自然有序，注意区间是左开右闭因此相差2才是两个元素
	RANK mi = (lo + hi) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

