def search(root):
    if not root:
      return
    visit(root)
    root.visited = True
    for n in root.adjacent:
      if not n.visited:
        search(n)
