//
// Created by Rishav Sharma on 10/31/25.
//
#ifndef P4_DECODEHUFFMAN_HUFFMANTREE_H
#define P4_DECODEHUFFMAN_HUFFMANTREE_H

#include "utils.hpp"
#include <vector>
#include <string>

#include "TreeNode.hpp"


class HuffmanTree {
    public:
    HuffmanTree() = default;
    ~HuffmanTree();

    static HuffmanTree buildFromHeader(std::vector<std::pair<std::string, std::string>>);
    error_type decode(std::ifstream&, std::ofstream&);

private:
    static TreeNode* root;
    static void destroyTree(TreeNode*) noexcept;
    static void buildTree(std::string address, std::string word);


};


#endif //P4_DECODEHUFFMAN_HUFFMANTREE_H