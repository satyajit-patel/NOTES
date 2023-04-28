#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link:-

class Node {
public:
  int data;
  Node *next;
  Node() {
    this->data = 0;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};
Node* head = NULL;
Node* tail = NULL;

class linked_list {
public:
  int len = 0;

  void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void push_front(int data) { // O(1)
    // edge case
    if (head == NULL) {
      Node *newNode = new Node(data);
      head = newNode;
      tail = newNode;
      len++;
      return;
    }

    // create
    Node *newNode = new Node(data);

    // point
    newNode->next = head;
    
    // update
    head = newNode;
    len++;
  }

  void push_back(int data) { // O(1)
    // edge case
    if (tail == NULL) {
      Node *newNode = new Node(data);
      head = newNode;
      tail = newNode;
      len++;
      return;
    }

    // create
    Node *newNode = new Node(data);

    // point
    tail->next = newNode;

    // update
    tail = newNode;
    len++;
  }

  void push_at_position(int n, int data) { // O(N)
    // edge case
    if (n <= 1) {
      push_front(data);
      return;
    }
    if (n >= len) {
      push_back(data);
      return;
    }

    // find
    int pos = 1;
    Node *prev = head;
    while(pos != n-1) {
      pos++;
      prev = prev->next;
    }
    
    // create
    Node *newNode = new Node(data);

    // point
    newNode->next = prev->next;
    prev->next = newNode;

    // update
    len++;
  }

  int size() { // O(1)
    return len; 
  }

  void pop_front() { // O(1)
    // edge case
    if(head == NULL) {
      cout<<"underflow\n";
      return;
    }
    
    Node* temp = head;

    head = head->next;
    len--;

    temp->next = NULL;
    delete temp; // destructor called

  }

  void pop_back() { // O(N)
    // edge case
    if(tail == NULL) {
      cout<<"underflow\n";
      return;
    }
    
    Node* prev = head;
    while(prev->next->next != NULL) prev = prev->next;
    
    Node* temp = prev->next;
    prev->next = NULL;
    
    tail = prev;
    len--;
    delete temp; // destructor called

  }

  void pop_at_position(int n) {
    // edge case
    if (n <= 1) {
      pop_front();
      return;
    }
    if (n >= len) {
      pop_back();
      return;
    }

    // find
    int pos = 1;
    Node *prev = head;
    while(pos != n-1) {
      pos++;
      prev = prev->next;
    }

    Node* temp = prev->next;
    prev->next = prev->next->next;
    len--;

    temp->next = NULL;
    delete temp; // destructor called
  }
};

void input() {
  linked_list L;
  for (int i = 1; i <= 5; i++) L.push_back(i);
  L.print(head);
  
  L.push_at_position(1, 200);
  L.push_at_position(L.size(), 300);
  L.push_at_position(4, 100);
  L.print(head);
  
  L.pop_front();
  L.pop_back();
  L.pop_at_position(3); 
  L.print(head);
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
