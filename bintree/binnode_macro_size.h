0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 template <typename T> int BinNode<T>::size() { //统计当前节点后代总数，即以其为根的子树规模
0010    int s = 1; //计入本身
0011    if ( lc ) s += lc->size(); //递归计入左子树规模
0012    if ( rc ) s += rc->size(); //递归计入右子树规模
0013    return s;
0014 }