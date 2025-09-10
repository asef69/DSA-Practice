class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        langs=[set(x) for x in languages]
        usersToTeach=set()
        for u,v in friendships:
            if langs[u-1].isdisjoint(langs[v-1]):
                usersToTeach.add(u-1)
                usersToTeach.add(v-1)
        if not usersToTeach:
            return 0
        ans=float('inf')
        for lang in range(1,n+1):
            count=0
            for i in usersToTeach:
                if lang not in langs[i]:
                    count+=1
            ans=min(ans,count)
        return ans                        
