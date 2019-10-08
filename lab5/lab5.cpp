#include <iostream>

using namespace std;

//----------- Define Node ---------------------------------------------------
struct Node{
  int key;
  Node *previous;
  Node *next;
};

//----------- Define Doubly Linked List ---------------------------------------------------
class doubleLL
{
  private:
    Node *head;
    Node *tail;
  public:
    doubleLL(){
      head = NULL;
      tail = NULL;
    }
    void insert_begin(int); //put element at front
    void insert_end(int); //put element at end
    void display_dll_rev(); //display in reverse
    void display_dll(); //display the linked list
};

//----------- Main ---------------------------------------------------
int main()
{
  int choice, element;
  doubleLL dl;

  while(1)
  {
    cout << "--------------------------------------------" << endl;
    cout << "* 1. Insert node at the beginning          *"<< endl;
    cout << "* 2. Insert node at the end                *" << endl;
    cout << "* 3. Display doubly linked list from tail  *" << endl;
    cout << "* 4. Display doubly linked list from head  *" << endl;
    cout << "* 5. Quit                                  *" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Choice: ";
    cin >> choice;
    cout << endl;
    switch(choice)
    {
      case 1:
            cout << "Enter the key to be inserted at the beginning: ";
            cin >> element;
            dl.insert_begin(element);
            cout << endl;
            break;
      case 2:
            cout << "Enter the key to be inserted at the end: ";
            cin >> element;
            dl.insert_end(element);
            cout << endl;
            break;
      case 3:
            dl.display_dll_rev();
            break;
      case 4:
            dl.display_dll();
            break;
      case 5:
            return 0;
      default:
            cout << "------- Oops! Wrong choice ------ " << endl;
            return 0;
    }
  }
  return 0;
}


// -------------------------------------------------------------------------
/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
// -------------------------------------------------------------------------

void doubleLL::insert_begin(int element)
{
  //1. ALLOCATE NODE
  Node * newNode = new Node;

  //2. PUT IN THE DATA
  newNode -> key = element;
  
  //3. Make next of newNode as head and previous as NULL
  //head -> previous = newNode;
  newNode -> next = head;
  newNode -> previous = NULL;
  //4. Edge case; CHECK if the head is NULL or not. If NULL then set tail to NULL; also set next to NULL
  if(head != NULL){
    head->previous = newNode;
    head = newNode;
  }else{
  //5. Move the head to point to the new node */
  head = newNode;
  tail = newNode;
  }
}


// -------------------------------------------------------------------------
/* Given a node as prev_node, insert a new node after the given node */
// -------------------------------------------------------------------------


void doubleLL::insert_end(int element)
{

  //1.  ALLOCATE NODE
  Node * newNode = new Node;

  //2. PUT IN THE DATA
  newNode -> key = element;
  
  if(head == NULL){
    newNode -> previous = NULL;
    newNode -> next = NULL;
    head = newNode;
    tail = newNode;
    return;
  }
  
  tail -> next = newNode;
  newNode -> previous = tail;
  /*3. This new node is going to be the last node, so make next of it as NULL*/
  newNode -> next = NULL;
  tail = newNode;
  /*4. If the Linked List is empty, then make the new node as head */
  

}

// -------------------------------------------------------------------------
/* Print Doubly Linked List in the reverse order (Tail to Head) */
// -------------------------------------------------------------------------

void doubleLL::display_dll_rev()
{
    // Get the tail, assign it to a pointer
    Node *Traverse = tail;

    // Traverse back till head, i.e. previous of pointer is NULL
     while(Traverse != NULL){
    cout << Traverse -> key << "<-";
    Traverse = Traverse -> previous;
    }

    // Print the elements of nodes
    cout << "Tail";
}

// -------------------------------------------------------------------------
// Print Doubly Linked List
// -------------------------------------------------------------------------

void doubleLL::display_dll()
{
  // Get the head, assign it to a pointer
  Node *Traverse = head;
  
  while(Traverse != NULL){
    cout << Traverse -> key << "->";
    Traverse = Traverse -> next;
  }
  // Traverse till the tail, i.e. next of the pointer is NULL
  cout << "Null";
  // Print the elements
}


