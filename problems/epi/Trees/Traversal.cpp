#include <iostream>
#include "utils.h"
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

template <typename T>
void Rinorder(btnode<T>* t, vector<T>& out) {
  if (!t) return;
  Rinorder(t->left, out);
  out.push_back(t->data);
  Rinorder(t->right, out);
  return;
}

template <typename T>
void Rpreorder(btnode<T>* t, vector<T>& out) {
  if (!t) return;
  out.push_back(t->data);
  Rpreorder(t->left, out);
  Rpreorder(t->right, out);
  return;
}

template <typename T>
void Rpostorder(btnode<T>* t, vector<T>& out) {
  if (!t) return;
  Rpostorder(t->left, out);
  Rpostorder(t->right, out);
  out.push_back(t->data);
  return;
}

template <typename T>
void Iinorder(btnode<T>* t, vector<T>& out) {
  if (!t) return;
  stack<btnode<T>* > s;
  s.push(t);
  int state = 0;
  while (!s.empty()) {
    if (state == 0) {
      btnode<T>* tmp = s.top();
      btnode<T>* leftchild = tmp->left;
      if (leftchild) s.push(leftchild);
      else state = 1;
    }
    else {
      btnode<T>* tmp = s.top();
      btnode<T>* rightchild = tmp->right;
      s.pop();
      out.push_back(tmp->data);
      if (rightchild) {
	s.push(rightchild);
	state = 0;
      }
      else state = 1;
    }
  }
}

template <typename T>
void Ipreorder(btnode<T>* t, vector<T>& out) {
  if (!t) return;
  stack<btnode<T>* > s;
  s.push(t);
  int state = 0;
  while (!s.empty()) {
    if (state == 0) {
      btnode<T>* tmp = s.top();
      out.push_back(tmp->data);
      btnode<T>* leftchild = tmp->left;
      if (leftchild) s.push(leftchild);
      else state = 1;
    }
    else {
      btnode<T>* tmp = s.top();
      btnode<T>* rightchild = tmp->right;
      s.pop();
      if (rightchild) {
	s.push(rightchild);
	state = 0;
      }
      else state = 1;
    }
  }
}

template <typename T>
void Ipostorder(btnode<T>* t, vector<T>& out) {
  if (!t) return;
  stack<btnode<T>* > s;
  s.push(t);
  int state = 0;
  while (!s.empty()) {
    if (state == 0) {
      btnode<T>* tmp = s.top();
      btnode<T>* leftchild = tmp->left;
      if (leftchild) s.push(leftchild);
      else state = 1;
    }
    else if (state == 1) {
      btnode<T>* tmp = s.top();
      btnode<T>* rightchild = tmp->right;
      if (rightchild) {
	s.push(rightchild);
	state = 0;
      }
      else {
	out.push_back(tmp->data);
	s.pop();
	state = 1;
	if (!s.empty()) {
	  if (tmp == s.top()->right) {
	    state = 2;
	  }
	}
      }
    }
    else  {
      btnode<T>* tmp = s.top();
      out.push_back(tmp->data);
      s.pop();
      if (!s.empty()) {
	if (tmp == s.top()->right)
	  state = 2;
	else state = 1;
      }
    }
  }
}

int main() {
  vector<int> inorderi = {29, 270, 0, 6, 561, 17, 3, 314, 2, 401, 641, 1, 257, 13, 271, 28};
  vector<int> preorderi = {314, 6, 270, 29, 0, 561, 3, 17, 13, 2, 1, 401, 641, 257, 271, 28};
  vector<int> postorderi = {29, 0, 270, 17, 3, 561, 6, 641, 401, 257, 1, 2, 28, 271, 13, 314};
  unordered_map<int, size_t> inIdxMapi;
  for (size_t i = 0; i < inorderi.size(); i++)
    inIdxMapi.insert({inorderi[i], i});
  btnode<int>* t = makeTree(preorderi, inorderi, inIdxMapi, 0, preorderi.size()-1,
			    0, inorderi.size()-1);
  vector<int> out;
  Iinorder(t, out);
  for (int i : out) {
    cout << i << " ";
  }
  cout << endl;
  vector<int> out1;
  Ipostorder(t, out1);
  for (int i : out1) {
    cout << i << " ";
  }
  cout << endl;
  deltree(t);
  return 0;
}
