s=str(input('Sentence :'))

words = s.split(" ")

snew= " ".join(words[::-1])

print(snew)

newWords = [word[::-1] for word in words]

snew1=" ".join(newWords)

print(snew1)
