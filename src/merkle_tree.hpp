#ifndef MERKLE_H
#define MERKLE_H

#include <array>
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

#include "sha256.hpp"

class MerkleTreeNode {
 public:
  string data;
  shared_ptr<MerkleTreeNode> left;
  shared_ptr<MerkleTreeNode> right;

  MerkleTreeNode(string data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class MerkleTree {
 public:
  shared_ptr<MerkleTreeNode> root;
  vector<MerkleTreeNode> leaf_nodes;

  void initialize(vector<string> transactions)
  {
    for (auto transaction : transactions) {
      this->leaf_nodes.push_back(MerkleTreeNode(transaction));
    }
  }

  /* alters the vector to have even no of elements to support binary tree */
  void make_even(vector<shared_ptr<MerkleTreeNode>> &q)
  {
    if (q.size() & 1) {
      auto extra_node = q[q.size() - 1];
      q.push_back(extra_node);
    }
  }

  /* build the merkle tree in a bottom up fashion */
  void build()
  {
    vector<shared_ptr<MerkleTreeNode>> q;
    for (auto node : leaf_nodes) {
      q.push_back(shared_ptr<MerkleTreeNode>(new MerkleTreeNode(sha256(node.data))));
    }
    this->make_even(q);

    while (q.size() > 1) {
      /* for (auto node : q) { */
      /*   cout << node->data << endl; */
      /* } */
      /* cout << endl << endl; */
      /* auxillary ds used for swapping out with q */
      vector<shared_ptr<MerkleTreeNode>> temp;
      this->make_even(q);
      for (int ix = 0; ix < q.size(); ix += 2) {
        /* creating parent for adjacent children */
        shared_ptr<MerkleTreeNode> new_node(
            new MerkleTreeNode(sha256(q[ix]->data + q[ix + 1]->data)));
        new_node->left = shared_ptr<MerkleTreeNode>(q[ix]);
        new_node->right = shared_ptr<MerkleTreeNode>(q[ix + 1]);

        temp.push_back(new_node);
      }
      q = temp;
    }

    /* setting root */
    this->root = q[0];
  }

  void display()
  {
    cout << "leaf_nodes: ";
    for (auto node : leaf_nodes) {
      cout << node.data << " ";
    }
    cout << "\n";
    cout << "merkle_root_hash: " << this->root->data << endl;
    cout << "actual expected hash: "
         << sha256(sha256(sha256("100") + sha256("101")) + sha256(sha256("102") + sha256("102")))
         << endl;
  }
};

#endif
