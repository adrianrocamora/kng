graph = { 'a': ['b', 'd', 'e'],
visited = []
dfs(graph, 'a', visited)
print()
visited = []
dfs(graph, 'b', visited)
print()
visited = []
dfs(graph, 'c', visited)
print()
visited = []
dfs(graph, 'd', visited)
print()
visited = []
dfs(graph, 'e', visited)
          'b': ['c'],
          'c' : [],
          'd' : ['a'],
          'e' : ['b']
          }


def dfs(graph, root, visited):
  if root not in visited:
    # visit root
    print(root)
    visited.append(root)
    for neighbor in graph[root]:
      dfs(graph, neighbor, visited)

def bfs(graph, root, visited):
  queue = []
  queue.append(root)
  visited.append(root)

  while queue:
    n = queue.pop(0)
    print(n)
    
    for neighbor in graph[n]:
      if neighbor not in visited:
        queue.append(neighbor)
        visited.append(neighbor)


# visited = []
# dfs(graph, 'a', visited)
# print()
# visited = []
# dfs(graph, 'b', visited)
# print()
# visited = []
# dfs(graph, 'c', visited)
# print()
# visited = []
# dfs(graph, 'd', visited)
# print()
# visited = []
# dfs(graph, 'e', visited)
# print()
# print()

visited = []
bfs(graph, 'a', visited)
print()
visited = []
bfs(graph, 'b', visited)
print()
visited = []
bfs(graph, 'c', visited)
print()
visited = []
bfs(graph, 'd', visited)
print()
visited = []
bfs(graph, 'e', visited)

