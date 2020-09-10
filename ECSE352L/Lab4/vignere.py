def generateKey(string, key): 
    key = list(key) 
    if len(string) == len(key): 
        return(key) 
    else: 
        for i in range(len(string) - 
                       len(key)): 
            key.append(key[i % len(key)]) 
    return key 
      
def originalText1(cipher_text, key):
 
  orig_text = [] 
  for i in range(len(cipher_text)): 
    x = (ord(cipher_text[i]) - ord(key[i]) + 26) % 26
    x += ord('A') 
    orig_text.append(chr(x)) 
  return orig_text
  

def originalText2(plain_text, key):
  
  ciph_text = [] 
  for i in range(len(plain_text)):
      y = (ord(plain_text[i]) + ord(key[i])) % 26
      y += ord('A')
      ciph_text.append(chr(y))
  return ciph_text
     
    
      
 
#string = input("Enter a string:")
#string = string.upper()
#keyword = input("Enter the Key:")
#keyword = keyword.upper()
#c=generateKey(string,keyword)
#a=originalText1(string,c)
#print(a)

#b=originalText2(a,c)
#print(b)
