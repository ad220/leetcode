
class Solution:
    graph_length = []
    convex_subgraphs = []
    node_in_loop = []
    search_depth = 0
    found_loop = False

    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        reversed_favorite = [[] for _ in range(n)]
        self.graph_length = [-1] * n
        self.node_in_loop = [False] * n
        for i in range(n):
            reversed_favorite[favorite[i]].append(i)

    def computeGraphLength(self, fav_graph, start_node):
        if self.graph_length[start_node] > -1:
            return self.graph_length[start_node]
        
        if not fav_graph[start_node]: return 1

        if not self.node_in_loop[start_node]:
            self.node_in_loop[start_node] = True
            self.search_depth += 1
            result = []
            for node in fav_graph[start_node]:
                result.append(self.computeGraphLength(fav_graph, node))
                if self.found_loop:
                    self.convex_subgraphs.append([self.search_depth, max(result)])
                    return self.search_depth

            self.search_depth -= 1
            return max(result + 1)
            if self.node
            return 
        
        else:
            self.found_loop = True
            return self.search_depth

            


        [2,2,1,2]
        [[], [2], [0,1,3], []]




