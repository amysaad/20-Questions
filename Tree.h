#ifndef TREE
#define TREE
#include "Node.h"
#include "fstream"


class Tree
{
public:

    void SaveTreeToFile(string outputFileName);
    void ReadTreeFromFile(string inputFileName);

    Tree();													// Default CTOR
    //..........................................
    //POST: new tree is created with a root


    Tree(string questionText, string leftObject, string rightObject);	// CTOR when root info is known
    //..........................................
    //POST: new tree is created with a root with text questionText, plus two children:
    //		right child has text of rightObject, and left child has text of leftObject


    ~Tree();												// DTOR
    //..........................................
    //POST: entire tree is deleted/freed and all dynamic memory cleared

    void DeleteAll(Node* pNode);


    bool IsEmpty(void) const;
    //..........................................
    //POST: RETURN T/F whether or not the root node of the Tree has children


    Node* GetRoot(void) const;
    //..........................................
    //POST: RETURN == address of root node


private:
    Node* root;    // pointer to root node of tree


    ofstream FOUT;
    ifstream FIN;

    // private methods
    void  RecursiveNodeSAVEtoFile(Node* root);
    Node* RecursiveNodeREADfromFile( );

};// class Tree

#endif
