0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 #include "BinNode.h" //引入二叉树节点类
0010 template <typename T> class BinTree { //二叉树模板类
0011 protected:
0012    int _size; BinNodePosi(T) _root; //规模、根节点
0013    virtual int updateHeight ( BinNodePosi(T) x ); //更新节点x的高度
0014    void updateHeightAbove ( BinNodePosi(T) x ); //更新节点x及其祖先的高度
0015 public:
0016    BinTree() : _size ( 0 ), _root ( NULL ) { } //构造函数
0017    ~BinTree() { if ( 0 < _size ) remove ( _root ); } //析构函数
0018    int size() const { return _size; } //规模
0019    bool empty() const { return !_root; } //判空
0020    BinNodePosi(T) root() const { return _root; } //树根
0021    BinNodePosi(T) insertAsRoot ( T const& e ); //插入根节点
0022    BinNodePosi(T) insertAsLC ( BinNodePosi(T) x, T const& e ); //e作为x的左孩子（原无）插入
0023    BinNodePosi(T) insertAsRC ( BinNodePosi(T) x, T const& e ); //e作为x的右孩子（原无）插入
0024    BinNodePosi(T) attachAsLC ( BinNodePosi(T) x, BinTree<T>* &T ); //T作为x左子树接入
0025    BinNodePosi(T) attachAsRC ( BinNodePosi(T) x, BinTree<T>* &T ); //T作为x右子树接入
0026    int remove ( BinNodePosi(T) x ); //删除以位置x处节点为根的子树，返回该子树原先的规模
0027    BinTree<T>* secede ( BinNodePosi(T) x ); //将子树x从当前树中摘除，并将其转换为一棵独立子树
0028    template <typename VST> //操作器
0029    void travLevel ( VST& visit ) { if ( _root ) _root->travLevel ( visit ); } //层次遍历
0030    template <typename VST> //操作器
0031    void travPre ( VST& visit ) { if ( _root ) _root->travPre ( visit ); } //先序遍历
0032    template <typename VST> //操作器
0033    void travIn ( VST& visit ) { if ( _root ) _root->travIn ( visit ); } //中序遍历
0034    template <typename VST> //操作器
0035    void travPost ( VST& visit ) { if ( _root ) _root->travPost ( visit ); } //后序遍历
0036    bool operator< ( BinTree<T> const& t ) //比较器（其余自行补充）
0037    { return _root && t._root && lt ( _root, t._root ); }
0038    bool operator== ( BinTree<T> const& t ) //判等器
0039    { return _root && t._root && ( _root == t._root ); }
0040 }; //BinTree