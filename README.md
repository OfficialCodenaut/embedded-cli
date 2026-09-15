# Embedded CLI

[![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus\&logoColor=white)](https://isocpp.org/)
[![GCC](https://img.shields.io/badge/GCC-MinGW-2E8B57?logo=gnu\&logoColor=white)](https://gcc.gnu.org/)
[![GitHub last commit](https://img.shields.io/github/last-commit/OfficialCodenaut/embedded-cli)](https://github.com/OfficialCodenaut/embedded-cli)
[![GitHub repo size](https://img.shields.io/github/repo-size/OfficialCodenaut/embedded-cli)](https://github.com/OfficialCodenaut/embedded-cli)

A C++ embedded system simulator with an interactive command-line interface.

Embedded CLI simulates basic hardware peripherals such as GPIO, ADC and UART, providing a simple interface for interacting with them through a terminal.

The project is developed as a practical exploration of **C++, hardware abstraction, command parsing and embedded-system concepts**.

## Overview

The project models an embedded system as a collection of independent hardware modules controlled through a command-line interface.

Current architecture:

```text
EmbeddedSystem
├── GPIO
├── ADC
└── UART
     ▲
     │
     CLI
```

`EmbeddedSystem` acts as the main container for the simulated hardware peripherals, while the CLI provides the interface used to interact with them.

## Features

### GPIO

* 30 simulated GPIO pins
* `INPUT` / `OUTPUT` pin modes
* `LOW` / `HIGH` pin states
* Pin read operations
* Pin write operations
* Input/output validation

### ADC

* 8 simulated ADC channels
* 10-bit resolution
* Value range: `0–1023`
* Channel read operations
* Channel value configuration
* Input validation

### UART

* UART initialization
* Configurable baud rate
* `UNINITIALIZED` / `READY` states
* UART status reporting
* Message transmission

### CLI

* Interactive terminal interface
* Token-based command parsing
* Module-specific subcommands
* Argument validation
* Error handling
* Module-specific help

## CLI Usage

Start the simulator and interact with the system using commands such as:

```text
embedded> gpio mode 13 output
GPIO13 = OUTPUT

embedded> gpio write 13 high
GPIO13 = HIGH

embedded> gpio read 13
GPIO13 = HIGH

embedded> adc set 4 512

embedded> adc read 4
ADC4 = 512

embedded> uart begin 9600

embedded> uart status
UART = READY

embedded> uart send Hello world
UART TX: Hello world
```

### Available Commands

| Module | Command                     | Description             |
| ------ | --------------------------- | ----------------------- |
| GPIO   | `gpio mode <pin> <mode>`    | Configure GPIO pin mode |
| GPIO   | `gpio write <pin> <state>`  | Set GPIO pin state      |
| GPIO   | `gpio read <pin>`           | Read GPIO pin state     |
| GPIO   | `gpio help`                 | Display GPIO commands   |
| ADC    | `adc set <channel> <value>` | Set ADC channel value   |
| ADC    | `adc read <channel>`        | Read ADC channel value  |
| ADC    | `adc help`                  | Display ADC commands    |
| UART   | `uart begin <baudrate>`     | Initialize UART         |
| UART   | `uart send <message>`       | Transmit a message      |
| UART   | `uart status`               | Display UART status     |
| UART   | `uart help`                 | Display UART commands   |
| Global | `help`                      | Display global commands |
| Global | `exit`                      | Exit the CLI            |

## Project Structure

```text
embedded-cli/
├── .gitignore
├── README.md
└── src/
    ├── ADC.cpp
    ├── ADC.hpp
    ├── EmbeddedSystem.cpp
    ├── EmbeddedSystem.hpp
    ├── GPIO.cpp
    ├── GPIO.hpp
    ├── UART.cpp
    ├── UART.hpp
    └── main.cpp
```

### Source Responsibilities

| File               | Responsibility              |
| ------------------ | --------------------------- |
| `GPIO.*`           | GPIO hardware simulation    |
| `ADC.*`            | ADC hardware simulation     |
| `UART.*`           | UART hardware simulation    |
| `EmbeddedSystem.*` | Hardware module aggregation |
| `main.cpp`         | CLI and command processing  |

## Building

The project currently uses **GCC / MinGW**.

Compile the project with:

```bash
g++ src/main.cpp src/GPIO.cpp src/ADC.cpp src/UART.cpp src/EmbeddedSystem.cpp -o src/embedded.exe
```

Run:

```bash
./src/embedded.exe
```

On Windows:

```powershell
.\src\embedded.exe
```

The generated executable is excluded from version control through `.gitignore`.

## Development

The project is developed incrementally, with individual hardware modules and CLI functionality implemented and tested separately.

The main goals are:

* Practice modern C++ fundamentals
* Learn hardware abstraction concepts
* Build modular C++ code
* Understand command-line parsing
* Experiment with embedded-system architecture
* Gradually introduce more advanced system concepts

## Roadmap

### Planned

* Diagnostics system
* Sensors
* Configuration system
* Additional embedded peripherals
* Improved command parser
* More robust CLI validation
* Embedded scripting language

### Future Direction

The long-term goal is to evolve the simulator into a small programmable embedded environment rather than simply a collection of simulated peripherals.

A possible future scripting interface could allow users to write programs such as:

```text
program thermostat

    gpio 13 output
    gpio 13 high

    let temp = sensor temperature

    if temp > 25
        gpio 13 high
    else
        gpio 13 low
    end

end
```

This would eventually require a dedicated lexer, parser, AST and interpreter.

## Project Status

**Work in progress.**

Embedded CLI is primarily a learning and portfolio project. Features are added incrementally as the architecture evolves.

## License

License information will be added once the project license is formally defined.
