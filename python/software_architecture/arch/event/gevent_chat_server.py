# Code Listing #9

"""

Multi chat server using gevent

"""

# gevent_chat_server.py


import gevent
from gevent import monkey
from gevent import socket
from gevent.server import StreamServer

monkey.patch_all()

participants = set()


def new_chat_channel(conn, address):
    """ New chat channel for a given connection """

    participants.add(conn)
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
        try:
            data = conn.recv(1024)
        except ConnectionResetError:
            break

    participants.remove(conn)
    for p in participants:
        p.send(bytearray(f'(User {user} leave)\n', 'utf-8'))
    print(f"Participant {user} left chat.")


if __name__ == "__main__":
    port = 3490
    try:
        print(f"ChatServer starting up on port {port}")
        server = StreamServer(('0.0.0.0', port), new_chat_channel)
        server.serve_forever()
    except (KeyboardInterrupt, SystemExit):
        print("ChatServer exiting.")
