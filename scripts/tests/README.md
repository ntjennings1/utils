# Test Suite

A penetration test suite built for TC operatives.

## Software Requirements

## Actions


## Usage

This section will cover how to use the test suite.

### Flags

Flags are parameters used by the test suite to operate.

This flag switches the suite to GUI mode:
```
* --gui
```

These flags allow the CLI to perform the actions.
```
* --out
* --url
* --ip4addr
* --ip6addr
* --hostname
* --port
* --username
* --password
* --info
* --login
* --dictionary
* --pingdeath
* --len
* --size
```

### CLI

The command line interface relies on users setting flag variables. 

```
python src\main.py -h
```

```
python src\main.py -u
```

### GUI

The graphical user interface guides users.

```
python src\main.py --g
```

## Acknowledgements

    Noah Jennings 
        TC 
        ntjennings1@gmail.com
        Virginia Beach, VA
        
    TC 
        th3orycc@gmail.com
        Virginia Beach, VA