//
//  EnumerateBinaryTree.hpp
//  EnumerateBinaryTree
//
//  Created by Source on 2020/10/4.
//  Copyright © 2020 Source. All rights reserved.
//

#ifndef EnumerateBinaryTree_hpp
#define EnumerateBinaryTree_hpp

#include <stdio.h>
#include <vector>


struct BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;
};


class EnumerateBinaryTree {
public:
    static std::vector<int> recursiveFrontEnumerateBinaryTree(BinaryTree *root);
    static std::vector<int> nonRecursiveFrontEnumerateBinaryTree(BinaryTree *root);
    
    static std::vector<int> recursiveMiddleEnumerateBinaryTree(BinaryTree *root);
    static std::vector<int> nonRecursiveMiddleEnumerateBinaryTree(BinaryTree *root);
    
    static std::vector<int> recursiveBackEnumerateBinaryTree(BinaryTree *root);
    static std::vector<int> nonRecursiveBackEnumerateBinaryTree(BinaryTree *root);
};


#endif /* EnumerateBinaryTree_hpp */
