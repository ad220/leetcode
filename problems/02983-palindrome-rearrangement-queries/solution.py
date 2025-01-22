class Solution:

    def canMakePalindromeQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        queries_result = []
        alphabet ="abcdefghijklmnopqrstuvwxyz"
        queries_result_dict = {}

        for query in queries:
            if queries_result_dict.get(tuple(query))!=None:
                queries_result += [queries_result_dict.get(tuple(query))]
                continue

            foundInOldQueries = None
            for old_query in queries_result_dict.keys():
                if old_query[0]>=query[0] and old_query[1]<= query[1] and old_query[2]>=query[2] and old_query[3]<= query[3]:
                    if queries_result_dict.get(old_query):
                        foundInOldQueries = True
                        break
                elif old_query[0]<=query[0] and old_query[1]>= query[1] and old_query[2]<=query[2] and old_query[3]>= query[3]:
                    if not queries_result_dict.get(old_query):
                        foundInOldQueries = False
                        break
            if foundInOldQueries!=None:
                queries_result += [foundInOldQueries]
                continue
                

            result = True
            freq_left = [s[query[0]:query[1]+1].count(char) for char in alphabet]
            freq_right = [s[query[2]:query[3]+1].count(char) for char in alphabet]

            strSize = len(s)
            for x in range(strSize//2):
                y = strSize-1-x
                if not self.isInRange(x, query[:2]) and not self.isInRange(y, query[2:]) and s[x]!=s[y]:
                    result = False
                    break
                elif not self.isInRange(x, query[:2]) and self.isInRange(y, query[2:]):
                    freq_right[ord(s[x])-ord('a')]-=1
                elif self.isInRange(x, query[:2]) and not self.isInRange(y, query[2:]):
                    freq_left[ord(s[y])-ord('a')]-=1
            
            for freq in freq_left+freq_right:
                if freq<0: result=False

            queries_result += [result and freq_left==freq_right]
            queries_result_dict[tuple(query)] = result and freq_left==freq_right
        
        return queries_result


    def isInRange(self, x: int, range: List[int]) -> bool:
        return x>=range[0] and x<=range[1]

        
        