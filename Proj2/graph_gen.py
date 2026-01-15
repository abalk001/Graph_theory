import networkx as nx 
import matplotlib.pyplot as plt 


def read_adj_matrix(filename):
    matrix = []
    with open(filename, 'r') as f:
        for line in f:
            row = [int(x) for x in line.strip().split(',') if x != '']
            matrix.append(row)
    return matrix 



def build_graph(matrix):
    G = nx.Graph()
    n = len(matrix)
    G.add_nodes_from(range(n))
    for i in range(n):
        for j in range(i+1, n):
            if matrix[i][j] != 0:
                G.add_edge(i, j)
    return G 



def draw_graph(G):
    """Draw graph with node size proportional to degree."""
    degrees = dict(G.degree())
    node_sizes = [degrees[n]*100 for n in G.nodes()]
    pos = nx.spring_layout(G, seed=42)
    nx.draw(G, pos, with_labels=True, node_size=node_sizes, node_color='skyblue', edge_color='gray')
    plt.title("Graph Visualization from Adjacency Matrix")
    plt.savefig("graph.png")
    plt.show()

if __name__ == "__main__":
    filename = "adj_matrix.txt"
    matrix = read_adj_matrix(filename)
    G = build_graph(matrix)
    draw_graph(G)
