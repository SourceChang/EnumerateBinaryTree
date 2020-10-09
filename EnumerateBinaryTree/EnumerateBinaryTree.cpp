//
//  EnumerateBinaryTree.cpp
//  EnumerateBinaryTree
//
//  Created by Source on 2020/10/4.
//  Copyright © 2020 Source. All rights reserved.
//

#include "EnumerateBinaryTree.hpp"


#include <stack>


void recursiveFrontEnumerateBinaryTreeImp(BinaryTree *root, std::vector<int>& results) {
    
    // 前序遍历
    // 根左右
    if ( !root ) {
        
        return;
    }
    
    results.push_back( root -> value );
    
    if ( root -> left ) {
        
        recursiveFrontEnumerateBinaryTreeImp( root -> left, results );
    }
    
    if ( root -> right ) {
        
        recursiveFrontEnumerateBinaryTreeImp( root -> right, results );
    }
}


std::vector<int> EnumerateBinaryTree::recursiveFrontEnumerateBinaryTree(BinaryTree *root) {
    
    std::vector<int> results;
    recursiveFrontEnumerateBinaryTreeImp( root, results );
    
    return results;
}


std::vector<int> EnumerateBinaryTree::nonRecursiveFrontEnumerateBinaryTree(BinaryTree *root) {
    
    // 根左右
    std::vector<int> results;
    std::stack<BinaryTree *> stack;
    while ( root || !stack.empty() ) {
        
        while ( root ) {
            
            results.push_back( root -> value );
            stack.push( root );
            
            root = root -> left;
        }
        
        root = stack.top();
        stack.pop();
        root = root -> right;
    }

    return results;
}


void recursiveMiddleEnumerateBinaryTreeImp(BinaryTree *root, std::vector<int>& results) {
    
    // 中序遍历
    // 左根右
    if ( !root ) {
        
        return;
    }
    
    if ( root -> left ) {
        
        recursiveMiddleEnumerateBinaryTreeImp( root -> left, results );
    }
    
    results.push_back( root -> value );
    
    if ( root -> right ) {
        
        recursiveMiddleEnumerateBinaryTreeImp( root -> right, results );
    }
}


std::vector<int> EnumerateBinaryTree::recursiveMiddleEnumerateBinaryTree(BinaryTree *root) {
    
    std::vector<int> results;
    recursiveMiddleEnumerateBinaryTreeImp( root, results );
    
    return results;
}


std::vector<int> EnumerateBinaryTree::nonRecursiveMiddleEnumerateBinaryTree(BinaryTree *root) {
    
    std::vector<int> results;
    std::stack<BinaryTree *> stack;
    while ( root || !stack.empty() ) {
        
        while ( root ) {
            
            stack.push( root );
            root = root -> left;
        }
        
        root = stack.top();
        stack.pop();
        results.push_back( root -> value );
        root = root -> right;
    }
    
    return results;
}


void recursiveBackEnumerateBinaryTreeImp(BinaryTree *root, std::vector<int>& results) {
    
    // 后序遍历
    // 左右根
    if ( !root ) {
        
        return;
    }
    
    if ( root -> left ) {
        
        recursiveBackEnumerateBinaryTreeImp( root -> left, results );
    }
    
    if ( root -> right ) {
        
        recursiveBackEnumerateBinaryTreeImp( root -> right, results );
    }
    
    results.push_back( root -> value );
}


std::vector<int> EnumerateBinaryTree::recursiveBackEnumerateBinaryTree(BinaryTree *root) {
    
    std::vector<int> results;
    recursiveBackEnumerateBinaryTreeImp( root, results );
    
    return results;
}


std::vector<int> EnumerateBinaryTree::nonRecursiveBackEnumerateBinaryTree(BinaryTree *root) {
    
    // 左右根
    // 仿照先序遍历
    // 根右左
    // 最后再 reverse 就是 左右根 了
    std::vector<int> results;
    std::stack<BinaryTree *> stack;
    while ( root || !stack.empty() ) {
        
        while ( root ) {
            
            results.push_back( root -> value );
            
            stack.push( root );
            root = root -> right;
        }
        
        root = stack.top();
        stack.pop();
        root = root -> left;
    }
    std::reverse( results.begin(), results.end() );
    
    return results;
}

