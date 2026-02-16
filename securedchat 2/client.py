import socket
import threading 
from cryptography.fernet import Fernet

key = input("Enter shared secret key: ").encode()
cipher = Fernet(key)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("localhost", 9999))

name = input("Enter your name: ")

def receive():
    while True:
        try:
            msg = client.recv(1024)

            if msg.decode() == "NAME":
                client.send(name.encode())
            else:
                decrypted = cipher.decrypt(msg).decode()
                print(decrypted)
        except:
            print("Error! Disconnected from server.")
            client.close()
            break

def write():
    while True:
        message = f"{name}: {input('')}"
        encrypted = cipher.encrypt(message.encode())
        client.send(encrypted)

receive_thread = threading.Thread(target=receive)
receive_thread.start()

write_thread = threading.Thread(target=write)
write_thread.start()
