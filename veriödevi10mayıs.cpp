#include<iostream>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
int yapraksayisi = 0;
int nodesayisi = 0;
struct node {
	int data;
	node* llink;
	node* rlink;
};
int say(node* root)
{
	if (root == NULL) return 0;
	if (root->llink == NULL && root->rlink == NULL)
		return yapraksayisi++;
	
	return nodesayisi=  yapraksayisi+ say(root->llink) + say(root->rlink);
}
node* root = NULL;
node* newnode() {
	node* node_ = new node;
	node_->llink = NULL;
	node_->rlink = NULL;
	cout << "ağaçtaki yeni node'un datasını giriniz:";
	cin >> node_->data;
	return(node_);
}
void inserttree(node*& root, node* node_)
{
	if (root==NULL) {
		root = node_;
		return;
	}
	if (root->data > node_->data)
		inserttree(root->llink, node_);
	else
		inserttree(root->rlink, node_);
}
void printtree(node* root)
{
	if (root == NULL) return;
	if(root->llink!=NULL)
	printtree(root->llink);
	cout << root->data << endl;
	if (root->rlink != NULL)
	printtree(root->rlink);
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	int yaprak = 0;
	cout << "kaç nodelu ağaç oluşturmak istersiniz?:";
	cin >> yaprak;
	cout << endl;
	for (int i = 0; i < yaprak; i++)
	{
		node* ekleneceknode=newnode();
		inserttree(root, ekleneceknode);
	}
	cout << "Ağaç:" << endl;
	printtree(root);
	say(root);
	cout << "ağaçta " << nodesayisi << " tane node vardır." << endl;
	cout << "ağaçta " << yapraksayisi << " tane yaprak vardır." << endl;
	return 0;
}