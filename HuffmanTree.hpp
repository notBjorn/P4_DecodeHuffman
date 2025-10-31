//
// Created by Rishav Sharma on 10/31/25.
//
#ifndef P4_DECODEHUFFMAN_HUFFMANTREE_H
#define P4_DECODEHUFFMAN_HUFFMANTREE_H

#include "utils.hpp"
#include <vector>
#include <string>
#include <fstream>

#include "TreeNode.hpp"


class HuffmanTree {
    public:
    HuffmanTree() = default;
    ~HuffmanTree();

    static HuffmanTree buildFromHeader(const std::vector<std::pair<std::string, std::string>>& headerIn);
    error_type decode(std::ifstream&, std::ofstream&);

private:
    TreeNode* root {nullptr};
     void destroyTree(TreeNode*) noexcept;
     void buildTree(const std::string& address, const std::string& word);


};


#endif //P4_DECODEHUFFMAN_HUFFMANTREE_H