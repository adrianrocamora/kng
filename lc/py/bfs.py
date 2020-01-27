def search(root):
  queue = []
  root.visited = true;
  visit(root)
  queue.append(root)

  while(len(queue) > 0):
    # Remove from the front of the queue
    r = queue.pop(0) 
    for n in r.adjacent:
      if not n.visited:
        visit(n)
        n.visited = True
        queue.append(n)



