# C Sockets demo program
This project shows the communication between the server and client through websockets, running a small interactive program.

## Simple project deployment using docker
Based on the general README.md, we can now create a network and attach our containers to it for the communication.

1. Create the server container and bind your directory
```bash
docker run -d -p 5001:5001 -it --name cServer -v `pwd`:/usr/src -w /usr/src dev/c:gcc
```

2. Create the client container and bind your directory
```bash
docker run -d -p 5002:5002 -it --name cClient -v `pwd`:/usr/src -w /usr/src dev/c:gcc
```

3. Create the network
```bash
docker network create cNetwork
```

4. Attach the server to the network
```bash
docker network connect cNetwork cServer
```

5. Attach the client to the network
```bash
docker network connect cNetwork cClient
```

### Run the programs
Run the server and the client based on the instructions from the main README.md.

This sockets project was built in collaboration with Emilio Gonzalez Gonzalez
