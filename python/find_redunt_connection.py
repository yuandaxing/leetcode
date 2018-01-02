#!/bin/python
def findRedundantConnection(edges):
    tree = ''.join(map(chr, range(100)))
    for u, v in edges:
        if tree[u] == tree[v]:
            return [u, v]
        tree = tree.replace(tree[u], tree[v])
print findRedundantConnection([[1,2], [1,3], [2,3]])
