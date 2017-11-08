#include <stdio.h>

typedef struct Element Element;
struct Element
{
    int data;
    Element *next;
};

typedef struct LinkedList LinkedList;
struct LinkedList {
    Element *first;
};

LinkedList *init(int elementValue) {
    LinkedList *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL) {
        exit(EXIT_FAILURE);
    }

    element->data = elementValue;
    element->next = NULL;

    list->first = element;

    return list;
}

void prepend(LinkedList *list, int elementValue) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    if (list->first == NULL) {
        Element *newElement = malloc(sizeof(*newElement));
        newElement->data = elementValue;
        newElement->next = NULL;

        list->first = newElement;
    }
    else {
        Element *newElement = malloc(sizeof(*newElement));
        newElement->data = elementValue;
        newElement->next = list->first;

        list->first = newElement;
    }
}

void append(LinkedList *list, int elementValue) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *newElement = malloc(sizeof(*newElement));
    newElement->data = elementValue;
    newElement->next = NULL;

    Element *current = list->first;

    if (current == NULL) {
        current = newElement;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newElement;
}

void delete(LinkedList *list, int elementValue) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;

    if (current == NULL) {
        exit(EXIT_FAILURE);
    }

    if (current->data == elementValue) {
        if (current->next != NULL) {
            Element* toBeDeleted = list->first;
            list->first = current->next;
            free(toBeDeleted);
        } else {
            current = NULL;
        }
        return;
    }

    while (current->next != NULL) {
        if (current->next->data == elementValue) {
            Element* toBeDeleted = current->next;
            current->next = current->next->next;
            free(toBeDeleted);
            return;
        }
        current = current->next;
    }
}

void display(LinkedList *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;

    while (current != NULL) {
        printf("[%d %d] -> ", current->data, current->next);
        current = current->next;
    }
    printf("NULL\n");
}
