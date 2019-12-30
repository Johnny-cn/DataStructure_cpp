0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 #define Balanced(x) ( stature( (x).lc ) == stature( (x).rc ) ) //理想平衡条件
0010 #define BalFac(x) ( stature( (x).lc ) - stature( (x).rc ) ) //平衡因子
0011 #define AvlBalanced(x) ( ( -2 < BalFac(x) ) && ( BalFac(x) < 2 ) ) //AVL平衡条件