//
// Created by Rishav Sharma on 10/31/25.
//

#include "HuffmanTree.hpp"

#include <iostream>

#include "utils.hpp"


HuffmanTree::~HuffmanTree() {
    destroyTree(root);
    root = nullptr;
}


void HuffmanTree::destroyTree(TreeNode* node) noexcept {
    if (!node) return;
    destroyTree(node->leftSubtree());
    destroyTree(node->rightSubtree());
    delete node;
}


HuffmanTree HuffmanTree::buildFromHeader(std::vector<std::pair<std::string, std::string> > headerIn) {
    //check if we have an empty header file
    if (headerIn.empty())
        return HuffmanTree();

    //check if we have a root
    if (!root)
        root = new TreeNode();

    //loop for each word
    for (auto i = 0; i < headerIn.size(); i++) {
        //create a temp word for readbility
        std::string address = headerIn.at(i).second;
        std::string word = headerIn.at(i).first;
        buildTree(address, word);
    }

    return HuffmanTree();
}

void HuffmanTree::buildTree(std::string address, std::string word) {
    TreeNode *curr = root;
    for (char c: address) {
        if (c == '0') {
            if (!curr->leftSubtree())
                curr->leftSubtree(new TreeNode());
            curr = curr->leftSubtree();
        } else if ( c == '1') {
            if (!curr->rightSubtree())
                curr->rightSubtree(new TreeNode());
            curr = curr->rightSubtree();
        } else {
            break;
        }
    }
    curr->setWord(word);
}
