import asyncio
import random
import numpy as np
import matplotlib.pyplot as plt

plt.axis([50, 400, 0, 100])

class Server:
    def connection_made(self, transport):
        self.transport = transport

    def datagram_received(self, data, addr):
        message = data.decode()
        x, y, z = message.split(",")
        print(f"white rabbit @ {x},{y},{z}")
        plt.scatter(float(x), float(z))
        plt.pause(0.05)
        self.transport.sendto(data, addr) # it's not expecting an answer but w/e


loop = asyncio.get_event_loop()
listen = loop.create_datagram_endpoint(
    Server,
    local_addr=("127.0.0.1", 12000))
transport, protocol = loop.run_until_complete(listen)

try:
    loop.run_forever()
except KeyboardInterrupt:
    pass

transport.close()
loop.close()