import socket
from diffei_hellman import generateKey
from diffei_hellman import computeSession


def server_program():
    
    host = socket.gethostname()
    port = 5000  

    server_socket = socket.socket()  
    
    server_socket.bind((host, port))  

   
    server_socket.listen(2)
    conn, address = server_socket.accept()  
    print("Connection from: " + str(address))

    data = conn.recv(1024).decode()
    q=int(input("Enter prime number:"))
    alpha= int(input("Enter alpha:"))
    privateKey=int(input("Enter your private key:"))
    publicKey=generateKey(q,alpha,privateKey) 
    publicKey=str(publicKey)
    conn.send(publicKey.encode())
          
    while True:
        
        data = conn.recv(1024).decode()
        if not data:
            
            break
        print("from connected user: " + str(data))
        #data = input(' -> ')
       
        
             

        
        
        data=input('>') 
        conn.send(data.encode())


    conn.close()  
if __name__ == '__main__':
    server_program()