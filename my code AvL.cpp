#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* lchild;
    node* rchild;
    int height;
    node(int d) {
        data = d;
        lchild = rchild = NULL;
        height = 1;
    }
};

class AVL {
    node* root;

public:
    AVL() {
        root = NULL;
    }

    int getheight(node* n) {
        return n ? n->height : 0;
    }

    int getbalance(node* n) {
        return n ? getheight(n->lchild) - getheight(n->rchild) : 0;
    }

    node* LLRotation(node* p) {
        node* pl = p->lchild;
        node* plr = pl->rchild;

        pl->rchild = p;
        p->lchild = plr;

        p->height = 1 + max(getheight(p->lchild), getheight(p->rchild));
        pl->height = 1 + max(getheight(pl->lchild), getheight(pl->rchild));

        if (p == root)
            root = pl;

        return pl;
    }

    node* RRRotation(node* p) {
        node* pr = p->rchild;
        node* prl = pr->lchild;

        pr->lchild = p;
        p->rchild = prl;

        p->height = 1 + max(getheight(p->lchild), getheight(p->rchild));
        pr->height = 1 + max(getheight(pr->lchild), getheight(pr->rchild));

        if (p == root)
            root = pr;

        return pr;
    }

    node* LRRotation(node* p) {
        node* pl = p->lchild;
        node* plr = pl->rchild;

        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;

        plr->lchild = pl;
        plr->rchild = p;

        p->height = 1 + max(getheight(p->lchild), getheight(p->rchild));
        pl->height = 1 + max(getheight(pl->lchild), getheight(pl->rchild));
        plr->height = 1 + max(getheight(plr->lchild), getheight(plr->rchild));

        if (p == root)
            root = plr;

        return plr;
    }

    node* RLRotation(node* p) {
        node* pr = p->rchild;
        node* prl = pr->lchild;

        pr->lchild = prl->rchild;
        p->rchild = prl->lchild;

        prl->rchild = pr;
        prl->lchild = p;

        p->height = 1 + max(getheight(p->lchild), getheight(p->rchild));
        pr->height = 1 + max(getheight(pr->lchild), getheight(pr->rchild));
        prl->height = 1 + max(getheight(prl->lchild), getheight(prl->rchild));

        if (p == root)
            root = prl;

        return prl;
    }

    node* insert(int key, node* r) {
        if (r == NULL) {
            return new node(key);
        }

        if (key < r->data)
            r->lchild = insert(key, r->lchild);
        else if (key > r->data)
            r->rchild = insert(key, r->rchild);
        else
            return r; // duplicate keys not allowed

        r->height = 1 + max(getheight(r->lchild), getheight(r->rchild));

        int balance = getbalance(r);

        if (balance > 1 && key < r->lchild->data)
            return LLRotation(r);
        if (balance < -1 && key > r->rchild->data)
            return RRRotation(r);
        if (balance > 1 && key > r->lchild->data)
            return LRRotation(r);
        if (balance < -1 && key < r->rchild->data)
            return RLRotation(r);

        return r;
    }

    void inorder(node* r) {
        if (r == NULL)
            return;
        inorder(r->lchild);
        cout << r->data << " ";
        inorder(r->rchild);
    }

    void print() {
        if (root)
            cout << "The root is: " << root->data << endl;
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void create(int key) {
        root = insert(key, root);
    }
};

int main() {
    AVL obj;
    obj.create(1);
    obj.create(4);
    obj.create(8);
    obj.create(2); // optional test insert
    obj.print();
    return 0;
}
