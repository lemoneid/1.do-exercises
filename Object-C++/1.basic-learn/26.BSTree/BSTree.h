/*************************************************************************
	> File Name: BSTree.h
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 18时59分44秒
 ************************************************************************/

#ifndef _BSTREE_H
#define _BSTREE_H

#include <memory>
#include <iostream>
namespace worst {

template<typename T>
class BSNode {
public :
    BSNode(const T &data) : data(data), lchild(nullptr), rchild(nullptr), father() {
        std::cout << "Node constructor" << std::endl;
    }
    bool operator<(const BSNode<T> &obj) {
        return this->data < obj.data;
    }
    bool operator>(const BSNode<T> &obj) {
        return obj.data < this->data;
    }
    bool operator!=(const BSNode<T> &obj) {
        return ((*this) < obj || (*this) > obj);
    }
    bool operator==(const BSNode<T> &obj) {
        return !((*this) != obj);
    }
    std::weak_ptr<BSNode<T> > father; //为什么是弱指针
    std::shared_ptr<BSNode<T>> lchild, rchild;
    ~BSNode() {
        std::cout << "Node destructor" << std::endl;
    }
    T data;
};

template<typename T>
class BSTree_helper {
public :
    static std::shared_ptr<BSNode<T> > get_next(std::shared_ptr<BSNode<T> > p) {
        if (p->rchild != nullptr) {
            p = p->rchild;
            while (p->lchild != nullptr) p = p->lchild;
            return p;
        }
        while (p->father.lock() != nullptr && p->father.lock()->rchild == p) p = p->father.lock();
        if (p->father.lock() == nullptr) return p;
        return p->father.lock();
    }
    static std::shared_ptr<BSNode<T> > get_most_left(std::shared_ptr<BSNode<T> > p) {
        while (p && p->lchild != nullptr) p = p->lchild;
        return p;
    }
};

template<typename T>
class BSTree_iterator {
using helper = BSTree_helper<T>;
public :
    BSTree_iterator() : node(nullptr) {}
    BSTree_iterator(std::shared_ptr<BSNode<T> > node) : node(node) {}
    BSTree_iterator<T> &operator++() {
        node = helper::get_next(node);
        return *this;
    }
    BSTree_iterator<T> operator++(int) {
        BSTree_iterator iter(*this);
        node = helper::get_next(node);
        return iter;
    }
    bool operator==(const BSTree_iterator<T> &iter) {
        return this->node == iter.node;
    }
    bool operator!=(const BSTree_iterator<T> &iter) {
        return !((*this) == iter);
    }
    T &operator*() {
        return node->data;
    }

private :
    std::shared_ptr<BSNode<T> > node;
};

template<typename T>
class BSTree {
using helper = BSTree_helper<T>;
public :
    typedef BSTree_iterator<T> iterator;
    BSTree() : root(std::make_shared<BSNode<T> >(T())) {}
    void insert(const T &data) {
        std::shared_ptr<BSNode<T> > p = this->root;
        std::shared_ptr<BSNode<T> > new_node = std::make_shared<BSNode<T> >(data);
        if (p->lchild == nullptr) {
            new_node->father = p;
            p->lchild = new_node;
            return ;
        }
        p = p->lchild;
        while (*p != *new_node) {
            if (*p > *new_node) {
                if (p->lchild == nullptr) {
                    p->lchild = new_node;
                    new_node->father = p;
                    break;
                }
                p = p->lchild;
            }  else {
                if (p->rchild == nullptr) {
                    p->rchild = new_node;
                    new_node->father = p;
                    break;
                }
                p = p->rchild;
            }
        }
        return ;
    }
    iterator begin() {
        if (root->lchild == nullptr) return iterator(root);
        return iterator(helper::get_most_left(root));
    }
    iterator end() {
        return iterator(root);
    }
private : 
    std::shared_ptr<BSNode<T> > root;
};
}
#endif
