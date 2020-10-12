from pprint import pprint 
def findMinArrowShots(points):
  # For simplicity we'll just shoot through each integer point from min_x to max_y
  # We'll create a hashmap of which balloons were popped at each integer x
  # At the end we'll try to find the smallest collection
  min_x = points[0][0]
  max_x = points[0][1]

  for idx, point in enumerate(points):
    min_x = point[0] if point[0] < min_x else min_x
    max_x = point[1] if point[1] > max_x else max_x

  popped_at_x = dict()

  for x in range(min_x, max_x + 1):
    popped_at_x[x] = []
    for idx, point in enumerate(points):
      if point[0] <= x <= point[1]:
        popped_at_x[x].append(point)
  pprint(popped_at_x)
  print()
          
p1 = [[10,16],[2,8],[1,6],[7,12]] # 2
p2 = [[1,2],[3,4],[5,6],[7,8]] # 4
p3 = [[1,2],[2,3],[3,4],[4,5]] # 2
p4 = [[1,2]] # 1
p5 = [[2,3],[2,3]] # 1

findMinArrowShots(p1)
findMinArrowShots(p2)
findMinArrowShots(p3)
findMinArrowShots(p4)
findMinArrowShots(p5)
