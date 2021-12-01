class Node(object):
    def __init__(self, val, parent):
        self.value = val
        self.parent = parent
        self.children = []

forest = {}

n, m = list(map(int, input().split()))
s, e = list(map(int, input().split()))

for i in range(m):
    p, c = list(map(int, input().split()))
    try:
        p_node = forest[p]
        p_node.children.append(c)
    except:
        new_node = Node(p,[])
        forest[p] = new_node
        new_node.children.append(c)

    try:
        c_node = forest[c]
        c_node.parent.append(p)
    except:
        new_node = Node(c,[p])
        forest[c] = new_node

def get_subgraph(forest, start, end):
    start_set = set([start])
    end_set = set([end])

    t = True
    r = True
    new_pars = start_set.copy()
    e_pars = set(forest[end].parent)
    while t:
        init_set = start_set.copy()
        for i in new_pars:
            start_set.update(forest[i].children)
        new_pars = start_set-init_set
        if (len(new_pars) == 0):
            t = False
            if end not in start_set:
                r = False
    
    if not r:
        return 0
    
    t = True
    new_pars = end_set.copy()
    while t:
        init_set = end_set.copy()
        for i in new_pars:
            if i != start:
                end_set.update(forest[i].parent)
        new_pars = end_set-init_set

        if (len(new_pars) == 0):
            t = False
    
    return end_set & start_set

sub_graph_nodes = get_subgraph(forest, s,e)
routes_dict = {}
for n in sub_graph_nodes:
    node = forest[n]
    try:
        routes_dict[len(set(node.parent)&sub_graph_nodes)*len(set(node.children)&sub_graph_nodes)].append(node.value)
    except:
        routes_dict[len(set(node.parent)&sub_graph_nodes)*len(set(node.children)&sub_graph_nodes)] = [node.value]

print(routes_dict[max(routes_dict.keys())][0])
