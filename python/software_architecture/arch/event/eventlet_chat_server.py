# Code Listing #8

"""

Multiuser chat server using eventlet

"""

import eventlet
from eventlet.green import socket

participants = set()


def new_chat_channel(conn):
    """ New chat channel for a given connection """

    data = conn.recv(1024)
    user = ''

    while data:
        for p in participants:
            try:
                if p is not conn:
                    data = data.decode('utf-8')
                    user, msg = data.split(':')
                    if msg != '<handshake>':
                        data_s = f'\n#[{user}]>>> says {msg}'
                    else:
                        data_s = f'(User {user} connected)\n'

                    p.send(bytearray(data_s, 'utf-8'))
            except socket.error as e:
                # ignore broken pipes, they just mean the participant
                # closed its connection already
                if e[0] != 32:
                    raise
        data = conn.recv(1024)

    participants.remove(conn)
    for p in participants:
        p.send(bytearray(f'(User {user} leave)\n', 'utf-8'))
    print(f"Participant {user} left chat.")


if __name__ == "__main__":
    port = 3490
    try:
        print(f"ChatServer starting up on port {port}")
        server = eventlet.listen(('0.0.0.0', port))

        while True:
            new_connection, address = server.accept()
            print(f"Participant {address} joined chat.")
            participants.add(new_connection)
            eventlet.spawn(new_chat_channel, new_connection)

    except (KeyboardInterrupt, SystemExit):
        print("ChatServer exiting.")
