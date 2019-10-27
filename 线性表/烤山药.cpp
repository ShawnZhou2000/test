#include <iostream>
#include <cstdio>   
#include <string>
#include <Windows.h>
#define OK 1  
#define ERROR 0  
#define OVERFLOW -2  
#define MAXSIZE 100  
using namespace std;
typedef int Status; // ���庯������ֵ����  

typedef struct {
	string num; // ѧ��  
	string name; // ����  
	double grade = 0.0; // �ɼ�   

}student;

typedef student ElemType;

typedef struct {
	ElemType* elem; // �洢�ռ�Ļ���ַ   
	int length; // ��ǰ����   

} SqList;

Status InitList(SqList* L) { // ����յ�˳��� L   
	L->elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (!L->elem)  
		exit(OVERFLOW);
	L->length = 0;
	return OK;
}

ElemType GetElem(SqList& L, int i) { // ����˳����ҵ� iλ�ã����ظ� e  
	return L.elem[i];
}

int Search(SqList& L, string str) { // �������ֲ��ң����ظ�ͬѧ��˳����еı��   
	for (int i = 1; i <= L.length; i++) {
		if (L.elem[i].name == str)
			return i;
	}
	return 0;
}

Status ListInsert(SqList& L, int i, ElemType e) { // �� iλ�ò���ĳ��ѧ������Ϣ   
	if ((i < 1) || (i > L.length + 1)) 
		return ERROR;
	if (L.length == MAXSIZE)   
		return ERROR;
	for (int j = L.length; j >= i; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i] = e;
	++L.length;
	return OK;
}

Status ListDelete(SqList& L, int i) { // ��˳�����ɾ�� iλ�õ�ѧ����Ϣ   
	if ((i < 1) || (i > L.length))   
		return ERROR;
	for (int j = i; j <= L.length; j++) {
		L.elem[j] = L.elem[j + 1];
	}
	--L.length;
	return OK;
}

void Input(ElemType* e) {
	cout << "������";
	cin >> e->name;
	cout << "ѧ��";
	cin >> e->num;
	cout << "�ɼ���";
	cin >> e->grade;
	cout << "������ɣ�\n\n";
}

void Output(ElemType* e) {
	cout << "\t" << e->name << "\t" << e->num << "\t" << e->grade << endl;
}

void PrintList() {
	cout << "\n\t\t\t\t\t\tѧ���ɼ�����ϵͳ" << endl;
	cout << "\t\t\t\t=========================================================" << endl;
	cout << "\t\t\t\t|\t\t1. ����˳���\t\t\t\t|\n";
	cout << "\t\t\t\t|\t\t2. ¼��ѧ����Ϣ\t\t\t\t|\n";
	cout << "\t\t\t\t|\t\t3. ��ʾѧ����Ϣ\t\t\t\t|\n";
	cout << "\t\t\t\t|\t\t4. �������������Ҹ�ѧ��\t\t\t|\n";
	cout << "\t\t\t\t|\t\t5. ��ʾĳλ�ø�ѧ����Ϣ\t\t\t|\n";
	cout << "\t\t\t\t|\t\t6. ��ָ��λ�ò���ѧ����Ϣ\t\t|\n";
	cout << "\t\t\t\t|\t\t7. ��ָ��λ��ɾ��ѧ����Ϣ\t\t|\n";
	cout << "\t\t\t\t|\t\t8. ͳ��ѧ������\t\t\t\t|\n";
	cout << "\t\t\t\t|\t\t0. �˳�\t\t\t\t\t|\n";
	cout << "\t\t\t\t=========================================================" << endl;
}

int main() {
	SqList L = SqList();
	ElemType a, b, c, d;
	int x = 0, choose;
	string s;
	bool isCreated = false;
	
	system("COLOR 71");
	system("TITLE ѧ���ɼ�����ϵͳ");

	while (1) {
		PrintList();
		cout << "��ѡ���Ӧ����Ŀ��ţ�" << endl;
		while (1) {
			cin >> choose;
			if (!((choose >= 1 && choose <= 8) || (choose == 0))) {
				system("cls");
				PrintList();
				cout << "�����������������룺";
			}
			else
				break;
		}

		if (choose == 0)   
			break;

		switch (choose) {
		case 1:
			if (InitList(&L)) {
				cout << "�ɹ�����˳���\n\n";
				system("pause");
				system("cls");
				isCreated = true;
			}
			else {
				cout << "˳�����ʧ��\n\n";
				system("pause");
				system("cls");
			}
			break;
		case 2:
			if (!isCreated) {
				cout << "����δ����˳���" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "������Ҫ¼��ѧ����������С��" << MAXSIZE << "��:";
			cin >> x;
		
			for (int i = 1; i <= x; i++) {
				cout << "��" << i << "��ѧ����" << endl;
				Input(&L.elem[i]);
			}
			L.length = x;
			cout << "���е�ѧ����Ϣ¼������ˣ�" << endl;
			system("pause");
			system("cls");
			
			break;
		case 3:
			if (!isCreated) {
				cout << "����δ����˳���" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "\t" << "����" << "\t" << "ѧ��" << "\t" << "�ɼ�" << endl;
			for (int i = 1; i <= x; i++) {
				a = GetElem(L, i);
				Output(&a);
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if (!isCreated) {
				cout << "����δ����˳���" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "������Ҫ���ҵ�ѧ��������";
			cin >> s;
			if (Search(L, s))
				Output(&L.elem[Search(L, s)]);
			else
				cout << "�Բ��𣬲��޴���" << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			if (!isCreated) {
				cout << "����δ����˳���" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "������Ҫ��ѯ��λ��:";
			int id1;
			cin >> id1;
			b = GetElem(L, id1);
			Output(&b);
			system("pause");
			system("cls");
			break;
		case 6:
			if (!isCreated) {
				cout << "����δ����˳���" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "������Ҫ�����λ��:";
			int id2;
			cin >> id2;
			cout << "������ѧ����Ϣ:" << endl;
			Input(&c);
			if (ListInsert(L, id2, c)) {
				x++;
				cout << "����ɹ�" << endl;
			}
			else {
				cout << "����ʧ��" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 7:
			if (!isCreated) {
				cout << "����δ����˳���" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "������Ҫɾ����λ��:";
			int id3;
			cin >> id3;
			if (ListDelete(L, id3)) {
				x--;
				cout << "ɾ���ɹ�" << endl;		
			}
			else {
				cout << "ɾ��ʧ��" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 8:
			if (!isCreated) {
				cout << "����δ����˳���" << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "��¼���ѧ������Ϊ:" << L.length << "\n" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	cout << "\n\nлл����ʹ�ã��밴������˳�\n\n\n";
	system("pause");
	return 0;
}
