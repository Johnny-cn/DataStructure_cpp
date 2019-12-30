0001 
/******************************************************************************
************
0002  * Data Structures in C++
0003  * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
0004  * Junhui DENG, deng@tsinghua.edu.cn
0005  * Computer Science & Technology, Tsinghua University
0006  * Copyright (c) 2003-2019. All rights reserved.
0007  
*******************************************************************************
***********/
0008 
0009 #include "binTree_test.h"
0010 
0011 int testID = 0; //测试编号
0012 
0013 // 随机生成期望高度为h的二叉树
0014 template <typename T> bool randomBinTree ( BinTree<T> & bt, BinNodePosi(T
) x, int h ) {
0015    if ( 0 >= h ) return false; //至多h层
0016    if ( 0 < dice ( h ) ) //以1/h的概率终止当前分支的生长
0017       randomBinTree ( bt, bt.insertAsLC ( x, dice ( ( T ) h * h * h ) ), 
h - 1 );
0018    if ( 0 < dice ( h ) ) //以1/h的概率终止当前分支的生长
0019       randomBinTree ( bt, bt.insertAsRC ( x, dice ( ( T ) h * h * h ) ), 
h - 1 );
0020    return true;
0021 }
0022 
0023 // 在二叉树中随机确定一个节点位置
0024 template <typename T> BinNodePosi(T) randomPosiInBinTree ( BinNodePosi(T
) root ) {
0025    if ( !HasChild ( *root ) ) return root;
0026    if ( !HasLChild ( *root ) )
0027       return dice ( 6 ) ? randomPosiInBinTree ( root->rc ) : root;
0028    if ( !HasRChild ( *root ) )
0029       return dice ( 6 ) ? randomPosiInBinTree ( root->lc ) : root;
0030    return dice ( 2 ) ?
0031           randomPosiInBinTree ( root->lc ) :
0032           randomPosiInBinTree ( root->rc ) ;
0033 }
0034 
0035 template <typename T> void   testBinTree ( int h ) { //测试二叉树
0036    printf ( "\n  ==== Test %2d. Generate a binTree of height <= %d \n", 
testID++, h );
0037    BinTree<T> bt; print ( bt );
0038    bt.insertAsRoot ( dice ( ( T ) h * h * h ) ); print ( bt );
0039    randomBinTree<T> ( bt, bt.root(), h ); print ( bt );
0040    printf ( "\n  ==== Test %2d. Double and increase all nodes by 
traversal\n", testID++ );
0041    bt.travPre ( Double<T>() ); bt.travPre ( Increase<T>() ); print ( bt );
0042    bt.travIn ( Double<T>() ); bt.travIn ( Increase<T>() ); print ( bt );
0043    bt.travPost ( Double<T>() ); bt.travPost ( Increase<T>() ); print ( 
bt );
0044    bt.travLevel ( Double<T>() ); bt.travLevel ( Increase<T>() ); print ( 
bt );
0045    Hailstone<T> he; bt.travIn ( he ); print ( bt );
0046    printf ( "\n  ==== Test %2d. Remove/release subtrees in the Tree\n", 
testID++ );
0047    while ( !bt.empty() ) {
0048       BinNodePosi(T) p = randomPosiInBinTree ( bt.root() ); //
随机选择一个节点
0049       if ( dice ( 2 ) ) {
0050          printf ( "removing " ); print ( p->data ); printf ( " ...\n" );
0051          printf ( "%d node(s) removed\n", bt.remove ( p ) ); print ( bt );
0052       } else {
0053          printf ( "releasing " ); print ( p->data ); printf ( " ...\n" );
0054          BinTree<T>* S = bt.secede ( p ); print ( S );
0055          printf ( "%d node(s) released\n", S->size() ); release ( S ); 
print ( bt );
0056       }
0057    }
0058 }
0059 
0060 int main ( int argc, char* argv[] ) { //测试二叉树
0061    if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] )
; return 1; }
0062    srand ( ( unsigned int ) time ( NULL ) );
0063    testBinTree<int> ( atoi ( argv[1] ) ); //
元素类型可以在这里任意选择
0064    return 0;
0065 }