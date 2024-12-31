#pragma once
#include <iostream>
using namespace std;

template <typename T>
class List 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) 
        {
        
        }
    };

    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) 
    {
    
    }

    void AddToHead(T value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = head;
    }

    void AddToTail(T value) 
    {
        Node* newNode = new Node(value);
        if (tail) 
        {
            tail->next = newNode;
        }
        else 
        {
            head = newNode;
        }
        tail = newNode;
    }

    void DeleteFromHead() 
    {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
    }

    void DeleteFromTail()
    {
        if (!head) return;
        if (head == tail) 
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* current = head;
        while (current->next != tail) 
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void DeleteAll() 
    {
        while (head) 
        {
            DeleteFromHead();
        }
    }

    void Show() 
    {
        Node* current = head;
        while (current) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void InsertAt(int position, T value) 
    {
        if (position <= 0) 
        {
            AddToHead(value);
            return;
        }
        Node* current = head;
        for (int i = 1; i < position && current; i++) 
        {
            current = current->next;
        }
        if (!current) 
        {
            AddToTail(value);
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
    }

    void DeleteAt(int position) 
    {
        if (position <= 0) 
        {
            DeleteFromHead();
            return;
        }
        Node* current = head;
        for (int i = 1; i < position && current->next; i++) 
        {
            current = current->next;
        }
        if (!current->next) return;
        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) 
        {
            tail = current;
        }
        delete temp;
    }

    int Find(T value) 
    {
        Node* current = head;
        int position = 0;
        while (current) 
        {
            if (current->data == value) 
            {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    int Replace(T oldValue, T newValue) 
    {
        Node* current = head;
        int count = 0;
        while (current) 
        {
            if (current->data == oldValue) 
            {
                current->data = newValue;
                count++;
            }
            current = current->next;
        }
        return count > 0 ? count : -1;
    }

    void Reverse() 
    {
        Node* prev = nullptr;
        Node* current = head;
        tail = head;
        while (current) 
        {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    ~List() 
    {
        DeleteAll();
    }
};