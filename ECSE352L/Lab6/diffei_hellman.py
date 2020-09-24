
#Function to calculate keys

def generateKey(q,alpha,privateKey):
    if(privateKey>q):
        print("choose the right private key. Not meeting the criteria")
    else:
        a=pow(alpha,privateKey)
        pk1= a%q
        
    
        
    return pk1
#q=int(input("Enter prime number:"))
#alpha= int(input("Enter alpha:"))
#privateKey=int(input("Enter your private key:"))
#publicKey=generateKey(q,alpha,privateKey)
#print("your public key is:",publicKey)


# Function to calculate Session Key

def computeSession(pk,q,prk):
    
    session= (pk**prk)%q
    return session
#print(computeSession(10,q,3))


#Function to encrypt the text

def encryption(text,sessionKey):
    enctext=""
    for i in range (0,len(text)):
        enctext+= chr((ord(text[i])+sessionKey)%26 +65)
    return enctext
#print(encryption("HELLO",20))

#Function to decrypt the text

def decryption(cipheredText,sessionKey):
    dectext=""
    for i in range (0,len(cipheredText)):
        dectext+=chr((ord(cipheredText[i])-sessionKey)%26+65)
    return dectext
#print(decryption("OLSSV",20))