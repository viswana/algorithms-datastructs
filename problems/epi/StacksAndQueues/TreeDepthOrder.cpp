#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

template <typename T>
class btnode {
public:
  T data;
  btnode* left;
  btnode* right;
  btnode(T item) : data(item), left(NULL), right(NULL) {};
};

template <typename T>
btnode<T>* makeTree(vector<T>& preorder, vector<T>& inorder, unordered_map<T, size_t>& inIdxMap, int prelo, int prehi, int inlo, int inhi) {
  if (preorder.empty() || inorder.empty() || inIdxMap.empty()) return NULL;
  if (inlo > inhi || prelo > prehi) return NULL;
  T rootkey = preorder[prelo];
  btnode<T>* root = new btnode<T>(rootkey);
  int leftTreesz = inIdxMap[rootkey] - inlo;
  int rightTreesz = inhi - inIdxMap[rootkey];
  root->left = makeTree(preorder, inorder, inIdxMap,
			prelo+1, prelo + leftTreesz,
			inlo, inIdxMap[rootkey]-1);
  root->right = makeTree(preorder, inorder, inIdxMap,
			 prehi - rightTreesz + 1, prehi,
			 inIdxMap[rootkey] + 1, inhi);
  return root;
}

template<typename T>
btnode<T>* deltree(btnode<T>* t) {
  if (!t) return t;
  if (t->left) t->left = deltree(t->left);
  else if (t->right) t->right = deltree(t->right);
  delete(t);
  t = NULL;
  return t;
}

template <typename T>
vector<vector<T> > TreeDepthOrder(btnode<T>* t) {
  vector<vector<T> > ret;
  if (!t) return ret;
  queue<btnode<T>* > q;
  q.push(t);
  size_t cnt = q.size();
  while (!q.empty()) {
    vector<T> level;
    while (cnt) {
      btnode<T>* tmp = q.front();
      q.pop();
      cnt--;
      level.push_back(tmp->data);
      if (tmp->left) {
	q.push(tmp->left);
      }
      if (tmp->right) {
	q.push(tmp->right);
      }
    }
    cnt = q.size();
    ret.push_back(level);
  }
  return ret;
}
//Zigzag
template <typename T>
vector<vector<T> > TreeDepthOrder2(btnode<T>* t) {
  vector<vector<T> > ret;
  if (!t) return ret;
  stack<btnode<T>* > current_level;
  int depth = 0;
  current_level.push(t);
  while (!current_level.empty()) {
    vector<T> level;
    stack<btnode<T>* > next_level;
    while (!current_level.empty()) {
      btnode<T>* tmp = current_level.top();
      current_level.pop();
      level.push_back(tmp->data);
      if (depth & 1) {
	if (tmp->right) next_level.push(tmp->right);
	if (tmp->left) next_level.push(tmp->left);
      }
      else {
	if (tmp->left) next_level.push(tmp->left);
	if (tmp->right) next_level.push(tmp->right);
      }
    }
    ret.push_back(level);
    current_level = next_level;
    depth++;
  }
  return ret;
}

template <typename T>
void TreeDepthOrderHelper(btnode<T>* t, vector<vector<T> >& out, size_t depth) {
  if (!t) return;
  if (out.size() > depth) out[depth].push_back(t->data);
  else out.push_back(vector<T>(1, t->data));
  TreeDepthOrderHelper(t->left, out, depth+1);
  TreeDepthOrderHelper(t->right, out, depth+1);
}

template <typename T>
vector<vector<T> > TreeDepthOrder1(btnode<T>* t) {
  vector<vector<T> > ret;
  if (!t) return ret;
  TreeDepthOrderHelper(t, ret, 0);
  return ret;
}

int main() {
  vector<char> inorder = {'f', 'b', 'a', 'e', 'h', 'c', 'd', 'i', 'g'};
  vector<char> preorder = {'h', 'b' ,'f', 'e', 'a', 'c', 'd', 'g', 'i'};
  //vector<int> inorderi = {29, 270, 0, 6, 561, 17, 3, 314, 2, 401, 641, 1, 257, 13, 271, 28};
  //vector<int> preorderi = {314, 6, 270, 29, 0, 561, 3, 17, 13, 2, 1, 401, 641, 257, 271, 28};
  unordered_map<char, size_t> inIdxMap;
  //unordered_map<int, size_t> inIdxMapi;
  for (size_t i = 0; i < inorder.size(); i++)
    inIdxMap.insert({inorder[i], i});
  //for (size_t i = 0; i < inorderi.size(); i++)
  //inIdxMapi.insert({inorderi[i], i});
  btnode<char>* t = makeTree(preorder, inorder, inIdxMap, 0, preorder.size()-1,
  			    0, inorder.size()-1);
  //btnode<int>* t = makeTree(preorderi, inorderi, inIdxMapi, 0, preorderi.size()-1,
  //			     0, inorderi.size()-1);
  auto levellist = TreeDepthOrder2(t);
  int cnt = 0;
  for (auto i : levellist) {
    cout << "Level: " << cnt << endl;
    for (auto j: i) {
      cout << j << " ";
    }
    cout << endl;
    cnt++;
  }
  
  deltree(t);
  return 0;
}
