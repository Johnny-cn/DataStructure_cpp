/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

#include "../../list/list.h"  //由列表实现栈

//以列表为基类派生出栈的模板类
//列表首节点为栈顶，列表尾节点为栈底
template <typename T> 
class Stack:public List<T> {
piblic: //其余接口均可继续使用
	void push(T const& e) {insertAsFirst(e);}  //作为首节点插入
	T& top() { return first()->data;}  //返回首节点的引用
	T pop() { return remove(first());}  //删除首节点
}

#endif

