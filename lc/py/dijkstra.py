# Dijkstra

# Finds the shortest path between two nodes on a graph 
# We can use it for weighted an unweighted graphs, but not for negative weighted edges, for those use the Bellman-Ford algorithm

# 1. Create a set that keeps track of vertices included in the shortest path tree. Initially empty

# 2. Assign a distance to all vertices in the input graph. Initialize all distance values as INF. Assign 0 to the source vertex so it's picked first

# 3. While SPTSet doesn't include all vertices
#    a. Pick a vertex u which is not there in sptSet and has minimum distance value
#    b. include u to sptSet
#    c. Update distance value of all adjacent vertices of u. To do this, iterate through all adjacent vertices. For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v is less than the distance value of v, then update the distance value of v

inf = float('inf')

class Graph():
  def __init__(self, vertices):
    self.V = vertices
    self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

  def print_solution(self, dist):
    print("Vertex \tDistance from Source")
    for node in range(self.V):
      print(str(node) + "\t" + str(dist[node]))

  # Finds vertex with min distance value
  # from the set of vertices not yet included
  # in the shortest path tree
  def min_distance(self, dist, sptSet):
    minim = float('inf')

    for v in range(self.V):
      if dist[v] < minim and not sptSet[v]:
        minim = dist[v]
        min_index = v
    
    return min_index

  def dijkstra(self, src):
    dist = [float('inf')] * self.V
    dist[src] = 0
    sptSet = [False] * self.V

    for cout in range(self.V):
      u = self.min_distance(dist, sptSet)
      sptSet[u] = True
      for v in range(self.V):
        if self.graph[u][v] > 0 and \
            not sptSet[v] and \
            dist[v] > dist[u] + self.graph[u][v]:
          dist[v] = dist[u] + self.graph[u][v]
    self.print_solution(dist)

g = Graph(9)
g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0], 
        [4, 0, 8, 0, 0, 0, 0, 11, 0], 
        [0, 8, 0, 7, 0, 4, 0, 0, 2], 
        [0, 0, 7, 0, 9, 14, 0, 0, 0], 
        [0, 0, 0, 9, 0, 10, 0, 0, 0], 
        [0, 0, 4, 14, 10, 0, 2, 0, 0], 
        [0, 0, 0, 0, 0, 2, 0, 1, 6], 
        [8, 11, 0, 0, 0, 0, 1, 0, 7], 
        [0, 0, 2, 0, 0, 0, 6, 7, 0] 
        ]; 

g.dijkstra(0);

