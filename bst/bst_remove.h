0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> bool BST<T>::remove ( const T& e ) { //从BST树中删除关键码e
0010    BinNodePosi(T) & x = search ( e ); if ( !x ) return false; //确认目标存在（留意_hot的设置）
0011    removeAt ( x, _hot ); _size--; //实施删除
0012    updateHeightAbove ( _hot ); //更新_hot及其历代祖先的高度
0013    return true;
0014 } //删除成功与否，由返回值指示