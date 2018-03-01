#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

/*
    Using the phonebook generator outside, random_gen_phonebook.py to generate the testdata

    Implement the huffman code tree
*/

// Data structure
struct huffman_tree{
    // huffman code
    std::string huffman_code();
    int size;
    char orig;
    // truncate 
    struct huffman_tree *left;
    struct huffman_tree *right;
    struct huffman_tree *parent;
};

// create vector for huffman usage
std::vector<huffman_tree *> tree;

// for sorting
bool comp(huffman_tree *lvalue,huffman_tree *rvalue){
    return (lvalue->size > rvalue->size);
}

// traversal
void traversal(huffman_tree *root,std::string str){
    if(root->left!=NULL)
        traversal(root->left,str+std::string("0"));
    if(root->right!=NULL)
        traversal(root->right,str+std::string("1"));
    if(root->left==NULL && root->right==NULL)
        printf("Character: %c, with size: %d, have huffman code: %s\n",root->orig,root->size,str.c_str());
    
    return;
}

// Main 
int main(){
    // read input from stdin
    char c;
    int counter[127];
    for(int i=0;i<127;i++)
        counter[i]=0;

    while(scanf("%c",&c)!=EOF){
        if(c!='\n'){
            counter[(int)c]++;
        }
    }

    for(int i=33;i<127;i++){
        huffman_tree *newnode=(huffman_tree*)malloc(sizeof(huffman_tree));
        newnode->size=counter[i];
        newnode->orig=(char)i;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->parent=NULL;
        // push into
        tree.push_back(newnode);
    }

    // loop
    while(tree.size()!=1){
        // Step 1: sorting
        std::sort(tree.begin(),tree.end(),comp);
        // Step 2: pop out the last 2 element
        huffman_tree *node1,*node2,*result=(huffman_tree*)malloc(sizeof(huffman_tree));
        node1 = tree.back();
        tree.pop_back();
        node2 = tree.back();
        tree.pop_back();
        // create new node, as these 2 elements' parent node
        result->size=(node1->size)+(node2->size);
        // truncate these 3 node
        if(node1->size > node2->size){
            result->left = node2;
            result->right = node1;
        }
        else{
            result->left = node1;
            result->right = node2;
        }
        node1->parent=result;
        node2->parent=result;
        // push this new node back to tree
        tree.push_back(result);
    }

    // now the only element in "tree" is the root of huffman tree
    printf("Root node is here, with size: %d\n",tree.at(0)->size);
    
    // traversal, and print out huffman encoding
    traversal(tree.at(0),std::string(""));

    // we can construct the huffman tree - encode

    // print 
    /*for(std::vector<huffman_tree>::iterator it=tree.begin(); it!=tree.end(); ++it){
        printf("%c: %d\n", (*it).orig, (*it).size);
    }*/

    return 0;
}