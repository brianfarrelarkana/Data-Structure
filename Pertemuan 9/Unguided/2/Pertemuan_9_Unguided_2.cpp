#include <iostream>

using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init()
{
    root = NULL;
}

int isEmpty()
{
    if (root == NULL)
        return 1;
    else
        return 0;
}

void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon* cariNodeHelper(Pohon* currNode, char simpul)
{
    if (currNode != nullptr)
    {
        if (currNode->data == simpul)
        {
            return currNode;
        }
        else
        {
            Pohon* foundNode = cariNodeHelper(currNode->left, simpul);
            if (foundNode == nullptr)
            {
                foundNode = cariNodeHelper(currNode->right, simpul);
            }
            return foundNode;
        }
    }
    else
    {
        return nullptr;
    }
}

Pohon* cariNode(char simpul)
{
    if (root == nullptr)
    {
        cout << "Pohon masih kosong.\n";
        return nullptr;
    }
    else
    {
        return cariNodeHelper(root, simpul);
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (root == NULL)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

void preOrder(Pohon *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

void inOrder(Pohon *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

void postOrder(Pohon *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

void deleteTree(Pohon *node)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

void deleteSub(Pohon *node)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

void clear()
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

int size(Pohon *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

int height(Pohon *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

void charateristic()
{
    cout << "\nKarakteristik Pohon\n";
    cout << "\nSize Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    char simpul, ortu, x;
    int jumlah, pilih_2211102352;
    Pohon *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9;

    cout << "\nSelamat datang di menu program tree\n";

    while (true)
    {
        cout << "\nSilakan pilih opsi di bawah ini\n\n";
        cout << "1.  Buat akar\n";
        cout << "2.  Masukkan node kiri\n";
        cout << "3.  Masukkan node kanan\n";
        cout << "4.  Update node\n";
        cout << "5.  Retrieve node\n";
        cout << "6.  Find node\n";
        cout << "7.  Tampilkan pohon secara Pre-Order\n";
        cout << "8.  Tampilkan pohon secara In-Order\n";
        cout << "9.  Tampilkan pohon secara Post-Order\n";
        cout << "10. Tampilkan karakteristik pohon\n";
        cout << "11. Hapus sub pohon\n";
        cout << "12. Hapus pohon\n";
        cout << "13. Keluar\n";
        cout << "\nMasukkan pilihan anda : "; cin >> pilih_2211102352;
        switch (pilih_2211102352)
        {
        case 1:
            cout << "\nMasukkan nama node akar : "; cin >> simpul;
            buatNode(simpul);
            break;

        case 2:
            cout << "\nMasukkan nama node kiri      : "; cin >> simpul;
            cout << "Masukkan nama node orang tua : "; cin >> ortu;
            insertLeft(simpul, cariNode(ortu));
            break;

        case 3:
            cout << "\nMasukkan nama node kanan     : "; cin >> simpul;
            cout << "Masukkan nama node orang tua : "; cin >> ortu;
            insertRight(simpul, cariNode(ortu));
            break;

        case 4:
            cout << "\nMasukkan nama node yang ingin diubah : "; cin >> simpul;
            cout << "Masukkan nama node baru              : "; cin >> x;
            update(x, cariNode(simpul));
            break;

        case 5:
            cout << "\nMasukkan nama node yang ingin dilihat : "; cin >> simpul;
            retrieve(cariNode(simpul));
            break;

        case 6:
            cout << "\nMasukkan nama node yang ingin dicari : "; cin >> simpul;
            find(cariNode(simpul));
            break;

        case 7:
            cout << "\nPohon secara Pre-Order\n";
            preOrder(root);
            break;

        case 8:
            cout << "\nPohon secara In-Order\n";
            inOrder(root);
            break;

        case 9:
            cout << "\nPohon secara Post-Order\n";
            postOrder(root);
            break;

        case 10:
            charateristic();
            break;

        case 11:
            cout << "\nMasukkan nama node yang sub tree nya akan dihapus : "; cin >> simpul;
            deleteSub(cariNode(simpul));
            break;

        case 12:
            clear();
            break;

        case 13:
            return 0;

        default:
            cout << "\nPilihan yang anda masukkan tidak tersedia\n";
        }
        cout << "\n" << endl;
    }
    return 0;
}