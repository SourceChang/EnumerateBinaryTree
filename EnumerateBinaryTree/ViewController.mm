//
//  ViewController.m
//  EnumerateBinaryTree
//
//  Created by Source on 2020/10/4.
//  Copyright © 2020 Source. All rights reserved.
//

#import "ViewController.h"


#include <iostream>


#include "EnumerateBinaryTree.hpp"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    /*
                                1
                             /    \
                            2      3
                         /     \
                        4       5
                     /     \
                    6       7
                 /     \
                8       9
             /     \
            10      11
     */
    
    BinaryTree *head = [self createTree];
    
    std::vector<int> array1 = EnumerateBinaryTree::recursiveFrontEnumerateBinaryTree( head );
    for ( auto value : array1 ) {
        
        std::cout << value << " ";
    }
    std::cout << std::endl << "-------------------" << std::endl;
    
    std::vector<int> array2 =EnumerateBinaryTree::nonRecursiveFrontEnumerateBinaryTree( head );
    for ( auto value : array2 ) {
        
        std::cout << value << " ";
    }
    std::cout << std::endl << "-------------------" << std::endl;
    
    std::vector<int> array3 =EnumerateBinaryTree::recursiveMiddleEnumerateBinaryTree( head );
    for ( auto value : array3 ) {
        
        std::cout << value << " ";
    }
    std::cout << std::endl << "-------------------" << std::endl;
    
    std::vector<int> array4 =EnumerateBinaryTree::nonRecursiveMiddleEnumerateBinaryTree( head );
    for ( auto value : array4 ) {
        
        std::cout << value << " ";
    }
    std::cout << std::endl << "-------------------" << std::endl;
    
    std::vector<int> array5 =EnumerateBinaryTree::recursiveBackEnumerateBinaryTree( head );
    for ( auto value : array5 ) {
        
        std::cout << value << " ";
    }
    std::cout << std::endl << "-------------------" << std::endl;
    
    std::vector<int> array6 =EnumerateBinaryTree::nonRecursiveBackEnumerateBinaryTree( head );
    for ( auto value : array6 ) {
        
        std::cout << value << " ";
    }
    std::cout << std::endl << "-------------------" << std::endl;
}


- (BinaryTree *)createTree {
    
    int value = 0;
    BinaryTree *head = (BinaryTree *)malloc(sizeof(BinaryTree));
    head -> value = ++value;
    head -> left = NULL;
    head -> right = NULL;
    BinaryTree *root = head;
    while ( root && value <= 9 ) {
        
        BinaryTree *left = (BinaryTree *)malloc(sizeof(BinaryTree));
        left -> value = ++value;
        left -> left = NULL;
        left -> right = NULL;
        root -> left = left;
        
        BinaryTree *right = (BinaryTree *)malloc(sizeof(BinaryTree));
        right -> value = ++value;
        right -> left = NULL;
        right -> right = NULL;
        root -> right = right;
        
        root = root -> left;
    }
    
    return head;
}


@end
