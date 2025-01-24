/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char* safeNodes;

bool isSafeNode(int** graph, int graphSize, int* graphColSize, int node, bool* parentCall) {
    if (parentCall[node]) return false;

    if (safeNodes[node]&1) return safeNodes[node]==3;

    bool result = true;
    parentCall[node]=true;
    // bool* newParentCall;
    for (int j=0; j<graphColSize[node]; j++) {
        // newParentCall = calloc(graphSize, sizeof(bool));
        // for (int i=0; i<graphSize; i++) newParentCall[i] = parentCall[i];
        result = result && isSafeNode(graph, graphSize, graphColSize, graph[node][j], parentCall);
        // free(newParentCall);
    }
    parentCall[node] = false;

    safeNodes[node] = result ? 3 : 1;
    return result;
}

int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    returnSize[0]=0;
    safeNodes = calloc(graphSize, sizeof(char));

    bool* parentCall;
    for (int i=0; i<graphSize; i++) {
        parentCall = calloc(graphSize, sizeof(bool));
        if (isSafeNode(graph, graphSize, graphColSize, i, parentCall)) returnSize[0]++;
        free(parentCall);
    }

    printf("%d", returnSize[0]);

    int j=0;
    int k=0;
    int* result = malloc(returnSize[0]*sizeof(int));
    while (j<returnSize[0]) {
        if(safeNodes[k]==3) result[j++] = k;
        k++;
    }
    return result;
}