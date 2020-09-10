import socket  
from vignere import originalText1  
from vignere import originalText2
from vignere import generateKey            
  

def server_program():
    
    host = socket.gethostname()
    port = 5000  

    server_socket = socket.socket()  
    server_socket.bind((host, port))  

    server_socket.listen(2)
    conn, address = server_socket.accept()  
    print("Connection from: " + str(address))
    while True:
        data = conn.recv(1024).decode()
        keyword = input("Enter the Key:")
        keyword = keyword.upper()
        c=generateKey(data,keyword)
        originalText2(data,c)
        if not data:
            break
        print("from connected user: " + str(data))
        data = input(' -> ')
        keyword = input("Enter the Key:")
        keyword = keyword.upper()
        c=generateKey(data,keyword)
        originalText1(data,c)
        conn.send(data.encode()) 

    conn.close()  


if __name__ == '__main__':
    server_program()