# Serial Calculator + Logic Gate Simulator

A tiny command-line interpreter written in C++ that parses a single line of text and evaluates it as either a basic arithmetic expression or a binary logic gate operation. Built as a prototype for a future Arduino Uno port (Serial Monitor input), where the goal is to work within the ATmega328P's tight 2KB RAM budget using only fixed-size `char` arrays — no `std::string`, no dynamic allocation.

## Status

- ✅ Core parsing/evaluation logic implemented and tested as a standalone C++ program (`cin`/`cout`)
- ⏳ Not yet ported to Arduino — current version reads input via `cin.getline()`, which will be replaced with a `Serial.available()` / `Serial.read()` loop on real hardware

## Supported operations

**Calculator (single-digit operands only):**

| Input    | Output |
|----------|--------|
| `3 + 5`  | `8`    |
| `9 - 4`  | `5`    |
| `6 * 7`  | `42`   |
| `7 / 2`  | `3.5`  |
| `5 / 0`  | `x` (invalid) |

**Logic gates (operands must be `0` or `1`):**

| Gate | Example    | Notes           |
|------|------------|-----------------|
| AND  | `AND 1 0`  | → `0`           |
| OR   | `OR 1 0`   | → `1`           |
| XOR  | `XOR 1 0`  | → `1`           |
| NOT  | `NOT 1`    | single operand → `0` |
| NAND | `NAND 1 0` | → `1`           |
| NOR  | `NOR 1 0`  | → `0`           |
| XNOR | `XNOR 1 0` | → `0`           |

Any malformed, misspelled, or out-of-spec input prints `x`.

## How mode detection works

Rather than scanning for a specific keyword first, the program locates the **first space character** in the input buffer. Its position alone narrows down which command shape is possible:

| First space at index | Candidate mode(s)         | Required total length (`stop`) |
|-----------------------|----------------------------|----------------------------------|
| 1                     | Calculator (`N op N`)      | 5                                |
| 2                     | `OR`                       | 6                                |
| 3                     | `NOT`, or `AND`/`XOR`/`NOR` | 5 (NOT) / 7 (others)            |
| 4                     | `NAND`, `XNOR`             | 8                                |

The exact operator/operand characters are only checked *after* this narrowing, and the total input length (tracked via a `stop` index found by scanning for `'\0'`/`'\n'`) must also match exactly — this catches malformed inputs like `"XY 1 0"` that would otherwise coincidentally match a valid shape by first-space position alone.

## Known limitations (by design, for this version)

- Calculator operands are single digits only (`3 + 5` works, `12 + 5` does not)
- Logic gate operands must be exactly `0` or `1`
- Operator keywords must be uppercase (`AND`, not `and`)
- Fixed buffer size (9 bytes) — matches the longest valid command (`NAND 1 0` / `XNOR 1 0`) plus a null terminator; input longer than this will not parse correctly
- No operator precedence or multi-operator expressions (`3 + 5 * 2` is not supported)

## Building and running (current desktop version)

```bash
g++ -o calc main.cpp
./calc
```

Type a single command and press Enter, e.g.:

```
AND 1 0
```

## Roadmap

- [x] Port input handling to Arduino Serial (`Serial.available()` / `Serial.read()` loop, byte-by-byte buffer fill, no `String` class)
- [x] Confirm behavior against real 2KB RAM budget on ATmega328P
- [ ] Consider extending calculator to multi-digit operands (requires dynamic-length parsing instead of fixed character positions)