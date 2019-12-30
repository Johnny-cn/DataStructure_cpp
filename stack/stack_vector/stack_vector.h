/******************************************************************************************
* Data Structures in C++
* Li MingFeng 
* +86 15071373461
* this is Only for my self-study
* Copyright (c) 2019-~ All rights reserved.
********************************************************************************************/

#ifndef _STACK_VECTOR_H_
#define _STACK_VECTOR_H_

#include "../../vector/vector.h"  //由向量实现栈

//以向量为基类派生出栈的模板类
//向量首为栈底，向量尾尾栈顶
template <typename T> 
class Stack:public Vector<T> {
piblic: //其余接口均可继续使用
	void push(T const& e) { insert(e);} //栈只能在栈顶插入元素
	T& top() { return (*this)[size_ - 1];}  //返回向量最后一个元素的引用
	T pop() { return remove(size_);}  //删除最后一个元素
}

#endif

