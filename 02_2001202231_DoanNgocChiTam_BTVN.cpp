#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef int data;
struct SV{
	char MaSV[20];
	char HoTen[50];
	int NamSinh;
};
struct Node{
	SV info;
	Node *next;
};
struct SList{
	Node *head;
	Node *tail;
};
struct Class{
	char MaLop[20];
	int SiSo;
	SList DSSV;
};
Node* TaoNode(data x)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	else
	{
		p->info = x;
		p->next = NULL;
		return p;
	}
}
void addHeadSList(SList &l, Node* p)
{
	if (p == NULL)
		return;
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void addTailSList(SList &l, Node* p)
{
	if (p == NULL)
		return;
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void nhapSList(SList &l)
{
	int n;
	do
	{
		printf("ban muon nhap dslk co bao nhieu sinh vien: ");
		scanf("%d", &n);
	} while (n <= 0);
	l.head = l.tail = NULL;
	for (int i = 0; i < n; i++)
	{
		int x;
		printf("nhap gia tri muon them: ");
		scanf("%d", &x);
		Node* node = TaoNode(x);
		addTailSList(l, node);
	}
}

void printSList(SList l)
{
	for (Node* i = l.head; i != NULL; i = i->next)
	{
		//xu ly node i
		printf("%5d", i->info);
	}
}
void main()
{
	SList l;
	nhapSList(l);
	printSList(l);
	getch();
}