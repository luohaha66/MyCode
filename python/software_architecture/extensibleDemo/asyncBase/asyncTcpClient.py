import asyncio


# streams
async def tcp_echo_client(message, ip, port):
    reader, writer = await asyncio.open_connection(ip, port)
    print(f'Send: {message!r}')
    writer.write(message.encode())
    await writer.drain()

    data = await reader.read(100)
    print(f'Received: {data.decode()!r}')

    print('Close the connection')
    writer.close()
    await writer.wait_closed()


async def main():
    await asyncio.gather(tcp_echo_client('Hello\n', '127.0.0.1', 8888),
                         tcp_echo_client('Hello World!\n', '127.0.0.1', 8888))


if __name__ == '__main__':
    asyncio.run(main())
