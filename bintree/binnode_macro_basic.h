0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 /******************************************************************************************
0010  * BinNode状态与性质的判断
0011  ******************************************************************************************/
0012 #define IsRoot(x) ( ! ( (x).parent ) )
0013 #define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
0014 #define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
0015 #define HasParent(x) ( ! IsRoot(x) )
0016 #define HasLChild(x) ( (x).lc )
0017 #define HasRChild(x) ( (x).rc )
0018 #define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //至少拥有一个孩子
0019 #define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //同时拥有两个孩子
0020 #define IsLeaf(x) ( ! HasChild(x) )
0021 
0022 /******************************************************************************************
0023  * 与BinNode具有特定关系的节点及指针
0024  ******************************************************************************************/
0025 #define sibling(p) /*兄弟*/ \
0026    ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc )
0027 
0028 #define uncle(x) /*叔叔*/ \
0029    ( IsLChild( * ( (x)->parent ) ) ? (x)->parent->parent->rc : (x)->parent->parent->lc )
0030 
0031 #define FromParentTo(x) /*来自父亲的引用*/ \
0032    ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )