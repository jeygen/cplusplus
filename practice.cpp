#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>

std::vector<std::vector<int>> ff(std::vector<std::vector<int>>& image, int
new_colour, int sr, inr sc) {
	int old_colour = image[sr][sc];

	if(new_colour != old_colour) {
		std::queue<std::pair<int>> q{};
		q.push(sr,sc);

		//std::vector<std::vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

		while (!q.empty()) {
			auto [r, c] = q.front();
			q.pop();

			image[r][c] = new_colour;

			for (auto d:dir) {
				:wq




	
int main(int argc, char** argv) {
}
