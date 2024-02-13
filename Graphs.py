from collections import deque

class Graph:
    def __init__(self):
        self.graph = {
            0: [1, 2],
            1: [0, 2],
            2: [0, 1],
            3: [4],
            4: [3],
            5: [6],
            6: [5]
        }
    
    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append(v)
    
    def dfs(self, start):
        visited = set()

        def helper(node):
            nonlocal visited

            if node not in visited:
                print(node, end=" ")
                visited.add(node)
                for neighbor in self.graph.get(node, []):
                    helper(neighbor)
            
        helper(start)
        print()

    def bfs(self, start):
        visited = set()
        queue = deque([start])

        while queue:
            node = queue.popleft()
            if node not in visited:
                print(node, end=" ")
                visited.add(node)
                queue.extend(neighbor for neighbor in self.graph.get(node, []) if neighbor not in visited)
        print()
    
    def dfs_connectedComponents(self, i, visited, component):
        visited[i] = True
        component.append(i)
        for neighbor in self.graph[i]:
            if not visited[neighbor]:
                self.dfs_connectedComponents(neighbor, visited, component)
    
    def findConnectedComponents(self):
        n = len(self.graph)
        visited = [False] * n
        connectedComponents = []

        for i in range(n):
            if not visited[i]:
                component = []
                self.dfs_connectedComponents(i, visited, component)
                connectedComponents.append(component)
        return connectedComponents

if __name__ == "__main__":
    g = Graph()
    connectedComponents = g.findConnectedComponents()
    for component in connectedComponents:
        print(component)

