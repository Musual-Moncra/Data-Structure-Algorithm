/* Danh sách liên kết đơn (Singly/One-way linked list) */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  // sử dụng hàm malloc()

// Lưu ý để truy xuất các thành phần, struct dùng dấu chấm (.) còn con trỏ dùng
// mũi tên (->)

// Định nghĩa một node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Định nghĩa một danh sách liên kết đơn
typedef struct SinglyLinkedList {
    Node *head;
} SinglyLinkedList;

// Khởi tạo danh sách rỗng
void init_list(SinglyLinkedList *list) { 
    list->head = NULL; 
}

// Kiểm tra xem danh sách có rỗng không
bool is_empty(SinglyLinkedList *list) {
    if (list->head == NULL) return true;
    return false;
}

// Tạo một node mới
Node* create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Tạo một danh sách mới
SinglyLinkedList* create_list() {
    SinglyLinkedList *list =
        (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    list->head = NULL;  // tương tự như init_list(list);
    return list;
}

// Duyệt và in danh sách
void display_list(SinglyLinkedList *list) {
    printf("Linked list: ");
    Node *current = list->head;
    if (current == NULL) {
        printf("Empty\n");
        return;
    }

    while (current != NULL) {
        // xử lý dữ liệu của mỗi node
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Tìm một phần tử trong danh sách
Node* search(SinglyLinkedList *list, int value) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* search_recursive(Node *current, int value) {
    if (current == NULL) {
        return NULL;
    }
    if (current->data == value) {
        return current;
    }
    return search_recursive(current->next, value);
}

// Thêm một phần tử vào đầu danh sách (các tham số đều là con trỏ)
void insert_head(SinglyLinkedList *list, Node *node) {
    node->next = list->head;
    list->head = node;
}

// Thêm một phần tử vào cuối danh sách
void insert_tail(SinglyLinkedList *list, Node *node) {
    if (list->head == NULL) {  // tương tự như is_empty(list)
        list->head = node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Thêm một phần tử vào vị trí sau node có giá trị value
void insert_after(SinglyLinkedList *list, int value, Node *node) {
    Node *current = list->head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    // trường hợp tìm thấy giá trị value
    if (current != NULL) {
        node->next = current->next;
        current->next = node;
    }
}

// Thêm các node vào danh sách theo thứ tự tăng dần của data
void insert_sorted(SinglyLinkedList *list, Node *node) {
    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL && current->data < node->data) {
        previous = current;
        current = current->next;
    }
    // thoát khỏi while chỉ có 2 trường hợp: current == NULL hoặc
    // current->data >= node->data, thì node sẽ được thêm vào trước current
    if (previous == NULL) {
        // trường hợp danh sách rỗng hoặc thêm vào đầu danh sách
        node->next = list->head;
        list->head = node;
    } else {
        // trường hợp thêm vào giữa hoặc cuối danh sách
        previous->next = node;
        node->next = current;
    }
}

// Xóa một phần tử đầu danh sách
void delete_head(SinglyLinkedList *list) {
    if (!is_empty(list)) {
        Node *current = list->head;
        list->head = current->next;
        free(current);
    }
}

// Xóa một phần tử cuối danh sách
void delete_tail(SinglyLinkedList *list) {
    if (list->head != NULL) {
        Node *current = list->head;
        Node *prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        } else {  // trường hợp list chỉ có 1 node
            list->head = NULL;
        }
        free(current);
    }
}

// Xóa một phần tử có giá trị value (được tìm thấy đầu tiên)
void delete(SinglyLinkedList *list, int value) {
    Node *current = list->head;
    Node *previous = NULL;  // để giữ node trước node cần xóa
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous != NULL) {
            previous->next = current->next;
        } else {
            list->head = current->next;
        }
        free(current);
    }
}

// Xóa toàn bộ danh sách
void delete_all(SinglyLinkedList *list) {
    while (list->head != NULL) {
        delete_head(list);
    }
}

// Sắp xếp danh sách theo thứ tự tăng dần (Selection sort)
void selection_sort(SinglyLinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *min_node = current;
        Node *temp = current->next;
        while (temp != NULL) {
            if (temp->data < min_node->data) {
                min_node = temp;
            }
            temp = temp->next;
        }
        // swap data
        int t = current->data;
        current->data = min_node->data;
        min_node->data = t;

        current = current->next;
    }
}

int main() {
    // Tạo một danh sách mới
    SinglyLinkedList *list = create_list();

    int a[] = {5, 3, 8, 1, 2, 7, 6, 4, 9};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++) {
        Node *node = create_node(a[i]);
        insert_sorted(list, node);
    }

    display_list(list);

    // Menu chức năng
    int choice;
    do {
        printf("\n***Linked List Basic Operations***\n");
        printf("1. Insert \t | 2. Delete\n");
        printf("3. Search \t | 4. Display\n");
        printf("5. Delete All \t | 6. Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            int value;
            case 1:
                // Thêm phần tử vào danh sách
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                Node *node = create_node(value);
                insert_head(list, node);
                break;
            case 2:
                // Xóa phần tử khỏi danh sách
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                delete (list, value);
                break;
            case 3:
                // Tìm kiếm phần tử trong danh sách
                printf("Enter a value to search: ");
                scanf("%d", &value);
                Node *found = search(list, value);
                if (found != NULL) {
                    printf("Found: %d\n", found->data);
                } else {
                    printf("Not found\n");
                }
                break;
            case 4:
                // Hiển thị danh sách
                display_list(list);
                break;
            case 5:
                // Xóa toàn bộ danh sách
                delete_all(list);
                break;
            case 6:
                // Sắp xếp danh sách
                selection_sort(list);
                break;
            case 0:
                // Thoát chương trình
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);
}