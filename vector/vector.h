/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

//vector ģ����
#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef int RANK; //��
#define DEFAULT_CAPACITY (5) //Ĭ�ϵĳ�ʼ����

template <typename T>
class Vector {
public:
	int size() { return size_;}  //���ص�ǰ������ģ
	bool empety() { return !size_; }  //�п�
	void copyFrom(T const& A, RANK lo, RANK hi);  //��������A����[lo, hi)��Ԫ��
	void expand();  //���ݴ���
	void shrink();  //���ݴ���
//����������
	Vector(int c = DEFAULT_CAPACITY, int s = 0; T v = 0) {
		elem_ = new T[capacity_ = c];
		for (size_ = 0; size_ < s; elem_[size++] = v);
	}  //��ʼ����Ϊc����ģΪs��Ԫ��Ϊv
	Vector(T const& A, RANK n) { copyFrom(A, 0, n);}  //s�������帴��
	Vector(T const& A, RANK lo, RANK hi) { copyFrom(A, lo, hi);}  //�������临�ƹ���
	Vector(Vector<T> const& V) {copyFrom(V.elem_, 0, V.size_);}  //�������帴�ƹ���
	Vector(Vector<T> const& V, RANK lo, RANK hi) { copyFrom(V.elem_, lo, hi); }  //���俽������
	~Vector() { delete []elem_; } 

	void put(RANK r, T const& e);  //�޸���Ϊr��Ԫ��Ϊe
	T& get(RANK r);  //������Ϊr��Ԫ������
	RANK insert(RANK r, T const& e);  //����Ԫ��e��r��λ��
	RANK insert(T const& e) { return insert(size_, e); }  //Ĭ����ΪĩԪ�ز���
	int remove(RANK lo, RANK hi);  //ɾ������[lo, hi)��Ԫ��,���ر�ɾ��Ԫ�صĸ���
	T remove(RANK r);  //ɾ����Ϊr��Ԫ�أ� ���ر�ɾ��Ԫ�ص�ֵ
	RANK search(T const& e, RANK lo, RANK hi)const;  //���������������
	RANK search(T const& e) const { return search(e, 0, size_);}  //���������������
	RANK find(T const& e, RANK lo, RANK hi) const;  //���������������
	RANK find(T const& e) const { return find(e, 0, size_);}  //���������������
	template <typename VST>
	void traverse(VST& visit); //��������������ʵ��

//�㷨
	int disorded(RANK lo, RANK hi);  //���������е������
	int deduplicate();  //����ȥ��
	int uniquify();  //����ȥ��
	RANK max(RANK lo, RANK hi);  //��ȡ���������Ԫ�أ� �������Ԫ�ص���
	void sort(RANK lo, RANK hi);  //��������
	void bubble(RANK lo, RANK hi);  //ð��ɨ�轻��
	void bubuleSort(RANK lo, RANK hi);  //ð�������㷨
	void merge(RANK lo, RANK mi, RANK hi);  //�鲢�㷨
	void mergeSort(RANK lo, RANK hi);  //�鲢�����㷨
	void quickSort(RANK lo, RANK hi);  //���������㷨
	void shellSort(RANK lo, RANK hi);  //ϣ������
	void heapSort(RANK lo, RANK hi);  //������
	RANK partition(RANK lo, RANK hi);  //��㹹���㷨

private:
	int size_;  //������ǰ��ģ
	int capacity_;  //��������
	T* elem_;  //������
};//Vector

#endif
