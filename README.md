# Redis-Inspired In-Memory Key-Value Store

A Redis-inspired in-memory key-value store built in **C++**. The project implements a TCP server that accepts Redis-like commands, stores data in memory using a hash table, and supports persistence by saving and loading data from disk.

## Features

- TCP server using Winsock
- In-memory key-value storage (`unordered_map`)
- Redis-like commands:
  - `SET`
  - `GET`
  - `DEL`
  - `EXISTS`
  - `SAVE`
  - `LOAD`
- Command parsing
- Modular architecture with separated networking, parsing, storage, and persistence layers

## Project Structure

```
redis-inspired-kv-store/
├── include/
├── src/
├── data/
├── tests/
├── CMakeLists.txt
└── README.md
```

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Run

```bash
./redis_clone
```

On Windows:

```powershell
.\redis_clone.exe
```

The server starts on **localhost:6379**.

## Connect

Using Telnet:

```bash
telnet localhost 6379
```

Or using Netcat:

```bash
ncat localhost 6379
```

## Example

```
SET name Prashant
OK

GET name
Prashant

EXISTS name
1

DEL name
1

SAVE
OK

LOAD
OK
```

## Tech Stack

- C++
- CMake
- Winsock (Windows Sockets API)
- STL (`unordered_map`, `vector`, `fstream`, `sstream`)

