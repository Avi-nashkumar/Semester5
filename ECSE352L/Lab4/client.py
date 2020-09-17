import socket  
from vignere import originalText2  
from vignere import originalText1
from vignere import generateKey   
        
  
def client_program():
    host = socket.gethostname()  
    port = 5000  

    client_socket = socket.socket()  
    client_socket.connect((host, port))  

    message = input(" -> ")  
    keyword = input("Enter the Key:")
    keyword = keyword.upper()
    c=generateKey(message,keyword)
    originalText1(message,c)

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())  
        data = client_socket.recv(1024).decode() 
        keyword = input("Enter the Key:")
        keyword = keyword.upper()
        c=generateKey(data,keyword)
        originalText2(data,c)
         

        print('Received from server: ' + data)  

        message = input(" -> ")  
        


    client_socket.close()  


if __name__ == '__main__':
    client_program()