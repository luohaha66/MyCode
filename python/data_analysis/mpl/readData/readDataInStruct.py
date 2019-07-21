
import struct

if __name__ == '__main__':
    mask = '3s5s6s7s'
    with open('struct.data', 'rb') as f:
        for line in f:
            fields = struct.unpack_from(mask, line)
            print([field.strip() for field in fields])
