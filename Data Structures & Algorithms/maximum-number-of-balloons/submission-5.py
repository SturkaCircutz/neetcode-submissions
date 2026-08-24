class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        text = Counter(text)
        real = Counter('balloon')
        res = 0
        sizem = text['b']
        for i in 'balon':
            sizem = min(text[i] // real[i], sizem)
        return sizem