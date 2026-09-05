class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        l = 0
        al = 0
        while l < len(word):
            if al >= len(abbr):
                return False
            if word[l] == abbr[al]:
                l+=1
                al +=1
            elif abbr[al].isdigit():
                if abbr[al] == '0':
                    return False
                tmp = al
                while al < len(abbr) and abbr[al].isdigit():    # no leading 0
                    al +=1
                l+=int(abbr[tmp : al])
            else:
                return False
        return len(abbr) == al and l == len(word)