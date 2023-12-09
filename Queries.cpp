#include <iostream>

class Node {
public:
    int value;
    Node *next;

    Node(int value) : value(value), next(nullptr) {}
};

// Insert at the head
void insert_head(Node *&head, int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at the tail
void insert_tail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Delete at the specified index
void delete_at_index(Node *&head, int index) {
    if (head == nullptr || index < 0) {
        return;
    }

    if (index == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
    } else {
        Node *current = head;
        for (int i = 0; i < index - 1 && current->next != nullptr; ++i) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return; // Index is invalid
        }

        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Print the linked list
void print_list(Node *head) {
    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;
    int Q, X, V;

    std::cin >> Q;

    for (int i = 0; i < Q; ++i) {
        std::cin >> X >> V;

        if (X == 0) {
            insert_head(head, V);
        } else if (X == 1) {
            insert_tail(head, tail, V);
        } else if (X == 2) {
            delete_at_index(head, V);
        }

        print_list(head);
    }

    // Free allocated memory for the linked list
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
