
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

def encryption(text,sessionKey):
    enctext=""
    for i in range len(text):
        enctext= (ord(text[i])+sessionKey)
    