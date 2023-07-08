#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>

void bfs(vector& v) {
  vector<bool> visited;
  visited[v[0]] = true;

  queue q;
  q.push(v[0]);

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    for(int i = 0; i < v.size(); i++)  {
      if (v[i] == false) {
        v[i] == true;
        q.push(v[i]);
      }
    }
  }
}

  



int main(int argc, char** argv) {
	int doggy = 1;
	int cat = doggy	
  int doggy
  int dogg

}
