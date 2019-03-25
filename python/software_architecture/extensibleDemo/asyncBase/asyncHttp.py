import asyncio
import urllib.parse


async def print_http_headers(url):
    url = urllib.parse.urlsplit(url)
    if url.scheme == 'https':
        reader, writer = await asyncio.open_connection(
            url.hostname, 443, ssl=True)
    else:
        reader, writer = await asyncio.open_connection(
            url.hostname, 80)

    query = (
        f"HEAD {url.path or '/'} HTTP/1.0\r\n"
        f"Host: {url.hostname}\r\n"
        f"\r\n"
    )

    writer.write(query.encode('latin-1'))
    while True:
        line = await reader.readline()
        if not line:
            break
        line = line.decode('latin1').rstrip()
        if line:
            print(f'HTTP header> {line}')
        # Ignore the body, close the socket
    writer.close()


async def main():
    await asyncio.gather(
        print_http_headers('https://www.baidu.com/?tn=62095104_7_oem_dg'),
        print_http_headers('https://www.csdn.net/'),
        print_http_headers('https://www.cnblogs.com/'),
        print_http_headers('https://github.com/')
    )


if __name__ == '__main__':
    asyncio.run(main())
