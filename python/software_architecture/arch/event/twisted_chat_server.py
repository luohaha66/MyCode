# Code Listing #6

"""

Multiuser chat server using Twisted

"""

# twisted_chat_server.py

from twisted.internet import protocol, reactor


class Chat(protocol.Protocol):
    """ Chat protocol """

    transports = {}
    peers = {}

    def connectionMade(self):
        self._peer = self.transport.getPeer()
        print(f'Connected {self._peer}')

    def connectionLost(self, reason):
        self._peer = self.transport.getPeer()
        # Find out and inform other clients
        user = self.peers.get((self._peer.host, self._peer.port))
        if user is not None:
            self.broadcast(f'\n(User {user} disconnected)\n', user)
            print(f'User {user} disconnected from {self._peer}')

    def byte_to_str(self, string):
        return str(string, encoding='utf-8')

    def str_to_byte(self, string):
        return bytes(string, encoding='utf-8')

    def broadcast(self, msg, user):
        """ Broadcast chat message to all connected users except 'user' """

        for key in self.transports.keys():
            if key != user:
                if msg != "<handshake>" and msg != '\n':
                    self.transports[key].write(self.str_to_byte(f'\n#[{user}]>>> {msg}'))
                else:
                    # Inform other clients of connection
                    self.transports[key].write(self.str_to_byte(f'\n(User {user} connected from {self._peer})\n'))

    def dataReceived(self, data):
        """ Callback when data is ready to be read from the socket """

        data = self.byte_to_str(data)
        user, msg = data.split(":")
        self.transports[user] = self.transport
        # Make an entry in the peers dictionary
        self.peers[(self._peer.host, self._peer.port)] = user
        self.broadcast(msg, user)


class ChatFactory(protocol.Factory):
    """ Chat protocol factory """

    def buildProtocol(self, addr):
        return Chat()


if __name__ == "__main__":
    reactor.listenTCP(3490, ChatFactory())
    reactor.run()
