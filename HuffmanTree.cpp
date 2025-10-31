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


HuffmanTree HuffmanTree::buildFromHeader(const std::vector<std::pair<std::string, std::string>>& headerIn) {
    //check if we have an empty header file
    HuffmanTree HFtree;
    if (headerIn.empty())
        return HFtree;

    //loop for each word
    for (const auto&[address, word]: headerIn) {
        HFtree.buildTree(address, word);
    }

    return HFtree;
}

void HuffmanTree::buildTree(const std::string& address, const std::string& word) {
    if (!root) root = new TreeNode();

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
