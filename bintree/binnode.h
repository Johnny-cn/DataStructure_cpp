0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 #define BinNodePosi(T) BinNode<T>* //节点位置
0010 #define stature(p) ((p) ? (p)->height : -1) //节点高度（与“空树高度为-1”的约定相统一）
0011 typedef enum { RB_RED, RB_BLACK} RBColor; //节点颜色
0012 
0013 template <typename T> struct BinNode { //二叉树节点模板类
0014 // 成员（为简化描述起见统一开放，读者可根据需要进一步封装）
0015    T data; //数值
0016    BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc; //父节点及左、右孩子
0017    int height; //高度（通用）
0018    int npl; //Null Path Length（左式堆，也可直接用height代替）
0019    RBColor color; //颜色（红黑树）
0020 // 构造函数
0021    BinNode() :
0022       parent ( NULL ), lc ( NULL ), rc ( NULL ), height ( 0 ), npl ( 1 ), color ( RB_RED ) { }
0023    BinNode ( T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
0024              int h = 0, int l = 1, RBColor c = RB_RED ) :
0025       data ( e ), parent ( p ), lc ( lc ), rc ( rc ), height ( h ), npl ( l ), color ( c ) { }
0026 // 操作接口
0027    int size(); //统计当前节点后代总数，亦即以其为根的子树的规模
0028    BinNodePosi(T) insertAsLC ( T const& ); //作为当前节点的左孩子插入新节点
0029    BinNodePosi(T) insertAsRC ( T const& ); //作为当前节点的右孩子插入新节点
0030    BinNodePosi(T) succ(); //取当前节点的直接后继
0031    template <typename VST> void travLevel ( VST& ); //子树层次遍历
0032    template <typename VST> void travPre ( VST& ); //子树先序遍历
0033    template <typename VST> void travIn ( VST& ); //子树中序遍历
0034    template <typename VST> void travPost ( VST& ); //子树后序遍历
0035 // 比较器、判等器（各列其一，其余自行补充）
0036    bool operator< ( BinNode const& bn ) { return data < bn.data; } //小于
0037    bool operator== ( BinNode const& bn ) { return data == bn.data; } //等于
0038 };