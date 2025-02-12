#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Employee {
    int id;
    char name[50];
    char dob[12];
    char doj[12];
    float salary;
    char designation[50];
    char department[50];
    struct Employee *next;
};

struct Node {
    struct Employee data;
    struct Node *next;
};

struct Hashtable {
    struct Node *table[TABLE_SIZE];
};

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(struct Hashtable *ht, struct Employee emp) {
    int index = hashFunction(emp.id);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = emp;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

struct Employee *search(struct Hashtable *ht, int id) {
    int index = hashFunction(id);
    struct Node *current = ht->table[index];
    while (current) {
        if (current->data.id == id) return &current->data;
        current = current->next;
    }
    return NULL;
}

void updateEmployee(struct Hashtable *ht, int id) {
    struct Employee *emp = search(ht, id);
    if (!emp) {
        printf("Employee not found!\n");
        return;
    }
    printf("Enter new details (leave unchanged fields blank):\n");
    printf("Name: ");
    char name[50];
    scanf("%49s", name);
    if (strlen(name) > 0) strcpy(emp->name, name);
    printf("Salary: ");
    float salary;
    if (scanf("%f", &salary) == 1) emp->salary = salary;
    printf("Department: ");
    char dept[50];
    scanf("%49s", dept);
    if (strlen(dept) > 0) strcpy(emp->department, dept);
    printf("Updated successfully!\n");
}

void deleteEmployee(struct Hashtable *ht, int id) {
    int index = hashFunction(id);
    struct Node *current = ht->table[index], *prev = NULL;
    while (current && current->data.id != id) {
        prev = current;
        current = current->next;
    }
    if (!current) {
        printf("Employee not found!\n");
        return;
    }
    if (prev) prev->next = current->next;
    else ht->table[index] = current->next;
    free(current);
    printf("Deleted successfully!\n");
}

void searchByDepartment(struct Hashtable *ht, char *department) {
    printf("Employees in %s:\n", department);
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *current = ht->table[i];
        while (current) {
            if (strcmp(current->data.department, department) == 0) {
                printf("ID: %d, Name: %s, Salary: %.2f\n", 
                        current->data.id, current->data.name, current->data.salary);
            }
            current = current->next;
        }
    }
}

void displayHashTable(struct Hashtable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *current = ht->table[i];
        while (current) {
            printf("ID: %d, Name: %s, Dept: %s, Salary: %.2f\n", 
                    current->data.id, current->data.name, current->data.department, current->data.salary);
            current = current->next;
        }
    }
}

int main() {
    struct Hashtable ht = {0};
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert Employee\n2. Search Employee\n3. Update Employee\n4. Delete Employee\n5. Search by Department\n6. Display All\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                struct Employee emp;
                printf("Enter ID: "); scanf("%d", &emp.id);
                printf("Enter Name: "); scanf("%49s", emp.name);
                printf("Enter DOB: "); scanf("%11s", emp.dob);
                printf("Enter DOJ: "); scanf("%11s", emp.doj);
                printf("Enter Salary: "); scanf("%f", &emp.salary);
                printf("Enter Designation: "); scanf("%49s", emp.designation);
                printf("Enter Department: "); scanf("%49s", emp.department);
                insert(&ht, emp);
                break;
            }
            case 2: {
                int id;
                printf("Enter ID to search: "); scanf("%d", &id);
                struct Employee *result = search(&ht, id);
                if (result) printf("Found: %s, %s, %.2f\n", result->name, result->department, result->salary);
                else printf("Not Found!\n");
                break;
            }
            case 3: {
                int id;
                printf("Enter ID to update: "); scanf("%d", &id);
                updateEmployee(&ht, id);
                break;
            }
            case 4: {
                int id;
                printf("Enter ID to delete: "); scanf("%d", &id);
                deleteEmployee(&ht, id);
                break;
            }
            case 5: {
                char dept[50];
                printf("Enter department: "); scanf("%49s", dept);
                searchByDepartment(&ht, dept);
                break;
            }
            case 6:
                displayHashTable(&ht);
                break;
        }
    } while (choice != 0);
    return 0;
}
