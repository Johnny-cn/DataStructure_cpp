0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 #define IsBlack(p) ( ! (p) || ( RB_BLACK == (p)->color ) ) //外部节点也视作黑节点
0010 #define IsRed(p) ( ! IsBlack(p) ) //非黑即红
0011 #define BlackHeightUpdated(x) ( /*RedBlack高度更新条件*/ \
0012    ( stature( (x).lc ) == stature( (x).rc ) ) && \
0013    ( (x).height == ( IsRed(& x) ? stature( (x).lc ) : stature( (x).lc ) + 1 ) ) \
0014 )