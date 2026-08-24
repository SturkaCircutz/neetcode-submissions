class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        collect = set()
        for email in emails:
            res = ''
            mark = True
            ignore = False
            for c in email:
                if c == '.' and mark:
                    continue
                elif c == '@':
                    mark = False
                elif c == '+':
                    ignore = True
                elif mark and ignore:
                    continue
                else:
                    res+=c
            print(res)
            collect.add(res)
        return len(collect)
        