class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        wordict = {}
        res = [] 
        for i in range(len(words)):
            wordict[words[i]] = i
            
        for i in range(len(words)):
            w = words[i]
            l = len(w)
            # case 1: If word is "" then (i,j) and (j,i) is pal
            if w == "":
                for j in range(len(words)):
                    if i!=j and words[j] == words[j][::-1]:
                        res.append([i,j])
                        res.append([j,i])
                continue
                
            # case 2: if rev(word) in list then (i,j) is pal
            rev_w = w[::-1]
            if rev_w in wordict and i != wordict[rev_w]:
                res.append([i,wordict[rev_w]])
            
            # case 3 :
            for k in range(1,l):
            # case 3_1: If (0..k-1 is pal) and (rev(k..n) is in list) then (word_i_in_list,i) make pal
                # if w[k:][::-1] in wordict and w[:k] == w[:k][::-1]:
                #     res.append([wordict[w[k:][::-1]],i])
                if rev_w[:l-k] in wordict and w[:k] == rev_w[l-k:]:  # prefix == suffix_of_rev
                    res.append([wordict[rev_w[:l-k]],i])
                    
            # case 3_2: If (k..n is pal) and (rev(0..k-1) is in list) then (i,word_i_in_list) make pal
                # if w[:k][::-1] in wordict and w[k:] == w[k:][::-1]:
                #     res.append([i,wordict[w[:k][::-1]]])
                if rev_w[l-k:] in wordict and w[k:] == rev_w[:l-k]:
                    res.append([i,wordict[rev_w[l-k:]]])

        return res