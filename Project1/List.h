#pragma once

#ifndef LINK_H

#define LINK_H

#include "Node.h"

#include <iostream>

#include <fstream>

#include <string>

template <class T>

class List

{

public:

	List();//Ĭ�Ϲ��캯��

	List(const List& ln);//�������캯��

	void Copy(const List & ln);

	~List();//��������

	void add(T e);//�������������

	void ascSort();//��������

	void remove(T index);//�Ƴ�ĳ�����

	T find(int index);//���ҽ��

	bool isEmpty();//�ж��Ƿ�Ϊ��

	int size();//������

	int getcharcount();//���ַ�����

	void show();//��ʾ����

	void resShow();	//��������ʾ

	void removeAll();//ɾ��ȫ�����

private:

	Node<T> *head;

	Node<T> *tail;

	int length;

	int charcount;

};



//////////////////////////////////////////////////////////////////////////////////

//Ĭ�Ϲ��캯��

template <typename T>

List<T>::List()

{

	head = new Node<T>;

	tail = new Node<T>;

	head->next = tail;

	head->prev = nullptr;

	tail->next = nullptr;

	tail->prev = head;

	length = 0;

	charcount = 0;

}

//�������캯��

template <typename T>

List<T>::List(const List &ln)

{

	head = new Node<T>;

	head->prev = nullptr;

	tail = new Node<T>;

	head->next = tail;

	tail->prev = head;

	length = 0;

	charcount = 0;

	Node<T>* temp = ln.head;

	while (temp->next != ln.tail)

	{

		temp = temp->next;

		tail->data = temp->data;

		Node<T> *p = new Node<T>;

		p->prev = tail;

		tail->next = p;

		tail = p;

		length++;

		charcount = charcount + tail->prev->data.getLen();

	}

	tail->next = nullptr;

}

//��������
template <typename T>

void List<T>::Copy(const List &ln)

{

	head = new Node<T>;

	head->prev = nullptr;

	tail = new Node<T>;

	head->next = tail;

	tail->prev = head;

	length = 0;

	charcount = 0;

	Node<T>* temp = ln.head;

	while (temp->next != ln.tail)

	{

		temp = temp->next;

		tail->data = temp->data;

		Node<T> *p = new Node<T>;

		p->prev = tail;

		tail->next = p;

		tail = p;

		length++;

		charcount = charcount + tail->prev->data.getLen();

	}

	tail->next = nullptr;

}

//�������������

template <typename T>

void List<T>::add(T e)

{

	Node<T>* temp = this->tail;

	tail->data = e;

	tail->next = new Node<T>;

	Node<T> *p = tail;

	tail = tail->next;

	tail->prev = p;

	tail->next = nullptr;

	length++;

	charcount = charcount + tail->prev->data.getLen();

}

//���ҽ��

template <typename T>

T List<T>::find(int index)

{
	T emp;

	if (length == 0)

	{

		//std::cout << "List is empty";

		return emp;

	}

	if (index >= length)

	{

		/// std::cout << "Out of bounds";

		return emp;

	}

	int x = 0;

	T data;

	Node<T> *p;

	if (x < length / 2)

	{

		p = head->next;

		while (p->next != nullptr && x++ != index)

		{

			p = p->next;

		}

	}
	else {

		p = tail->prev;

		while (p->prev != nullptr && x++ != index)

		{

			p = p->prev;

		}

	}

	return p->data;

}

//ɾ�����

template <typename T>

void List<T>::remove(T index)

{

	if (length == 0)

	{

		std::cout << "List is empty";

		return;

	}

	Node<T> *p = head;

	while (p->next != nullptr)

	{

		p = p->next;

		if (p->data.getWord().compare(index.getWord()) == 0)

		{

			charcount = charcount - p->data.getLen();

			Node<T> *temp = p->prev;

			temp->next = p->next;

			p->next->prev = temp;

			delete p;

			length--;

			return;

		}

	}

}

//ɾ�����н��

template <typename T>

void List<T>::removeAll()

{

	if (length == 0)

	{

		return;

	}

	Node<T> *p = head->next;

	while (p != tail)

	{

		Node<T>* temp = p;

		p = p->next;

		delete temp;

	}

	head->next = tail;

	tail->prev = head;

	length = 0;

	charcount = 0;

}

//��������

template <typename T>

void List<T>::ascSort()

{

	if (length <= 1) return;

	Node<T> *p = head->next;

	for (int i = 0; i < length - 1; i++)

	{

		Node<T> *q = p->next;

		for (int j = i + 1; j < length; j++)

		{

			if (p->data > q->data)

			{

				T temp = q->data;

				q->data = p->data;

				p->data = temp;

			}

			q = q->next;

		}

		p = p->next;

	}

}

//�ж��Ƿ�Ϊ��

template <typename T>

bool List<T>::isEmpty()

{

	if (length == 0)

	{

		return true;

	}
	else {

		return false;

	}

}

//������

template <typename T>

int List<T>::size()

{

	return length;

}

//�ַ�����

template <typename T>

int List<T>::getcharcount()

{

	return charcount;

}

//�������

template <typename T>

void List<T>::show()

{

	if (length == 0)

	{

		std::cout << "List is empty" << std::endl;

		return;

	}

	Node<T> *p = head->next;

	while (p != tail)

	{

		std::cout << p->data.getWord() << " ";

		p = p->next;

	}

	std::cout << std::endl;

}

//�����������

template <typename T>

void List<T>::resShow()

{

	if (length == 0)return;

	Node<T> *p = tail->prev;

	while (p != head)

	{

		std::cout << p->data.getWord() << " ";

		p = p->prev;

	}

	std::cout << std::endl;

}


//��������

template <typename T>

List<T>::~List()

{

	if (length == 0)

	{

		delete head;

		delete tail;

		head = nullptr;

		tail = nullptr;

		return;

	}

	while (head->next != nullptr)

	{

		Node<T> *temp = head;

		head = head->next;

		delete temp;

	}

	delete head;

	head = nullptr;

}



#endif //TEST1_LINK_H
