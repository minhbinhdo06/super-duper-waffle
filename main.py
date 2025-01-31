import sys
from collections import deque

def main():
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx])
    idx += 1
    M = int(input[idx])
    idx += 1
    matrix = []
    for _ in range(N):
        row = list(map(int, input[idx:idx+M]))  
        idx += M
        matrix.append(row)
    visited = [[False for _ in range(M)] for _ in range(N)]
    count = 0           
    for i in range(N):
        for j in range(M):
            if not visited[i][j]:
                h = matrix[i][j]
                queue = deque()
                queue.append((i, j))
                visited[i][j] = True
                is_peak = True
                
                while queue:
                    x, y = queue.popleft()
                    for dx in [-1, 0, 1]:
                        for dy in [-1, 0, 1]:
                            if dx == 0 and dy == 0:
                                continue
                            nx = x + dx
                            ny = y + dy
                            if 0 <= nx < N and 0 <= ny < M:
                                # Check if any neighbor has higher elevation
                                if is_peak and matrix[nx][ny] > h:
                                    is_peak = False
                                # Add unvisited cells of the same height to the queue
                                if matrix[nx][ny] == h and not visited[nx][ny]:
                                    visited[nx][ny] = True
                                    queue.append((nx, ny))
                if is_peak:
                    count += 1
    print(count)

if __name__ == "__main__":
    main()
