/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Johnny Li, 707328350@qq.com
 * ~
 * Copyright (c) 2019-2020. All rights reserved.
 ******************************************************************************************/
 
 /******************************************************************************************
 * BinNode 节点的状态与性质的判断
 ******************************************************************************************/
#define IsRoot(x) (!(x).parent)
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) (NULL != (x).lc)
#define HasRChild(x) (NULL != (x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x)) 
 
 /******************************************************************************************
 * 与BinNode具有特定关系的节点或者指针
 ******************************************************************************************/
#define sibling(p) (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc) //该节点的兄弟节点
#define uncle(x) (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)  //节点的叔叔
#define FromParentTo(x) (IsRoot(x) ? root_ : (IsLChild(x) ?  (x)->parent->lc : (x)->parent->rc))  //该节点的父亲节点中指向该节点的指针
