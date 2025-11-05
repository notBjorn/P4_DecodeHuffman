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


HuffmanTree HuffmanTree::(const std::vector<std::pair<std::string, std::string>>& headerIn) {
    //check if we have an empty header file
    HuffmanTree HFtree;
    if (headerIn.empty())
        return HFtree;

    //loop for each word
    for (const auto&[word, address]: headerIn) {
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
    return;
}

error_type HuffmanTree::decode(std::ifstream& code_in, std::ofstream& token_out) {
    if (!root) {
        std::cerr << "Error: decode called with empty Huffman tree\n";
        return ERR_TYPE_NOT_FOUND;
    }
    if (!code_in.is_open()) {
        std::cerr << "Error: input stream is not open\n";
        return UNABLE_TO_OPEN_FILE;
    }
    if (!token_out.is_open()) {
        std::cerr << "Error: output stream is not open\n";
        return UNABLE_TO_OPEN_FILE_FOR_WRITING;
    }



    TreeNode *curr = root;
    for (char c; code_in.get(c);) {
        if (c == '0')
            curr = curr->leftSubtree();
        else if (c == '1')
            curr = curr->rightSubtree();
        else
            continue;

        if (curr->leftSubtree()==nullptr && curr->rightSubtree()==nullptr) {
            token_out << curr->whatWord();
            token_out << '\n';
            curr = root;
        }
    }

    return NO_ERROR;

}

