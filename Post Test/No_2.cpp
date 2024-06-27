#include <iostream>

using namespace std;

struct Pohon
{
    char data2211102352;
    Pohon *left2211102352, *right2211102352, *parent2211102352;
};

Pohon *root2211102352, *baru2211102352;

void init()
{
    root2211102352 = NULL;
}

int isEmpty()
{
    if (root2211102352 == NULL)
        return 1;
    else
        return 0;
}

void buatNode(char data2211102352)
{
    if (isEmpty() == 1)
    {
        root2211102352 = new Pohon();
        root2211102352->data2211102352 = data2211102352;
        root2211102352->left2211102352 = NULL;
        root2211102352->right2211102352 = NULL;
        root2211102352->parent2211102352 = NULL;
        cout << "\nNode " << data2211102352 << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data2211102352, Pohon *node2211102352)
{
    if (node2211102352->left2211102352 != NULL)
    {
        cout << "\nNode " << node2211102352->data2211102352 << " sudah ada child kiri!" << endl;
        return NULL;
    }
    else
    {
        baru2211102352 = new Pohon();
        baru2211102352->data2211102352 = data2211102352;
        baru2211102352->left2211102352 = NULL;
        baru2211102352->right2211102352 = NULL;
        baru2211102352->parent2211102352 = node2211102352;
        node2211102352->left2211102352 = baru2211102352;
        cout << "\nNode " << data2211102352 << " berhasil ditambahkan ke child kiri " << baru2211102352->parent2211102352->data2211102352 << endl;
        return baru2211102352;
    }
}

Pohon *insertRight(char data2211102352, Pohon *node2211102352)
{
    if (node2211102352->right2211102352 != NULL)
    {
        cout << "\nNode " << node2211102352->data2211102352 << " sudah ada child kanan!" << endl;
        return NULL;
    }
    else
    {
        baru2211102352 = new Pohon();
        baru2211102352->data2211102352 = data2211102352;
        baru2211102352->left2211102352 = NULL;
        baru2211102352->right2211102352 = NULL;
        baru2211102352->parent2211102352 = node2211102352;
        node2211102352->right2211102352 = baru2211102352;
        cout << "\nNode " << data2211102352 << " berhasil ditambahkan ke child kanan " << baru2211102352->parent2211102352->data2211102352 << endl;
        return baru2211102352;
    }
}

void inOrder(Pohon *node2211102352 = root2211102352)
{
    if (!root2211102352)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node2211102352 != NULL)
        {
            inOrder(node2211102352->left2211102352);
            cout << " " << node2211102352->data2211102352 << ", ";
            inOrder(node2211102352->right2211102352);
        }
    }
}

void postOrder(Pohon *node2211102352 = root2211102352)
{
    if (!root2211102352)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node2211102352 != NULL)
        {
            postOrder(node2211102352->left2211102352);
            postOrder(node2211102352->right2211102352);
            cout << " " << node2211102352->data2211102352 << ", ";
        }
    }
}

int main()
{
    buatNode('A');
    Pohon *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8;

    node1 = insertLeft('B', root2211102352);
    node2 = insertRight('F', root2211102352);
    node3 = insertLeft('C', node1);
    node4 = insertRight('E', node2);
    node5 = insertRight('H', node3);
    node6 = insertLeft('Z', node5);
    node7 = insertLeft('D', node4);
    node8 = insertRight('G', node4);

    cout << "\n\nInOrder :" << endl;
    inOrder(root2211102352);

    cout << "\n\nPostOrder :" << endl;
    postOrder(root2211102352);
}