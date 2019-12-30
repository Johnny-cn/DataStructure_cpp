/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

#include "../../list/list.h"  //���б�ʵ��ջ

//���б�Ϊ����������ջ��ģ����
//�б��׽ڵ�Ϊջ�����б�β�ڵ�Ϊջ��
template <typename T> 
class Stack:public List<T> {
piblic: //����ӿھ��ɼ���ʹ��
	void push(T const& e) {insertAsFirst(e);}  //��Ϊ�׽ڵ����
	T& top() { return first()->data;}  //�����׽ڵ������
	T pop() { return remove(first());}  //ɾ���׽ڵ�
}

#endif

