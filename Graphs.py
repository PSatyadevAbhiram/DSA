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
    
    def dfs_findConnectedComponents(self, i, visited, component):
        visited[i] = True
        component.append(i)
        for neighbor in self.graph[i]:
            if not visited[neighbor]:
                self.dfs_findConnectedComponents(neighbor, visited, component)
    
    def findConnectedComponents(self):
        n = len(self.graph)
        visited = [False] * n
        components = []
        for i in range(n):
            if not visited[i]:
                component = []
                self.dfs_findConnectedComponents(i, visited, component)
                components.append(component)
        return components
    
    def detectCycle_helper(self, graph, node, parent, visited):
        visited[node] = True
        for neighbor in graph.get(node, []):
            if not visited[neighbor]:
                if self.detectCycle_helper(graph, neighbor, node, visited):
                    return True
            elif neighbor!=parent:
                return True
        return False
    
    def detectCycle(self, graph):
        n = len(graph)
        visited = [False] * n
        for node in graph:
            if not visited[node]:
                if self.detectCycle_helper(graph, node, -1, visited):
                    return True
        return False
    
    def topologicalSort(self, graph):
        n = len(graph)
        visited = [False]*n
        stack = []

        def dfs(node):
            visited[node] = True
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    dfs(neighbor)
            stack.append(node)
        
        for i in range(n):
            if not visited[i]:
                dfs(i)
        
        return stack[::-1]

if __name__ == "__main__":
    g = Graph()
    # graph_with_cycle = {
    #     0: [1, 2],
    #     1: [0, 2],
    #     2: [0, 1],
    #     3: [4],
    #     4: [3],
    #     5: [6],
    #     6: [5, 7],
    #     7: [6]
    # }

    graph = {
        0: [1, 2],
        1: [3],
        2: [3],
        3: [4, 5],
        4: [],
        5: []
    }

    print(g.topologicalSort(graph))
