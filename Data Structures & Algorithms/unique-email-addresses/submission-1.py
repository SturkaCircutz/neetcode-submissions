class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        res = set()
        for e in emails:
            local, domain = e.split('@')
            local = local.replace('.', '')
            local = local.split('+')[0]
            res.add(local+domain)
            print(local+domain)
        return len(res)