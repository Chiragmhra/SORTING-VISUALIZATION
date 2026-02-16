import socket
import threading
from cryptography.fernet import Fernet

key = Fernet.generate_key()
cipher = Fernet(key)

print("\n🔐 Multi-User Secure Chat Server Started")
print("Share this key with all clients:\n")
print(key.decode(), "\n")

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("localhost", 9999))
server.listen()
  
clients = []
names = []

def broadcast(message):
    for client in clients:
        client.send(message)

def handle_client(client):
    while True:
        try:
            msg = client.recv(1024)
            broadcast(msg)
        except:
            index = clients.index(client)
            name = names[index]
            print(f"{name} disconnected")

            clients.remove(client)
            client.close()
            names.remove(name)
            break

def receive():
    while True:
        client, addr = server.accept()
        print(f"Connected with {addr}")

        client.send("NAME".encode())
        name = client.recv(1024).decode()
        names.append(name)
        clients.append(client)

        print(f"Name: {name}")
        broadcast(cipher.encrypt(f"{name} joined the chat!".encode()))
        client.send(cipher.encrypt("Connected to Secure Server!".encode()))

        thread = threading.Thread(target=handle_client, args=(client,))
        thread.start()

receive()
