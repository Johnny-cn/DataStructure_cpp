0001 /******************************************************************************************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  ******************************************************************************************/
0008 
0009 /******************************************************************************************
0010  * Test of Binary Search Tree
0011  ******************************************************************************************/
0012 #include "BST_test.h"
0013 
0014 /******************************************************************************************
0015  * Test a BST
0016  ******************************************************************************************/
0017 template <typename T> void  testBST ( int n ) {
0018    BST<T> bst;
0019    while ( bst.size() < n ) bst.insert ( dice ( ( T ) n * 3 ) ); print ( bst ); //随机创建
0020    bst.stretchToLPath(); print ( bst ); //伸直成撇
0021    while ( !bst.empty() ) bst.remove ( bst.root()->data ); //清空
0022    while ( bst.size() < n ) bst.insert ( dice ( ( T ) n * 3 ) ); print ( bst ); //随机创建
0023    bst.stretchToRPath(); print ( bst ); //伸直成捺
0024    while ( !bst.empty() ) bst.remove ( bst.root()->data ); //清空
0025    while ( bst.size() < n ) { //随机插入、查询、删除
0026       T e = dice ( ( T ) n * 3 ); //[0, 3n)范围内的e
0027       switch ( dice ( 3 ) ) {
0028          case 0: { //查找，成功率 <= 33.3%
0029             printf ( "Searching for " ); print ( e ); printf ( " ... " );
0030             BinNodePosi(T) & p = bst.search ( e );
0031             p ?
0032             printf ( "Found with" ), print ( p->data ), printf ( "\n" ) :
0033             printf ( "not found\n" );
0034             break;
0035          }
0036          case 1: { //删除，成功率 <= 33.3%
0037             printf ( "Removing " ); print ( e ); printf ( " ... " );
0038             bst.remove ( e ) ?
0039             printf ( "Done\n" ), print ( bst ) :
0040             printf ( "not exists\n" );
0041             break;
0042          }
0043          default: {//插入，成功率 == 100%
0044             printf ( "Inserting " ); print ( e ); printf ( " ... " );
0045             printf ( "Done with" ), print ( bst.insert ( e )->data ), printf ( "\n" ), print ( bst );
0046             break;
0047          }
0048       }
0049    }
0050    while ( bst.size() > 0 ) { //清空
0051       T e = dice ( ( T ) n * 3 ); //[0, 3n)范围内的e
0052       printf ( "Removing " ); print ( e ); printf ( " ... " );
0053       bst.remove ( e ) ? printf ( "Done\n" ), print ( bst ) : printf ( "not exists\n" );
0054    }
0055 }
0056 
0057 /******************************************************************************************
0058  * 测试主入口
0059  ******************************************************************************************/
0060 int main ( int argc, char* argv[] ) {
0061    if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
0062    srand ( ( unsigned int ) time ( NULL ) );
0063    testBST<int> ( atoi ( argv[1] ) ); //元素类型可以在这里任意选择
0064    return 0;
0065 }

