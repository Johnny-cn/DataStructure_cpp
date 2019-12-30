/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

//vector 模板类
#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef int RANK; //秩
#define DEFAULT_CAPACITY (5) //默认的初始容量

template <typename T>
class Vector {
public:
	int size() { return size_;}  //返回当前向量规模
	bool empety() { return !size_; }  //判空
	void copyFrom(T const& A, RANK lo, RANK hi);  //拷贝数组A区间[lo, hi)的元素
	void expand();  //扩容处理
	void shrink();  //缩容处理
//构造与析构
	Vector(int c = DEFAULT_CAPACITY, int s = 0; T v = 0) {
		elem_ = new T[capacity_ = c];
		for (size_ = 0; size_ < s; elem_[size++] = v);
	}  //初始容量为c，规模为s，元素为v
	Vector(T const& A, RANK n) { copyFrom(A, 0, n);}  //s数组整体复制
	Vector(T const& A, RANK lo, RANK hi) { copyFrom(A, lo, hi);}  //数组区间复制构造
	Vector(Vector<T> const& V) {copyFrom(V.elem_, 0, V.size_);}  //向量整体复制构造
	Vector(Vector<T> const& V, RANK lo, RANK hi) { copyFrom(V.elem_, lo, hi); }  //区间拷贝构造
	~Vector() { delete []elem_; } 

	void put(RANK r, T const& e);  //修改秩为r的元素为e
	T& get(RANK r);  //返回秩为r的元素引用
	RANK insert(RANK r, T const& e);  //插入元素e在r的位置
	RANK insert(T const& e) { return insert(size_, e); }  //默认作为末元素插入
	int remove(RANK lo, RANK hi);  //删除区间[lo, hi)的元素,返回被删除元素的个数
	T remove(RANK r);  //删除秩为r的元素， 返回被删除元素的值
	RANK search(T const& e, RANK lo, RANK hi)const;  //有序向量区间查找
	RANK search(T const& e) const { return search(e, 0, size_);}  //有序向量整体查找
	RANK find(T const& e, RANK lo, RANK hi) const;  //无序向量区间查找
	RANK find(T const& e) const { return find(e, 0, size_);}  //无序向量整体查找
	template <typename VST>
	void traverse(VST& visit); //遍历，函数对象实现

//算法
	int disorded(RANK lo, RANK hi);  //返回区间中的逆序对
	int deduplicate();  //无序去重
	int uniquify();  //有序去重
	RANK max(RANK lo, RANK hi);  //获取区间中最大元素， 返回最大元素的秩
	void sort(RANK lo, RANK hi);  //向量排序
	void bubble(RANK lo, RANK hi);  //冒泡扫描交换
	void bubuleSort(RANK lo, RANK hi);  //冒泡排序算法
	void merge(RANK lo, RANK mi, RANK hi);  //归并算法
	void mergeSort(RANK lo, RANK hi);  //归并排序算法
	void quickSort(RANK lo, RANK hi);  //快速排序算法
	void shellSort(RANK lo, RANK hi);  //希尔排序
	void heapSort(RANK lo, RANK hi);  //堆排序
	RANK partition(RANK lo, RANK hi);  //轴点构造算法

private:
	int size_;  //向量当前规模
	int capacity_;  //向量容量
	T* elem_;  //数据区
};//Vector

#endif
