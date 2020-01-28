graph = { 'a': ['b', 'd', 'e'],
          'b': ['c'],
          'c' : [],
          'd' : ['a'],
          'e' : ['b']
          }

visited = []

def dfs(graph, root, visited):
  if root not in visited:
    # visit root
    print(root)
    visited.append(root)
    for neighbor in graph[root]:
      dfs(graph, neighbor, visited)

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


