#ifndef TREE_H
#define TREE_H

template <typename T>

class Tree:public Object
{
protected:
    TreeNode<T> *m_root;
public:
    Tree(){m_root = NULL};

};

#endif // TREE_H
