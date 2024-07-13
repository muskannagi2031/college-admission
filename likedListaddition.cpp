#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add a node at the beginning
    void addAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to add a node at the end
    void addAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to add a node at a specific position
    void addAtPosition(int val, int position) {
        if (position <= 0) {
            addAtBeginning(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 0; i < position - 1; i++) {
            if (temp == nullptr) {
                std::cout << "Position out of bounds" << std::endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Position out of bounds" << std::endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    
     void deleteFirstNode() {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete the last node
    void deleteLastNode() {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Function to delete a node at a specific position
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        if (position == 0) {
            deleteFirstNode();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) {
                std::cout << "Position out of bounds" << std::endl;
                return;
            }
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        if (nodeToDelete == nullptr) {
            std::cout << "Position out of bounds" << std::endl;
            return;
        }

        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    
    // Function to Sort linked list
    void sort() {
      Node *current = head, *index = nullptr;
        int temp;

        if (head == nullptr) {
            return;
        } else {
            while (current != nullptr) {
                index = current->next;

                while (index != nullptr) {
                    if (current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }

    
    // Function to search a node at given position in linked list
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    

    // Function to print the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
  
    LinkedList list;
    int choice;
    int value;
    int position;

    do {
        std::cout << "\nLinked List Operations Menu:\n";
        std::cout << "1. Add Node at Start\n";
        std::cout << "2. Add Note at End\n";
        std::cout << "3. Add Node at given position\n";
        std::cout << "4. Delete Node at Start\n";
        std::cout << "5. Delete Note at End\n";
        std::cout << "6. Delete Node at given position\n";
        std::cout << "7. Sort List\n";
        std::cout << "8. Search List at given position\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to add at start: ";
                std::cin >> value;
                list.addAtBeginning(value);
                list.printList();
                break;
            case 2:
                std::cout << "Enter value to add at End: ";
                std::cin >> value;
                list.addAtEnd(value);
                list.printList();
                break;
            case 3:
                std::cout << "Enter position: ";
                std::cin >> position;
                std::cout << "Enter value to add at given position: ";
                std::cin >> value;
                list.addAtPosition(value,position);
                list.printList();
                break;
            case 4:
                list.deleteFirstNode();
                std::cout << "Delete Node at Start.\n";
                list.printList();
                break;
            case 5:
                list.deleteLastNode();
                std::cout << "Delete Node at End.\n";
                list.printList();
                break;
            case 6:
                std::cout << "Delete Node at given position.\n";
                std::cin >> position;
                list.deleteAtPosition(position);
                list.printList();
                break;
            case 7:
                list.sort();
                std::cout << "Sort List\n";
                list.printList();
                break;
            case 8:
                std::cout << "Search List at given position.\n";
                std::cin >> position;
                list.search(position);
                list.printList();
            case 9:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter again.\n";
                break;
        }

    } while (choice != 9);

    return 0;
    
}
