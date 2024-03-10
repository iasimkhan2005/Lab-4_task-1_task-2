#include <iostream>
#include <list>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(int value) const {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* temp = head;
        Node* nextNode = nullptr;

        while (temp) {
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }

        head = prev;
    }
    //Task # 2
    void Sort() {
        list<int> t;
        Node* temp = head;

        while (temp) {
            t.push_back(temp->data);
            temp = temp->next;
        }

        t.sort();

        temp = head;
        auto it = t.begin();

        while (temp) {
            temp->data = *it;
            temp = temp->next;
            ++it;
        }
    }

    void mergeLists(const LinkedList& otherList) {
        Node* temp = head;

        while (temp->next) {
            temp = temp->next;
        }

        Node* otherTemp = otherList.head;

        while (otherTemp) {
            append(otherTemp->data);
            otherTemp = otherTemp->next;
        }
    }

    ~LinkedList() {
        Node* temp = head;
        Node* nextNode = nullptr;

        while (temp) {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList myList1;
    LinkedList myList2;

    myList1.append(3);
    myList1.append(1);
    myList1.append(2);

    myList2.append(6);
    myList2.append(4);
    myList2.append(5);

    cout << "List 1: ";
    myList1.display();

    cout << "List 2: ";
    myList2.display();

    //Task # 2  
    myList1.Sort();
    myList1.display();

    myList1.mergeLists(myList2);
    cout << "Merged List: ";
    myList1.display();

    return 0;
}
