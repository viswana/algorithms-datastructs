#include <iostream>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

typedef struct _Node {
  int i;
  size_t degree;
  struct _Node** padjList;
} Node, *pNode;

pNode bfsClone(pNode g) {
  if (g == NULL) return g;
  list<pNode> q;
  unordered_map<pNode, pNode> nodeMap;
  pNode t = new Node;
  t->i = g->i;
  t->degree = g->degree;
  t->padjList = NULL;
  if (g->degree) {
    t->padjList = new pNode[g->degree];
    q.push_back(g);
  }
  nodeMap[g] = t;
  while (!q.empty()) {
    pNode tmp = q.front();
    q.pop_front();
    for (size_t i = 0; i < tmp->degree; i++) {
      pNode tmp1 = *(tmp->padjList+i);
      pNode x = NULL;
      if (tmp1 != NULL) {
        if (!nodeMap.count(tmp1)) {
          x = new Node;
          x->i = tmp1->i;
          x->degree = tmp1->degree;
          x->padjList = NULL;
          if (tmp1->degree) {
            x->padjList = new pNode[tmp1->degree];
            q.push_back(tmp1);
          }
          nodeMap[tmp1] = x;
        }
        else {
          x = nodeMap[tmp1];
        }
      }
      nodeMap[tmp]->padjList[i] = x;
    }
  }
  return t;
}

pNode dfsClone(pNode g, unordered_map<pNode, pNode>& nodeMap) {
  if (g == NULL) return g;
  pNode t = new Node;
  t->i = g->i;
  t->degree = g->degree;
  t->padjList = NULL;
  if (g->degree) t->padjList = new pNode[g->degree];
  nodeMap[g]= t;
  for (size_t i = 0; i < g->degree; i++) {
    pNode tmp1 = *(g->padjList+i);
    pNode x = NULL;
    if (tmp1 != NULL) {
      if (!nodeMap.count(tmp1)) {
        x = dfsClone(tmp1, nodeMap);
      }
      else {
        x = nodeMap[tmp1];
      }
    }
    t->padjList[i] = x;
  }
  return t;
}

pNode dfsCloneStack(pNode g) {
  if (g == NULL) return g;
  unordered_map<pNode, pNode> nodeMap;
  vector<pair<pNode, size_t> > stack;
  pNode t = new Node;
  t->i = g->i;
  t->degree = g->degree;
  t->padjList = NULL;
  if (g->degree) { 
    t->padjList = new pNode[g->degree];
    stack.push_back(make_pair(g, 0));
  }
  nodeMap[g] = t;
  while (stack.size()) {
    pNode tmp = stack[stack.size()-1].first;
    size_t i = stack[stack.size()-1].second;
    //Find first unvisited neighbor
    for (; i < tmp->degree; i++) {
      pNode tmp1 = *(tmp->padjList+i);
      if (tmp1 != NULL) {
        if (nodeMap.count(tmp1)) {
          nodeMap[tmp]->padjList[i] = nodeMap[tmp1];
        }
        else { //Found unvisited neighbor
          pNode x= new Node;
          x->i = tmp1->i;
          x->degree = tmp1->degree;
          x->padjList = NULL;
          if (tmp1->degree) { //this is always true for a fully connected graph
            x->padjList = new pNode[tmp1->degree];
            //Update the index where to re-start probing from
            stack[stack.size()-1].second = i+1;
            stack.push_back(make_pair(tmp1, 0));
          }
          nodeMap[tmp1] = x;
          nodeMap[tmp]->padjList[i] = x;
          break;
        }
      }
      else {
        nodeMap[tmp]->padjList[i] = NULL;
      }
    }
    if (i == tmp->degree) {
      stack.pop_back();  
    }
  }
  return t;
}

