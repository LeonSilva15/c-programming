# C Programming
This is a repository intended to cover all the fundamentals of C Programming based in a MSC in Computer Science program.

## Easy compile and run using docker
We can use a docker container to compile and run our programs without installing any other software in our system.

1. Pull the official GCC image from [Docker Hub](https://hub.docker.com/_/gcc).
```bash
docker pull gcc
```
2. Rename the image (optional)
```bash
docker tag gcc:latest dev/c:gcc
```
3. Create the container and bind your directory
```bash
docker run -d -it --name gcc -v `pwd`:/usr/src -w /usr/src dev/c:gcc
```
4. Access the container using a bash terminal
```bash
docker exec -it gcc bash
```
5. Compile your program
```bash
gcc -o your_program your_program.c
```
- We can add an extension to identify any compiled program (optional)
```bash
gcc -o your_program.out your_program.c
```
6. Run your compiled program
```bash
./your_program
```
- or
```bash
./your_program.out
```

You can find more on compiling and running in the [GCC official website](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html).

## Simplify compilation and running
We can create a function to ease the compilation and running with just one alias
1. Create alias
```bash
alias run='f(){ gcc -o compiled.out "$@".c && ./compiled.out; unset -f f; }; f'
```
2. Run alias
```bash
run your_program
```
This will compile your_program.c and output in an executable named compiled.out, then executes it.
