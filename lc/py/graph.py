def generate_edges(graph):
    edges = []
    for node in graph:
        for neighbour in graph[node]:
            edges.append((node, neighbour))

    return edges

def find_isolated_nodes(graph):
    """ returns a list of isolated nodes. """
    isolated = []
    for node in graph:
        if not graph[node]:
            isolated += node
    return isolated

def search(graph, root, visited = {}):
  def visit(a):
    print(a)

  visited = {node for}

  if root not in graph:
    return
  visit(root)
  visited[root] = True

  for node in graph[root]:
    if node in visited and not visited[node]:
      search(graph, n, visited)

graph = { "a" : ["c"],
          "b" : ["c", "e"],
          "c" : ["a", "b", "d", "e"],
          "d" : ["c"],
          "e" : ["c", "b"],
          "f" : []
        }

print(generate_edges(graph))
print()
print(find_isolated_nodes(graph))
print(search(graph,'c'))
