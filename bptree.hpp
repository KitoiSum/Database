//
//  bptree.hpp
//  Database
//
//  Created by  weixm on 2018/7/16.
//  Copyright © 2018  weixm. All rights reserved.
//

#ifndef bptree_hpp
#define bptree_hpp

#include <string>
#include <stdio.h>
#include <iostream>

// M is the size of a half node
// for the convinience of delete and insert
#define M 2
using namespace std;

/* class Node
 * -----------------------------
 * A basic structure in B+ tree;
 */
class Node{
public:
    // {pos} is the position of node
    // pos is equal to the order node being added
    // pos gets the same effact in disk
    // as pointer or address does in memory
    // pos = -1 means it points to "NULL"
    unsigned int pos;
    
    // {num} shows the number of keys it contains
    unsigned int num;
    
    // {isleaf} shows whether it gets sons
    bool isleaf;
    
    // {keys[]} keeps the keys it contains
    // key type is int
    int keys[2*M];
    
    // {sons[]} stores its sons node's position
    int sons[2*M];
    
    // {bro} is the position pointing its brother
    int bro;
    
    //constructor
    Node();
};


/* class Tree
 * -----------------------------
 * A b+ tree with methods
 */
class Tree{
public:
    
    // constructor
    Tree();
    
    // creat an empty index file with given name
    void initIndex(string);
    
    // init the tree from existed index file
    int  openIndex(string);
    
    // close the index file
    void closeIndex();
    
    // give out the pos when a key is given
    int  searchPos(int key);
    
    // write key to index file in position pos
    void insertKey(int key, int pos);
    
    // write key out of index file in its position
    void deleteKey(int key);
    
    // {filename}: the name of datafile
    string filename;
    
private:
    
    // root
    Node* root;
    
    // {rtPos}: the postion of root; this->root->pos
    // may not be 1 for root may change
    unsigned int rtPos;
    
    // {scope}: how many nodes the tree has
    unsigned int scope;
    
    // {file}: pointer to datafile in disk
    // C style FILE reads and writes faster than fstream
    FILE* file;
    
    
    // make a node written in this->file
    void writeNode(Node*);
    
    // make a node the same as the node
    // stores in this->file in certain position
    void readNode(Node*, int pos);
    
    // when the tree is full and a new key should be inserted
    void splitNode(Node* pre, Node* cur, int splitPos);
    
    // insert a key to a not full tree
    void insertNodeToNotFull(Node*s, int key, unsigned int pos);
    
    // make old node's position filled with new onw
    // when old node is deleted
    void replaceKey(int oldkey, int newkey);
    
    // adkust the node's son to prepare for delete it
    int preDelete(Node*,Node*,unsigned int);
    
    // start with a node , find key and delete it
    int deleteKeyInNode(Node* start, int key);
    
    // helpers in trans form string to char*
    // to fit c style funtions for FILE*
    int string_to_int(string input);
    void string_to_char(char* ch, string input);
    
};

#endif /* bptree_hpp */
