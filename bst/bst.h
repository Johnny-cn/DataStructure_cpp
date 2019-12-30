0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 #include "BinTree/BinTree.h" //引入BinTree
0010 
0011 template <typename T> class BST : public BinTree<T> { //由BinTree派生BST模板类
0012 protected:
0013    BinNodePosi(T) _hot; //“命中”节点的父亲
0014    BinNodePosi(T) connect34 ( //按照“3 + 4”结构，联接3个节点及四棵子树
0015       BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
0016       BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T) );
0017    BinNodePosi(T) rotateAt ( BinNodePosi(T) x ); //对x及其父亲、祖父做统一旋转调整
0018 public: //基本接口：以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写
0019    virtual BinNodePosi(T) & search ( const T& e ); //查找
0020    virtual BinNodePosi(T) insert ( const T& e ); //插入
0021    virtual bool remove ( const T& e ); //删除
0022 };