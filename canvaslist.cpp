#include "canvaslist.h"

#include <iostream>

using namespace std;

// TODO_STUDENT
// CORE
CanvasList::CanvasList() {
  list_size = 0;
  list_front = nullptr;
}

// ITERATING
CanvasList::CanvasList(const CanvasList& copyList) {  // list being copied
  this->list_size = 0;         // initialize new List size
  this->list_front = nullptr;  // initialize new List head

  ShapeNode* curr =
      copyList.front();  // pointer to traverse copylist called curr

  if (curr == nullptr) {  // if curr is null return
    return;
  }
  // else

  this->list_front = new ShapeNode;  // create head pointer for new list
  this->list_front->value =
      curr->value->copy();           // use copy method to copy the shape
  this->list_front->next = nullptr;  // head is pointing to null
  this->list_size = 1;               // size of list is one

  // head has been copied

  ShapeNode* newNode = this->list_front;  // stores head pointer for new list
  curr = curr->next;                      // moves onto next node on copied list

  while (curr != nullptr) {         // until nullptr is reached in copiedList
    newNode->next = new ShapeNode;  // create new node on new list
    newNode = newNode->next;        // advance to the new node
    newNode->value = curr->value->copy();  // use copy method to copy the shape
    newNode->next = nullptr;               // node is pointing to null
    this->list_size += 1;                  // new list increases in size
    curr = curr->next;                     // move onto next pointer in copylist
  }
}

CanvasList& CanvasList::operator=(const CanvasList& other) {
  if (this != &other) {  // Check for self-assignment
    clear();
    this->list_size = 0;
    this->list_front = nullptr;

    ShapeNode* curr = other.front();
    if (curr == nullptr) {  // if curr is null return
      return *this;
    }

    this->list_front = new ShapeNode;  // create head pointer for new list
    this->list_front->value =
        curr->value->copy();           // use copy method to copy the shape
    this->list_front->next = nullptr;  // head is pointing to null
    this->list_size = 1;

    ShapeNode* newNode = this->list_front;  // stores head pointer for new list
    curr = curr->next;  // moves onto next node on copied list

    while (curr != nullptr) {         // until nullptr is reached in copiedList
      newNode->next = new ShapeNode;  // create new node on new list
      newNode = newNode->next;        // advance to the new node
      newNode->value =
          curr->value->copy();  // use copy method to copy the shape
      newNode->next = nullptr;  // node is pointing to null
      this->list_size += 1;     // new list increases in size
      curr = curr->next;        // move onto next pointer in copylist
    }
  }
  return *this;  // Return the current object
}

// CORE
CanvasList::~CanvasList() {
  clear();
}

// CORE
void CanvasList::clear() {
  ShapeNode* current = list_front;

  while (current != nullptr) {
    ShapeNode* next = current->next;

    delete current->value;
    delete current;

    current = next;
  }
  list_front = nullptr;
  list_size = 0;
}

//EXTRAS
void CanvasList::insert_after(int insert, Shape* append) {

  ShapeNode* curr = list_front;

  if(insert < 0) {
    return;
  }

  if (curr == nullptr) {
    return;
  }


  for(int i = 0; i < insert; i++) {
    if(curr != nullptr) {
      curr = curr->next;
    }
    else{
      return;
    }
  }
  

  
  ShapeNode* newNode = new ShapeNode();
  newNode->value = append;
  newNode->next = curr->next;
  curr->next = newNode;

  list_size++;
}

// CORE PROBLEM AREA--> SOLVED
void CanvasList::push_front(Shape* shape) {
  ShapeNode* front = new ShapeNode;
  front->value = shape;

  if (list_front != nullptr) {
    front->next = list_front;
    list_front = front;
  } else {
    front->next = nullptr;
    list_front = front;
  }
  list_size++;
}

// ITERATING
void CanvasList::push_back(Shape* shape) {
  ShapeNode* append = new ShapeNode;
  append->value = shape;

  if (list_front == nullptr) {
    list_front = append;
    list_front->next = nullptr;
    list_size = 1;
  }

  else {
    ShapeNode* temp = list_front;

    while (temp->next != nullptr) {
      temp = temp->next;
    }

    temp->next = append;
    append->next = nullptr;
    list_size++;
  }
}

// MODIFYING
void CanvasList::remove_at(int remove) {
  if (remove < 0 || remove >= list_size) {
    return;
  }

  if (remove == 0) {
    ShapeNode* delfront = list_front;
    list_front = list_front->next;
    delete delfront->value;
    delete delfront;
    list_size--;
  } else {
    int i = 0;
    ShapeNode* curr = list_front;
    while (i < remove - 1) {
      curr = curr->next;
      i++;
    }

    if (curr != nullptr && curr->next != nullptr) {
      ShapeNode* deleteNode = curr->next;
      curr->next = deleteNode->next;
      delete deleteNode->value;  // Delete the shape
      delete deleteNode;         // Delete the node
      list_size--;
    }
  }
}

// EXTRAS
void CanvasList::remove_every_other() {
  ShapeNode* curr = list_front;

  if(curr == nullptr || curr->next == nullptr) {
    return;
  }

  while(curr != nullptr && curr->next != nullptr) {
    ShapeNode* temp = curr->next;
    curr->next = temp->next;

    cout << temp->value->as_string() << endl;
    delete temp->value;
    delete temp;

    curr = curr->next;
    list_size--;
  }
  return;
}

// MODIFYING
Shape* CanvasList::pop_front() {
  if (list_front == nullptr) {
    return nullptr;  // Return nullptr if the list is empty
  }

  ShapeNode* delfront = list_front;
  Shape* front = list_front->value;
  list_front = list_front->next;
  list_size--;

  delete delfront;
  return front;
}

// MODIFYING
Shape* CanvasList::pop_back() {
  if (list_front == nullptr) {
    return nullptr;
  } else if (list_front->next == nullptr) {
    Shape* deleted = list_front->value;
    delete list_front;
    list_front = nullptr;
    list_size = 0;

    return deleted;
  }

  ShapeNode* curr = list_front;

  while (curr->next->next != nullptr) {
    curr = curr->next;
  }
  Shape* deleted = curr->next->value;
  delete curr->next;
  curr->next = nullptr;
  list_size--;
  return deleted;
}

// CORE
ShapeNode* CanvasList::front() const {
  return list_front;
}

// CORE
bool CanvasList::empty() const {
  return list_front == nullptr;
}

// CORE
int CanvasList::size() const {
  return list_size;
}

// ITERATING
int CanvasList::find(int x, int y) const {
  int index = 0;
  ShapeNode* current = list_front;

  while (current != nullptr) {
    if ((current->value->getX() == x) && (current->value->getY() == y)) {
      return index;
    } else {
      current = current->next;
      index++;
    }
  }

  return -1;
}

// ITERATING
Shape* CanvasList::shape_at(int index) const {
  if (index < 0 || index >= list_size) {
    return nullptr;  // index out of bounds
  }

  int i = 0;
  ShapeNode* current = list_front;

  while (i < index && current != nullptr) {
    current = current->next;
    i++;
  }

  if (current == nullptr) {
    return nullptr;
  }

  return current->value;
}

// ITERATING
void CanvasList::draw() const {
  ShapeNode* current = list_front;

  while (current != nullptr) {
    cout << current->value->as_string() << endl;
    current = current->next;
  }
}

// ITERATING
void CanvasList::print_addresses() const {
  ShapeNode* current = list_front;

  while (current != nullptr) {
    cout << "Node Address: " << current << "\t"
         << "Shape Address: " << current->value << endl;
    current = current->next;
  }
}