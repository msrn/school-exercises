import operator
from collections import OrderedDict
"""
@brief sortedDictionary function
       Takes dictionary as parameter and counts total character count in it.
       Then count percentage of each character and round them to 2 decimal points.
       Lastly sort the dictionary and return it.
@param dictionary
@return dictionary as list
"""
def sortedDictionary(dict):
    totalCharCount = 0
    for value in dict.values():
        totalCharCount += value

    for entry in dict:
        dict[entry] = (dict[entry] * 100) / totalCharCount
        rounded = round(dict[entry],2)
        dict[entry] = rounded
    
    dict = sorted(dict.items(), key=operator.itemgetter(1), reverse=True)
    #dict = OrderedDict(sorted(dict.items()))
    return dict

"""
Main
"""

"""
Read encrypted text and save letters and occurences to a dictionary
"""
with  open('text.txt', 'r') as file:
    encText = file.read()

encDict = {} #Holds encrypted letter and occurences
encText = encText.strip().upper()
encText = encText.encode('iso-8859-1').decode('utf8')

for letter in encText:
    
    if not letter.isspace():
        if not letter in encDict:
            encDict[letter] = 1
        else:
            encDict[letter] += 1

encDict = sortedDictionary(encDict) ##Return sorted dictionary with calculated percentage of letter frequency.

"""
Read finnish monograms and save letters and value to dictionary
"""
with open('finnish_monograms.txt', 'r') as file:
    monograms = file.readlines()

monogramDict = {} #Hold monogram letters and values
for line in monograms:
    key, value = line.split(' ')
    monogramDict[key] = int(value)

monogramDict = sortedDictionary(monogramDict) #Sort dictionary and calculate percentage

#Dictionary with substitute letters. Encrypted letter as key and monogram letter as value. Eg. G : A
subDict = {}

# Iterate lists in paraller and encDict key as key to subDict and monogramDict key as value to subDict
print ('Character Frequency Comparision\nEncrypted - Percentage; Monogram - Percentage')
for (k1, v1), (k2, v2) in zip(encDict, monogramDict):
    subDict[k1] = k2
    print(k1, v1,'% ', k2, v2,'%')


"""
Replace original encrypted string letters with letters attained from frequency analysis.
"""
encTextList = list(encText)

for n, i in enumerate(encTextList):
    if encTextList[n] in subDict:
        encTextList[n] = subDict.get(i)

print("\nText with matched character frequency. Note that this may not be solved")
print("".join(encTextList))

print("\nOriginal Encrypted text")
print(encText)

