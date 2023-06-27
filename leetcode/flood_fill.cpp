// Get the color of the starting pixel

// If the color of the starting pixel is already the new color, no action is needed

// Create a queue for pixels to be processed and add the start pixel

// Directions represent the four possible movements (up, down, left, right)

// Process pixels until the queue is empty

// Get and remove the front element from the queue

// Change the color of the current pixel

// Check all four directions around the current pixel

// If the neighboring pixel is within the image boundaries and is the old color

// Add the neighboring pixel to the queue for processing




// source row and col, return newly coloured image
// change every colour to match starting colour
#include <vector>
#include <queue>

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
	// track starting node colour
    int oldColor = image[sr][sc];

	// if doesn't match, add to queues for bfs
    if (oldColor != newColor) { 
		// create 2 element queue
        std::queue<std::pair<int, int>> q;
		// instead of single value for node, have coordinate pairs
        q.push({sr, sc});

		// instead of checking if just connected, it is "moving" directions
        std::vector<std::vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right

		// core bfs
        while (!q.empty()) {
			// save front values and pop
			// syntax is assigns the returned pair to r and c 
            auto [r, c] = q.front();
            q.pop();

            image[r][c] = newColor;

			// can iterate through containers
            for (const auto& dir : directions) {
				// apply x and y element to row and col
                int nr = r + dir[0];
                int nc = c + dir[1];
				// if inbounds and old then push it to queue
                if (nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size() && image[nr][nc] == oldColor) {
                    q.push({nr, nc});
                }
            }
        }
    }
    return image;
}
		
		