void bfsFree(pNode g) {
  if (g == NULL) return;
  unordered_set<pNode> nodeList;
  list<pNode> q;
  q.push_back(g);
  nodeList.insert(g);
  while(!q.empty()) {
    pNode tmp = q.front();
    for (size_t i = 0; i < tmp->degree; i++) {
      pNode tmp1 = *(tmp->padjList+i);
      if (tmp1 != NULL) {
        if (!nodeList.count(tmp1)) {
          nodeList.insert(tmp1);
          q.push_back(tmp1); 
        }
      }
    }
    q.pop_front();
  }
  for (auto i : nodeList) {
    if (i->degree) {
      delete[] i->padjList;
    }
    delete i;
  }
}

void dfsFree(pNode g, unordered_set<pNode>& visited) {
  if (g == NULL) return;
  visited.insert(g);
  for (size_t i = 0; i < g->degree; i++) {
    pNode tmp1 = *(g->padjList+i);
    if (tmp1 != NULL && !visited.count(tmp1)) dfsFree(tmp1, visited);
  }
  if (g->degree) delete[] g->padjList;
  delete g;
}

void bfsPrint(pNode g) {
  if (g == NULL) return;
  list<pNode> q;
  size_t fdepth = 0;
  cout << "Depth: " << fdepth << endl;
  cout << g->i << endl;
  q.push_back(g);
  size_t count = q.size();
  unordered_set<pNode> visited;
  visited.insert(g);
  while (!q.empty()) {
    cout << "Depth: " << fdepth+1 << endl;
    while (count > 0) {
      pNode tmp = q.front();
      count--;
      for(size_t i = 0; i < tmp->degree; i++) {
        pNode tmp1 = *(tmp->padjList+i);
        if (tmp1 != NULL) {
          if (!visited.count(tmp1)) {
            cout << tmp1->i << " ";
            visited.insert(tmp1);
            q.push_back(tmp1);
          }
        }
      }
      q.pop_front();
    }
    fdepth++;
    cout << endl;
    count = q.size();
  }
}

void dfsPrintStack(pNode g) {
  if (g == NULL) return;
  unordered_set<pNode> visited;
  vector<pNode> stack;
  visited.insert(g);
  stack.push_back(g);
  while (stack.size()) {
    pNode tmp = stack[stack.size()-1];
    stack.pop_back();
    cout << tmp->i << endl;
    for (int i = tmp->degree-1; i >= 0 ; i--) {
      pNode tmp1 = *(tmp->padjList+i);
      if (tmp1 != NULL) {
        if (!visited.count(tmp1)) {
          visited.insert(tmp1);
          stack.push_back(tmp1);
        }
      }
    }
  }
}

int main() {
  Node a[8];
  size_t len = sizeof(a)/sizeof(Node);
  for (size_t i = 0; i < len; i++) 
    a[i].i = i+1;
  pNode a0list[] = {a+2, a+6, a+7};
  a[0].degree = 3;
  a[0].padjList = a0list; 
  pNode a1list[] = {a+4, a+7};
  a[1].degree = 2;
  a[1].padjList = a1list;
  pNode a2list[] = {a, a+7};
  a[2].degree = 2;
  a[2].padjList = a2list;
  a[3].degree = 0;
  a[3].padjList = NULL;
  pNode a4list[] = {a+1, a+5, a+6};
  a[4].degree = 3;
  a[4].padjList = a4list;
  pNode a5list[] = {a+4, a+7};
  a[5].degree = 2;
  a[5].padjList = a5list;
  pNode a6list[] = {a, a+4};
  a[6].degree = 2;
  a[6].padjList = a6list;
  pNode a7list[] = {a, a+1, a+2, a+5};
  a[7].degree = 4;
  a[7].padjList = a7list; 
  bfsPrint(a+7);
  pNode aclone = bfsClone(a);
  //bfsPrint(*(aclone->padjList+1));
  bfsPrint(aclone);
  unordered_set<pNode> visited;
  //dfsFree(aclone, visited);
  bfsFree(aclone);
  unordered_map<pNode, pNode> nodeMap;
  pNode aclone2 = dfsClone(a, nodeMap);
  pNode aclone3 = dfsCloneStack(a);
  bfsPrint(aclone2);
  bfsPrint(aclone3);
  //dfsPrintStack(aclone2);
  dfsFree(aclone2, visited);
  visited.clear();
  dfsFree(aclone3, visited);
}
