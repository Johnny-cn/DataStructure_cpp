/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

#ifndef _STACK_VECTOR_H_
#define _STACK_VECTOR_H_

#include "../../vector/vector.h"  //������ʵ��ջ

//������Ϊ����������ջ��ģ����
//������Ϊջ�ף�����ββջ��
template <typename T> 
class Stack:public Vector<T> {
piblic: //����ӿھ��ɼ���ʹ��
	void push(T const& e) { insert(e);} //ջֻ����ջ������Ԫ��
	T& top() { return (*this)[size_ - 1];}  //�����������һ��Ԫ�ص�����
	T pop() { return remove(size_);}  //ɾ�����һ��Ԫ��
}

#endif

